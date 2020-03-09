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
 * A PID library.
 */
#ifndef PID_H
#define PID_H


#include <iostream>
#include <string>
#include <functional>
#include "vector.h"
#include "global.h"

using std::string;
using std::cout;
using std::endl;
using std::function;


/*
* Class: PID
*/
class PID
{
private:
  //pid
  //in our case, the difference between the desired and actual blood glucose levels)
  function <double(void)> calculateError;
  function <double(vector<double>, double, double, double)> PIDfunction;/* =
    [*this](double error)
  {
    double error = calculateError();
    double P = K[0] * error;
    double I = K[1] *
      (trapezoidalIntegral(time, timestep, integralsteps,error);
    double D = K[2] * //derivative here

    return toReturn;
  };*/
  vector<double> K;
  double previousError;
  double h;


public:
  /*!
  * @brief uses default c++ implementation
  * @brief useful for initializing and assign later.
  */
  PID() = default;

  /*!
  * @brief constructor
  * @param[in] 
  * @param[in] 
  * @param[in] 
  * @post 
  */
  PID(const std::function <double(void)> f_error, const std::function <double(vector<double>, double, double, double)> f_PID,
    const vector<double>& input_K, double input_PE, double input_stepSize) :
    calculateError(f_error), PIDfunction(f_PID), K(input_K), previousError(input_PE), h(input_stepSize)
  {};


  /*!
  * @brief copy constructor
  * @param[in] otherEuler
  * @post copies Euler content to this object to be constructed
  */
  PID(const PID& otherPID):
    calculateError(otherPID.calculateError), PIDfunction(otherPID.PIDfunction),
    K(otherPID.K), previousError(otherPID.previousError),
    h(otherPID.h)
  {}


  /*!
  * @brief  returns value of element at position
  * @param[in]  index_var index position to access
  * @pre index_var must be bounded,non negative

  * @post returns value to element at given index_var
  * @throw range_error if out of bounds (vector class)
  * @throw range_error vector is empty (vector class)

  */


  /*!
  * @brief  returns value of element at position
  * @param[in]  index_var index position to access
  * @pre index_var must be bounded,non negative

  * @post returns value to element at given index_var
  * @throw range_error if out of bounds (vector class)
  * @throw range_error vector is empty (vector class)
  */

  double& operator [] (const int index_var);

  /*
  * @brief calls ()(double_input) with var h as step size
  * @post steps by default h and updates function
  * @post y is updated to y+1 with ODE
  */

  vector<double> operator()();

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */

  vector<double> operator()(double input_step);

  /*!
  * @brief assignment operator
  * @param[in] source PID object
  * @post copies source's content to *this
  */
  PID & operator = (const PID& source);


};


#endif
