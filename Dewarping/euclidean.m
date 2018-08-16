function [y] = euclidean(x,cb)

% This algorithm computes the Euclidean distance between a column
% vector x and a collection of column vectors in the codebook matrix cb. 

  for index=1:size(cb,2)
    y(:,index) = norm(x'-cb(:,index));    
  end

end

