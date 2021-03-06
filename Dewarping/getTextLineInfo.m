%
% Function to obtain base lines for text present in the image
% 
% function [T lines XX J stats] = getTextLineInfo(BW)
%
%           BW: input binary image
%
%            T: Bounding boxes for each character in the image
%        lines: Characters present in each line in the iamge
%           XX: # of characters in each line
%            J: index of the characters in the image
%        stats: statistics of each character in the image
%


function [T lines XX J stats] = getTextLineInfo(BW)

[L nr]         = bwlabel    (BW);
stats          = regionprops(L, 'Area');  

Area           = cat        (1, stats.Area);
Idx            = find       (Area >= 30);
BW             = ismember   (L, Idx);
[L nr]         = bwlabel    (BW);
stats          = regionprops(L, 'Perimeter', 'Area', 'PixelList', 'Image', 'BoundingBox', 'Extrema'); 
T              = cat        (1, stats.BoundingBox);

% Compute the left & right bottom points of the rectangles
% -- WRONG.....Compute the centers of the borders
leftCenter     = [T(:, 1)          T(:, 2) + T(:, 4) / 2];
rightCenter    = [T(:, 1) + T(:,3) T(:, 2) + T(:, 4) / 2];

% Define the boundary rectangles for each rightCenter
width          = ones(length(rightCenter), 1) .* 100;
SearchRect     = [rightCenter(:, 1)-5 rightCenter(:, 2)-10 width width];
IntersectArea  = rectint(SearchRect, T) > 0;
%figure, imagesc( IntersectArea, 'r.')

nextPointDist  = ones(1, nr) * 1000;
nextPoint      = ones(1, nr) * inf;

for ii = 1 : nr     
    Index     = find(IntersectArea(ii, :));
    Index     = setdiff(Index, ii);
   
   if( ~isempty(Index))   
       rightPoint             = rightCenter(ii, :);
       leftPoints             = leftCenter (Index, :)';       
       distPoint              = euclidean       (rightPoint, leftPoints);
       [nextPointDist(ii) kk] = min        (distPoint);
       nextPoint(ii)          = Index      (kk);      
   
       % Remove cyclic next-points...for example colon (:)
       if abs(rightCenter(ii, 1) - rightCenter(Index(kk), 1)) < 5,
           distPoint(kk)          = 1000;
           [nextPointDist(ii) kk] = min  (distPoint);
           nextPoint(ii)          = Index(kk);
       end
   end
end
PointDist  = nextPointDist < 25;

% Remember to use XY-Ordering, the way the lines are ordered in text...So,
% sort according to that.
% Array 'lines' holds the characters in each line
% Assumption - Each line contains a max. of 100 characters
%              Each page contains a maximum of 500 lines

[I J]      = sort (leftCenter(:, 1));
flag       = ones (nr,  1);
lines      = zeros(500, 100);      
line       = zeros(1,   100);
lineCount  = 1;
J          = J';
for temp = 1:length(J)
    % If next point, add that point to this line
    lineChar = 1;
    nextChar = temp;
    
    if(flag(nextChar))
        line(lineChar) = nextChar;
        flag(nextChar) = 0;
        
        while(PointDist(nextChar))
            nextChar       = nextPoint(nextChar);
            if(~flag(nextChar)), break; end
            flag(nextChar) = 0;
            lineChar       = lineChar + 1;
            line(lineChar) = nextChar;
        end

        lines(lineCount, 1 : lineChar) = line(1:lineChar);
        lineCount = lineCount + 1;
    end
end

% Remove lines containing single characters, if their size is less than a
% pre-defined size....removes noise...
% May also remove dots. (sentence endings)
lines(lineCount : end, :) = [];
temp                  = find(sum(lines > 0, 2) == 1);
Area                  = cat (1, stats.Perimeter);
temp2                 = find(Area(lines(temp, 1)) < 30);
oneCharLines          = lines(temp(temp2), 1);
lines(temp(temp2), :) = [];
lineCount             = lineCount - length(temp2) - 1;

% Now, sort according to y's
[I J]                 = sort(leftCenter(lines(:, 1), 2));
XX                    = sum (lines > 0, 2);

figure, imagesc(BW), colormap gray, hold on
for ii = J'   
    Index = lines(ii, 1 : XX(ii));
    for jj = Index
       rectangle('Position', [T(jj, 1 ), T(jj, 2), T(jj, 3), T(jj, 4)], 'EdgeColor', 'r', 'LineWidth', 1)
    end
    %pause
end

figure, imagesc(BW), colormap gray, hold on
for jj = oneCharLines'
   rectangle('Position', [T(jj, 1 ), T(jj, 2), T(jj, 3), T(jj, 4)], 'EdgeColor', 'r', 'LineWidth', 1)
end
