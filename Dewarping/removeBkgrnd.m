
% Function to remove background from an image on the assumption that the
% input image contains a simple background and the image largely contains
% text-page.
% 
% function im2 = removeBkgrnd(im)
%
%           im: inputImage
%          im2: outputImage - background pixels are given a value 1.
%

function im2 = removeBkgrnd(im)

% figure, imshow (im)
% Use global thresholding to obtain an estimate of the text-image
BW           = im2bw      (im, graythresh(im) * 0.75);

% Remove objects/areas of less size. Text image should obviously be a
% larger object
[L nr]       = bwlabel    (~BW);
stats        = regionprops(L, 'Area');
Idx          = find       ([stats.Area] > 500);
BW           = ismember   (L, Idx);
BW           = imdilate   (BW, strel('disk', 6));
[L nr]       = bwlabel    (~BW);
figure, imagesc(L)

% Assign the background pixels a value of 1.
stats        = regionprops(L, 'Area');
[I Idx]      = max        (cat(1, stats.Area));
[c r]        = find       (L == Idx);
im(L ~= Idx) = 1;

% Crop the background, if possible
im2          = imcrop     (im, [min(r) min(c) max(r)-min(r) max(c)-min(c)]);
% figure, imshow (im2);


