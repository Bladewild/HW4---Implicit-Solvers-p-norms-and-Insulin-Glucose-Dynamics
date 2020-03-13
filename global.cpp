

#include <iostream>

#include "global.h"

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


double nthRoot(double value, int N)
{

  if (N < 0)
  {
    throw std::invalid_argument("use customPow instead");
  }
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


/*
double trapezoidalIntegral(double a, double b, int n, double error)
{
  const double width = (b - a) / n;

  double trapezoidal_integral = 0;
  for (int step = 0; step < n; step++)
  {
    const double x1 = a + step * width;
    const double x2 = a + (step + 1) * width;

    trapezoidal_integral += 0.5 * (x2 - x1) * (error + error);
  }
  return trapezoidal_integral;
}*/