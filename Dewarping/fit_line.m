% Function fits a line with equation
%   ax + by + c = 0
% to given 2D points.
%
% Syntax: [a, b, c] = fit_line(x, y)
%
% x, y: coordinates of n points in the plane.
%       n must be at least two.
function [a, b, c] = fit_line(x, y)
  if ~isequal(size(x), size(y))
    error('x and y must have the same shape')
  end
  
  % flatten arrays into n x 1 vectors.
  x = x(:);
  y = y(:);
  
  n = numel(x);
  if (n < 2)
    error('too few points')
  end
  
  if (n == 2)
    % much faster method for fitting
    % a line through only two points.
    l = cross([x(1) y(1) 1], [x(2) y(2) 1]);
    l = l / norm(l(1:2));
    a = l(1);
    b = l(2);
    c = l(3);
    return
  end
  
  % find centroid.
  xbar = mean(x);
  ybar = mean(y);
  
  % subtract centroid.
  xrel = x - xbar;
  yrel = y - ybar;
  
  % form the "scatter matrix".
  A = [sum(xrel.*xrel) sum(xrel.*yrel)
       sum(yrel.*xrel) sum(yrel.*yrel)];
  
  % normal to the line is the eigenvector of A
  % corresponding to the smallest eigenvalue.
  % this is V(:, 1) because eig() gives sorted
  % eigenvalues on the diagonal of D.
  %   A: 2x2
  %   V: 2x2
  %   D: 2x2 diagonal.
  [V, D] = eig(A);
%  if ((D(1, 1)<0) || (D(1, 1) > D(2, 2)))
%    error('oiks!')
%  end
  a = V(1, 1);
  b = V(2, 1);
  
  % choose c to make the line go through the centroid.
  c = -(a * xbar + b * ybar);
end
