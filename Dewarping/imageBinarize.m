%
% Function to binarize an input-TEXT image.  Effectively takes into
% consideration the illumination variations and shadows by applying a local
% mean subtraction...a form of RETINEX.
% 
% function [BW rectImage] = imageBinarize(im, m, n, tRatio)
%
%           im: inputImage
%         m, n: m * n neighborhood pixels
%       tRatio: % of threshold value for global thresholding
%
%           BW: output binary image
%    rectImage: output mean subtracted image
%

function [BW rectImage] = imageBinarize(im, m, n, tRatio)

% mean subtract the image
h         = ones(m, n) ./ (m * n);
meanImage = imfilter( im, h );
rectImage = im ./ meanImage;

% Apply Otsu's Binarization
threshold = graythresh( rectImage ) .* tRatio;
T         = rectImage < threshold;

% remove too small and too large objects...considered as non-text
% Remember, this may also remove pictures (non-text)
L         = bwlabel(T);
stats     = regionprops(L, 'Area');
Idx       = find([stats.Area] > 10 & [stats.Area] < 1000);
BW        = ismember(L, Idx);
%figure, imshow(BW)

