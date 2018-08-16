
%
% Function to unwarp the curl in the text-image
% 
% function TransformImage = docUnWarp(T, lines, XX, J, stats, BW)
%
%           BW: input binary image
%            T: Bounding boxes for each character in the image
%        lines: Characters present in each line in the iamge
%           XX: # of characters in each line
%            J: index of the characters in the image
%        stats: statistics of each character in the image
%
% TranformImage: Final transformed image after unwarping curl
%

function TransformImage = docUnWarp(T, lines, XX, J, stats, BW)

% Compute the left & right centers of the borders
leftCenter  = [T(:, 1)          T(:, 2) + T(:, 4) / 2];
rightCenter = [T(:, 1) + T(:,3) T(:, 2) + T(:, 4) / 2];

% Compute the left & right centers of the borders
leftPt      = [T(:, 1) T(:, 2) + T(:, 4)];
rightPt     = [T(:, 1) + T(:,3) T(:, 2) + T(:, 4)];
botCenter   = (leftPt + rightPt) / 2.0;

% Do not use the entire line to do this.  Instead get the words and then
% use these words to fit the base lines.  This way, we obtain a more robust
% estimation of the character rotations.

% First collect the words in each line
word        = cell(size(lines, 1), 1);
linewords   = [];
for ii = J'
    % Consider each line
    Index        = lines(ii, 1 : XX(ii));    
    rightPoint   = rightCenter(Index, 1);
    leftPoint    = leftCenter (Index, 1);
    leftPoint(end+1) = 0;
    leftPoint(1) = [];
    dist1        = leftPoint - rightPoint;    
    wordCount    = 1;   
    temp         = [];  count = 0; E = Index(end);

    for jj    = Index
        temp  = [temp jj];
        count = count + 1;
        if((dist1(count) > 5 && length(temp) > 2) || (jj == E))
            word{ii, wordCount} = temp;
            temp      = [];
            wordCount = wordCount + 1;
        end
    end
    linewords(ii) = wordCount;   
end


% Now obtain the base angles for each character in the image

lineDist(1 : length(stats)) = 0;
%figure(7), clf, imagesc( BW ), colormap gray, hold on 
a = 0; b = 0; c = 0; k = 0;
for ii = J'
    line2     = 0;
    lineAngle = 0;
    wordCount = linewords(ii)-1;
    jj        = 0;
    
    while jj < wordCount,
        jj   = jj + 1;
        temp = word{ii, jj};
        
        if(length(temp) < 5 && jj ~= wordCount)
            temp = [temp  word{ii, jj+1}];
            jj   = jj + 1;
        end
        
        if(length(temp) >= 2)
            x       = botCenter(temp, 1);
            y       = botCenter(temp, 2);
            a1      = a; b1 = b; c1 = c; k1 = k;
            [a b c] = fit_line_ransac(x, y, 0.93);
%            xx      = [min(x) max(x)];
%            yy      = -(a*xx + c) / b;
%            plot(xx, yy, 'r-', 'LineWidth', 2)
            
            line2            = line2 + 1;
            lineAngle(line2) = atan     (-a/b );
            lineHist (temp ) = lineAngle(line2);
            if(line2 > 1 && abs(lineAngle(line2) - lineAngle(line2 - 1)) > 0.175)
                a = a1; b = b1; c = c1;
                lineHist(temp) = lineAngle(line2 - 1);
            end
            for kk  = temp
                TT  = stats(kk).PixelList;                 
                if a == 0,
                    if length(find(TT(:,2) + c > 0)) > stats(kk).Area * 0.1,
                        tipPt        = stats(kk).Extrema;
                        lineDist(kk) = tipPt(5,2) + c;
                    end
                else
                    TT3 = (a * TT(:, 1) + b * TT(:, 2) + c) / sqrt(a*a + b*b);
                    if length(find(TT3 < 0)) > stats(kk).Area * 0.1,
                        tipPt        = stats(kk).Extrema;
                        lineDist(kk) = (a * tipPt(5, 1) + b * tipPt(5, 2) + c) / sqrt(a*a + b*b);
                    end
                end                
            end
        else
            lineDist(temp) = 0;
            lineHist(temp) = 0;
        end
    end
end

temp   = find(abs(lineDist) >= 4 );
%for kk = temp
%    rectangle('Position', [T(kk, 1 ), T(kk, 2), T(kk, 3), T(kk, 4)], 'EdgeColor', 'g')
%end


% Start writing out each line to a new file after doing the unwarp
TransformImage = zeros(size(BW));
lineHist1      = lineHist .* 180 / pi;
lineDist       = floor(abs(lineDist));
for ii = J'
    Index  = lines(ii, 1 : XX(ii));      
    StartX = ceil(leftCenter(Index(1), 1));
    StartY = ceil(leftCenter(Index(1), 2));  
           
    for jj = 1 : length(Index)
        kk1 = Index(jj);
        im1 = stats(kk1).Image;              
        im1 = imrotate(im1, lineHist1(kk1), 'bicubic', 'crop');
        [height width] = size(im1);
                                     
        % Need to treat characters like p, g, q, y separately
        if lineDist(kk1) > 4, 
            YIndex = linspace(StartY-height + 1 + lineDist(kk1), StartY + lineDist(kk1), height);
        else            
            YIndex = linspace(StartY-height+1, StartY, height);
        end
        XIndex = StartX : StartX + width - 1;
        TransformImage(YIndex, XIndex) = im1;
       
        % The following spacing is important to separate words.
        if( jj ~= length(Index))
            kk2      = Index(jj + 1);
            diffDist = -rightCenter(kk1, 1) + leftCenter(kk2, 1);
            if diffDist < 0, diffDist = 0; end
            StartX   = StartX + width + diffDist;
        end
    end
end
