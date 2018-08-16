

clear all
close all

% Downscaling factor used for speed up, not used always
ScalingFac = 4;
MySize = 41;
TRatio = 1.8;  % When using imageMeanBinarize, set TRatio to 1 for average
fileToProcess = 'CloseUp1';

% Input image filename
%filename   = 'inputImages/t1_1.jpg';   
filename   = strcat('inputImages/', fileToProcess, '.jpg');    

% Get the image color data and the corresponding grayscale data
imcolor    = imread  (filename);
imgray     = rgb2gray(imcolor);

%imgray1 = imread(filename);

%%%%%% Added only to do Otsu Binarization before background removal
iml        = imageMeanBinarize(double(imgray),   MySize, MySize, TRatio);
imwrite(~iml, 'outputImages/binarized.jpg', 'jpg');
%%%%%%

% Remove the background
imgray1    = removeBkgrnd(imgray);
 figure, imshow(imcolor), title('Original Image')
 figure, imshow(imgray1), title('Background Subtracted Image')


% Get the individual pages
%[leftIm rightIm] = getBookHalfs(imgray1, ScalingFac);
% figure, imshow(leftIm),  title('left Page')
% figure, imshow(rightIm), title('Right Page')
leftIm = imgray1;

clear imcolor imgray


% -------------------------------------------------------------------------
% Now processing individual pages...Shown here for left page
% -------------------------------------------------------------------------


% First, obtain the binary image
iml        = imageBinarize(double(leftIm),   MySize, MySize, TRatio);
%iml        = imageBinarize(double(leftIm),   11, 11, 1.8);
 figure, imshow(iml), title('Binarized Left Page')
%imwrite(~iml, strcat('outputImages/', fileToProcess, '.enhanced.jpg'), 'jpg');
    


% Get individual text characters and the corresponding base lines
[T lines XX] = getTextLineInfo(iml);


% Perspective transformations - Obtain the vanishing points and the rotation matrix
H            = getRotationMat(T, lines, XX, iml);
tform        = maketform     ('projective', pinv(H));
B2           = imtransform   (iml, tform, 'bicubic', 'Size', size(iml), 'fill', 0);
% Beware, of the coordinate system...Make the necessary transformations
B2           = fliplr(flipud(B2));
figure, imshow(B2), title('After Removing Perspective Distortions')
imwrite(~B2, strcat('outputImages/', fileToProcess, '.perspective.jpg'), 'jpg');


% Now unwarp the text page-curl
[T lines XX J stats] = getTextLineInfo(B2);
TransformImageL      = docUnWarp(T, lines, XX, J, stats, B2);
figure, imshow(TransformImageL), title('After Removing Page Curl')

% Write the final output to a file
imwrite(~TransformImageL, strcat('outputImages/', fileToProcess, '.dewarped.jpg'), 'jpg');
