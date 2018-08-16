
function padIM = paddingDown( im1, x )

  [M, N, P] = size ( im1 );  
  M1        = floor( M / x );
  N1        = floor( N / x );
  
  padIM     = zeros( M1, N1, P );
  II        = 1 : M1;
  JJ        = 1 : N1;
  
  padIM     = im1( II*x-1, JJ*x-1, : );
  
  