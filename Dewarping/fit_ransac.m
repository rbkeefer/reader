% General-purpose RANSAC routine.
%
% [m, k, risk] = fit_ransac(data, sample_size, max_samples, max_risk, threshold, fitter, evaluator, ...)
%
% Input:
%            data: ? x n array, each column being a data point.
%     sample_size: minimal sample size for model.
%     max_samples: maximum number of samples to draw (can be +inf).
%        max_risk: acceptable failure risk level.
%       threshold: inlier threshold.
%          fitter: fitting function; syntax is m = fitter(x, ...).
%       evaluator: evaluation function; syntax is d = evaluator(m, x, ...).
%             ...: extra arguments to fitting and evaluation functions.
%
% Output:
%     m: fitted model.
%     k: indices of inliers.
%  risk: probability that we did not find a basis of inliers.
%
function [m, k, risk] = fit_ransac(data, sample_size, max_samples, max_risk, threshold, fitter, evaluator, varargin)
  n = size(data, 2);
  if n < sample_size
    error('too few points')
  end
  
  % here we store the best results obtained.
  best_m = [];
  best_k = [];
  
  % estimated inlier ratio.
  ratio = 0;
  
  for num_samples=1:max_samples
    % pick subset (the 'basis') of points at random.
    k = randsample(n, sample_size); % array of indices.
    
    % fit model to those points.
    m = feval(fitter, data(:, k), varargin{:});
    
    % evaluate model on all data.
    d = feval(evaluator, m, data, varargin{:});
    
    % find indices of data points within threshold.
    k = find(d <= threshold);
    
    % ------------------------------
    
    if numel(k) > numel(best_k)
      % it is better.
      best_m = m;
      best_k = k;
      ratio = numel(k) / n;
      better = 1;
    else
      % is is not better.
      better = 0;
    end
    
    % estimate the probability that we did
    % not yet find a basis of inliers.
    if ratio == 1
      risk = 0;
    else
      risk = (1 - ratio^sample_size)^num_samples;
    end
    
    %if better
      %fprintf(1, '%s: sample %4d found support %6d / %6d; risk = %e\n', ...
      %        mfilename, num_samples, ...
      %        numel(best_k), n, risk);
    %end
    
    if risk <= max_risk
      %fprintf(1, '%s: sample %4d last; support %6d / %6d; risk = %e\n', ...
      %        mfilename, num_samples, ...
      %        numel(best_k), n, risk);
     break
    end
  end
  
  m = best_m;
  k = best_k;
end
