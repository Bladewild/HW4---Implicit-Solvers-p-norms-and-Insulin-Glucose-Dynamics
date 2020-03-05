

#include <iostream>

/*!
* @brief  calculate p-norm
* @pre arr must have no null elements
* @pre
* @post returns a (double) scalar of p-norm calculated
*/


double customPow(const double input_element, const int input_pow)
{
  if (input_pow < 0)
  {
    throw std::invalid_argument("use nthRoot instead");
  }
  double result = 0;
  if (input_pow == 0)
  {
    result = 1;
  }
  else
  {
    result = input_element;
    for (int i = 1; i < input_pow; i++)
    {
      result *= input_element;
    }
  }
  return result;
}


/*!
* @brief  calculates nth root
* @pre
* @pre
* @post returns double scalar of given arguements
*/

double nthRoot(double value, int N)
{
  // intially guessing a random number between 
  // 0 and 9 
  double xPre = rand() % 10;

  //  smaller eps, denotes more accuracy 
  double eps = 1e-3;

  // initializing difference between two 
  // roots by INT_MAX 
  double delX = 2147483647;

  //  xK denotes current value of x 
  double xK;

  //  loop untill we reach desired accuracy 
  while (delX > eps)
  {
    //  calculating current value from previous 
    // value by newton's method 
    xK = ((N - 1.0) * xPre +
      (double)value / customPow(xPre, N - 1)) / (double)N;
    delX = abs(xK - xPre);
    xPre = xK;
  }

  return xK;
}