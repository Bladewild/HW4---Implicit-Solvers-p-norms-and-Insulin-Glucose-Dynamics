
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
  //cout << "y: " << y << std::endl;

  return y ;

}