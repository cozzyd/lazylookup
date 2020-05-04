#include "lazylookup.hh" 
#include <cmath> 
#include <stdlib.h> 


double frobnicate(int x)
{
  double sum = 1;
  for (int i = 0; i < 100000000; i++) 
  {
    sum += sin(sum*x); 
  }
  return sum; 
}

double ufrobnicate(std::size_t x)
{
  return frobnicate(x); 
}


double gridfn(const std::array<double,2> & X) 
{
  return X[0] *X[1]; 
}

int main(int nargs, char ** args)
{

  lazylookup::dict<int,double> test_dict(frobnicate); 
  lazylookup::vec<double> test_vec(ufrobnicate);

  lazylookup::grid_interpolator<2> test_grid(gridfn, {100,100},{0,0},{10,10}); 

  for (int i = 0; i < 100; i++) 
  {
    int input = (i%10);
    printf("dict: %g %d\n", test_dict[input], test_dict.get_n_filled()); 
    printf("vec: %g %d\n", test_vec[input], test_vec.get_n_filled()); 

    std::array<double,2> grid_input = { sqrt(i), sqrt(i) }; 
    printf("grid: %g %g\n", gridfn(grid_input), test_grid[grid_input]); 
  }

  //test_grid.dump(); 

  return 0; 

}


