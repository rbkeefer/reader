% Use RANSAC to fit a line with equation
%   a x + b y + c = 0
% to some 2D points.
%
% Syntax: [a, b, c, k] = fit_line_ransac(x, y, threshold)
%
%  x, y: coordinates of 2D points.
%  threshold: inlier threshold.
%
%  a, b, c: coefficients of line.
%  k: indices of inlier points.
function [a, b, c, k] = fit_line_ransac(x, y, threshold)
  if ~isequal(size(x), size(y))
    error('x and y must have the same shape')
  end
  
  % stack arrays into n x 2 matrix.
  n = numel(x);
  data = [reshape(x, [1 n])
          reshape(y, [1 n])];
  
  sample_size = 2;
  max_samples = 10000;
  max_risk = 1e-6;
  fit_model = @fitter;
  eval_model = @evaluator;
  
  [m, k] = fit_ransac(data, sample_size, max_samples, max_risk, threshold, fit_model, eval_model);
  
  if 0
    a = m(1);
    b = m(2);
    c = m(3);
  else
    % re-fit using all inliers.
    [a, b, c] = fit_line(x(k), y(k));
  end
end

function m = fitter(data)
  [a, b, c] = fit_line(data(1, :), data(2, :));
  
  m = [a
       b
       c];
end

function d = evaluator(m, data)
  a = m(1);
  b = m(2);
  c = m(3);
  
  x = data(1, :);
  y = data(2, :);
  
  d = abs(a*x + b*y + c) / sqrt(a^2 + b^2);
end
