%
% Function to binarize an input-TEXT image.  Based on Average of image
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

function [BW rectImage] = imageMeanBinarize(im, m, n, tRatio)

% mean subtract the image
h         = ones(m, n) ./ (m * n);
meanImage = imfilter( im, h );
rectImage = im ./ meanImage;

threshold = mean(mean(rectImage));
T         = rectImage < (threshold * tRatio);

% remove too small and too large objects...considered as non-text
% Remember, this may also remove pictures (non-text)
L         = bwlabel(T);
stats     = regionprops(L, 'Area');
Idx       = find([stats.Area] > 10 & [stats.Area] < 1000);
BW        = ismember(L, Idx);
%figure, imshow(BW)


