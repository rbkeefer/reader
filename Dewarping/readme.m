
% Note: This code has been tested on MATLAB version 7.2.0.232 (R2006a)

% list of files present:

%      docReader.m  - Main file to start the Image Document Unwarping
%                     Shows the entire procedure
%                     Run this to see the output at various stages
%
%         readme.m  - The readme file (current)
%   removeBkgrnd.m  - Function to remove background 
%   getBookHalfs.m  - Function to obtain individual text pages
%    paddingDown.m  - Function to scale down the image
%  imageBinarize.m  - Function to binarize the input image
%getTextLineInfo.m  - Function to obtain each character information
%                     Also, obtains the text in each line
% getRotationMat.m  - Function to obtain the rotation matrix for
%                     perspective rectification
%      docUnWarp.m  - Function to unwarp the text curl
%     fit_ransac.m  - RANSAC fitting algorithm
%       fit_line.m  - Function to fit a line
%fit_line_ransac.m  - Function to fit a line using RANSAC
%
%     
%         t1_0.jpg  - Example Input Image
%           OUTPUT  - Folder containing results (OCR outputs)
%  OUTPUT/Input.*   - Input image and the corresponding OCR output    
%  OUTPUT/Final.*   - Output image and the corresponding OCR output
%
