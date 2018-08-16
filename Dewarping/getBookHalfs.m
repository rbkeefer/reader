
% Function to separate book pages from a open text-book.
%
% function [leftHalf rightHalf] = getBookHalfs(imgray, ScalingFac)
%
%           imgray: input grayscale image
%       ScalingFac: downscaling factor to increase speedup
%
%         leftHalf: left text-page
%        rightHalf: right text-page
%

function [leftHalf rightHalf] = getBookHalfs(imgray, ScalingFac)

% Scale down the image for speedUp
% remove small regions in the scaled down image
% The largest object in the image is the text-page
im1        = paddingDown(imgray, ScalingFac);               

% Now find the center of the book and clean the parts
% Not always necessary
width       = size(im1, 2);
height      = size(im1, 1);
centerStart = width/2 - 60;
addFac      = (centerStart-0) * ScalingFac;
centerImage = imcrop(im1, [centerStart, 0, 120, height]);
edgeim2     = edge        (centerImage, 'canny', 0.03, 1.1);
L           = bwlabel     (edgeim2);
stats       = regionprops (L, 'Area');
Idx         = find        ([stats.Area] > 150);
BW          = ismember    (L, Idx);
%figure, imshow(BW)

% Use Ransac fit to find the line
% and obtain the distance of all points in the image from this line
% to decide which pixels belong to which part of the image
[c r]       = find(BW ~= 0);
[a b c]     = fit_line_ransac( r, c, 0.93 );
[r1 c1]     = find(ones(120*ScalingFac, height*ScalingFac));
I           = find((a * r1 + b * c1 + (c - 5) * ScalingFac) <= 0);
I2          = find((a * r1 + b * c1 + (c + 5) * ScalingFac) >= 0);

% Use sub2ind to speedup accessing large matrices
leftHalf       = imcrop(imgray, [0, 0, width/2+60, height] .* ScalingFac);
ind            = sub2ind(size(leftHalf), c1(I), r1(I)+addFac-1);
leftHalf(ind)  = 1; %imgray(1, 1);   % Assuming this contains gray value
% figure, imshow(leftHalf)

rightHalf      = imcrop(imgray, [width/2-60, 0, width/2+60, height] .* ScalingFac);
ind            = sub2ind(size(rightHalf), c1(I2), r1(I2));
rightHalf(ind) = 1; %imgray(1, 1);
% figure, imshow(rightHalf)
