
/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: Euler.hpp Date: 2/28/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of Euler
*/

#include "Euler.h"

template<typename T>
Euler<T>& Euler<T>::operator = (const Euler<T>& source)
{
  if (this != &source)
  {
    ODE = source.ODE;
    y = source.y;
    h = source.h;
  }

  return *this;
}

template<typename T>
T Euler<T>::operator()()
{
  return (*this)(h);
}


template<typename T>
T Euler<T>::operator () (double input_step)
{	
  if (input_step <= 0)
  {
    throw std::invalid_argument("input_step cannot be < 0 or = 0");
  }
  y = y + input_step* ODE(y);

  double specifiedTolerance=0.001;
  double errorTolerance;
  //initial predictor
  T yi = y;
  T ODEyi = ODE(y);
  //initial predictor - use current state
  T y_prev = yi + input_step* ODEyi;
  //initial correcter
  y = yi + ((ODEyi + ODE(y_prev)) * 0.5) * input_step;
  errorTolerance = abs(((y^(2)) - (y_prev^(2))) / (y^(2)));
  //std::cout << "y: " << y << std::endl;
  //std::cout << "y_prev: " << y_prev << std::endl;
  //std::cout << "Error: " << errorTolerance << std::endl;
  //std::cout << "----------------" << std::endl;
  //iterator
  while (specifiedTolerance <= errorTolerance)
  {
    y_prev = y;
    y = yi + ((ODEyi + ODE(y_prev)) * 0.5) * input_step;
    errorTolerance = abs(((y ^ (2)) - (y_prev ^ (2))) / (y ^ (2)));
    //std::cout << "y_prev: " << y_prev << std::endl;
    //std::cout << "y: " << y << std::endl;
    //std::cout << "Error: " << errorTolerance << std::endl;
    //std::cout << "----------------" << std::endl;
  }

  //std::cout << "----------------" << std::endl;
  return y ;

}