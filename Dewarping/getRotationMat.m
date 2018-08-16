
%
% Function to obtain rotation matrix for inverse perspective transformation
% This is obtained by finding horizontal and vertical vanishing points in
% the image.  Use cues present in the image to do this
% RANSAC fit is used to fit horizontal and vertical lines.
% 
% function H = getRotationMat(T, lines, XX, BW)
%
%           BW: input binary image
%            T: Bounding boxes for each character in the image
%        lines: Characters present in each line in the iamge
%           XX: # of characters in each line
%       
%            H: Transformation matrix
%

function H = getRotationMat(T, lines, XX, BW)

% Compute the left & right centers of the borders
leftPt    = [T(:, 1) T(:, 2) + T(:, 4)];
rightPt   = [T(:, 1) + T(:,3) T(:, 2) + T(:, 4)];
botCenter = (leftPt + rightPt) / 2.0;

% For line formation, do not consider all lines.
mCount    = mean(XX);
stdCount  = std (XX)/2; % Not needed, can be 0.
I         = find(XX > mCount -stdCount);
[length(XX) length(I)];

% Get the horizontal lines
% Collect only those that are not close in angle
% the angle difference between all these is > 1 degree
%figure, imagesc(~BW), colormap gray, hold on
count  = 1; 
for ii = I'
    Index   = lines(ii, 1 : XX(ii));
    if(length(Index) > 15),
        Index = Index(3 : end-3);
    end
    x       = botCenter      (Index, 1);
    y       = botCenter      (Index, 2);
    [a b c] = fit_line_ransac(x, y, 0.93);
    aa(count) = a; bb(count) = b; cc(count) = c;
 %   xx         = [min(x) max(x)];
 %   yy         = -(a*xx + c) / b;
 %   plot(xx, yy, 'b-', 'LineWidth', 1);
    count     = count + 1;
end

% Do not consider all the horizontal lines, Instead choose the ones that
% are maximum distance apart...Hopefully to cover the entire
% range....Alternatively one can use a RANSAC fitting....
% Note...The algorithm for RANSAC fitting is already present.

locX = floor(size(BW, 2) / 2);
yy1  = -(aa(1) * locX + cc(1)) / bb(1);
for ii = 1 : count-2
    yy2 = -(aa(ii) * locX + cc(ii)) / bb(ii);
    dist1(ii) = abs(yy2 - yy1);     
end
[II JJ] = max(dist1);

% Now, get the vertical lines...Works for only left/right aligned columns
% If the page contains multi-columns, use each column to fix a vertical
% line

% To decide on multi-columns, a quick hack is to use clustering
if( length(I) > 35 )
    tempfirst = lines      (I', 1);
    Pt        = botCenter  (tempfirst, :);        
    ID        = kmeans     (Pt(:, 1), 2);
    first     = Pt( find(ID == 1), :);
    last      = Pt( find(ID == 2), :);    
    figure, imagesc( BW ), colormap gray, hold on
    plot(first(:, 1), first(:, 2), 'r.');
    plot(last(:  ,1), last(:,  2), 'b.');
    
    [a1 b1 c1] = fit_line_ransac(first(:, 1), first(:, 2), 0.93);    
    xx         = [min(first(:, 1)) max(first(:, 1))];
    yy         = -(a1*xx + c1) / b1;
    plot(xx, yy, 'r-', 'LineWidth', 1);

    [a2 b2 c2] = fit_line_ransac(last(:,  1), last(:,  2), 0.93);
    xx         = [min(last(:, 1)) max(last(:, 1))];
    yy         = -(a2*xx + c2) / b2;
    plot(xx, yy, 'r-', 'LineWidth', 1);
else
    count = 1;
    for ii = I'
        first(count) = lines(ii, 1);
        last (count) = lines(ii, XX(ii));
        count        = count + 1;
    end
    x          = T(first, 1);
    y          = T(first, 2);
    [a1 b1 c1] = fit_line_ransac(x, y, 0.93);
   xx         = [min(x) max(x)];
   yy         = -(a1*xx + c1) / b1;
   plot(xx, yy, 'r-', 'LineWidth', 1)
    
    x          = T(last, 1) + T(last, 3);
    y          = T(last, 2);
    [a2 b2 c2] = fit_line_ransac(x, y, 0.93);
   xx         = [min(x) max(x)];
   yy         = -(a2*xx + c2) / b2;
   plot(xx, yy, 'r-', 'LineWidth', 1)
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Now get the horizontal, vertical VPs, vanishing line
% AND rotation matrix
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
A       = [ aa(1) bb(1); aa(JJ) bb(JJ)];
B       = [-cc(1);      -cc(JJ)];
HVanish = A \ B;

A       = [ a1 b1; a2 b2];
B       = [-c1;   -c2];
VVanish = A \ B;

HV      = [HVanish(1) HVanish(2) 1];
VV      = [VVanish(1) VVanish(2) 1];
if( VV(1) < 0 & HV(1) < 0 & HV(2) > 0)
    VV = -VV;
end
Vz      = cross(HV, VV);
H       = [HV; VV; Vz];
