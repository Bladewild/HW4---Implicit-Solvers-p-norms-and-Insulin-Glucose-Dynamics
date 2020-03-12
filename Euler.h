/*
* Author: Marky Santos-Tankia
* File: main.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : Clayton Price
*
* Euler file
*/
/*! \file
 *
 * A Euler library.
 */
#ifndef EULER_H
#define EULER_H


#include <iostream>
#include <string>
#include <functional>

using std::string;
using std::cout;
using std::function;
using std::endl;


/*
* Class: Euler
*  Wraps a function given,initial state and constants
*  Keeps track state as each step is taken which returns the
*  y+1 value. y+1 becomes the y value and the cycle continues
*/
template<typename T>
class Euler
{
private:
  function <T(T)> ODE;
  T y; //state
  double h; //step size
public:
  /*!
  * @brief uses default c++ implementation
  * @brief useful for initializing and assign later.
  */
  Euler() = default;

  /*!
  * @brief constructor
  * @param[in] callback_f function to apply to y state
  * @param[in] initial_y0 starting state of y
  * @param[in] input_h h step_size
  * @post assigns variables
  */
  Euler(const function<T(T)>& callback_f, const T initial_y0, const double input_h) :
    ODE(callback_f), y(initial_y0), h(input_h) {};

  /*!
  * @brief copy constructor
  * @param[in] otherEuler
  * @post copies Euler content to this object to be constructed
  */
  Euler(const Euler<T>& otherEuler) :
    ODE(otherEuler.ODE), y(otherEuler.y), h(otherEuler.h) {};
  
  /*  
  * @brief calls ()(double_input) with var h as step size
  * @post steps by default h and updates function 
  * @post y is updated to y+1 with ODE
  */

  T operator()();

  /*!
  * @brief predicts y+1 with ODE function
  * @param[in] input_setp
  * @pre input_step is > 0
  * @pre T + T (addition) defined
  * @pre  * T (multiplication) defined
  * @pre T =  (assignment) defined
  * @post y updated with y +ODE(y)
  * @post returns new y of type  T
  * @throw invalid_argument if negative or zero
  */

  T operator()(double input_step);

  /*!
  * @brief assignment operator
  * @param[in] source Euler object
  * @post copies source's content to *this
  */
  Euler<T>& operator = (const Euler<T>& source);



};

#include "Euler.hpp"

#endif
