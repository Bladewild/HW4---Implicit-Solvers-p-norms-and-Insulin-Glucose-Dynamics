/*
* Author: Marky Santos-Tankia
* File: main.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : Clayton Price
*
* IG file
*/

/*! \file
 *
 * A IG emulation library.
 */
#ifndef IG_H
#define IG_H


#include <iostream>
#include <functional>
#include "vector.h"
#include "Euler.h"
#include "PID.h"
#include <algorithm>    // std::max

using std::cout;
using std::function;
using std::ostream;


/*
* Class: IG
*  Emulates a Insulin/Glucose Model uses Euler object to
*  simulate the states. Encapsulates Euler as each step is taken
*  Can output results with <<. Updates with () operator
*/
class IG
{
private:

  double desiredGlucose;
  double h;
  vector<double> p;
  vector<double> vRates;
  vector<double> vBase;
  vector<double> state;
  Euler<vector<double>> IGeuler;
  PID controller;

public:


  /*!
  * @brief Default Constructor
  * @brief β=0.01, ν=0.1, and δ=0.05
  * @brief h=0.1 
  * @brief vector {S=99,I=1,R=0.0,D=0.0}
  * @post creates IG object with default values
  */
  IG();


  /*!
  * @brief creates IG object with given paramater
  * @param[in] 

  * @pre init_population,init_infected, step_size
  * @pre should all be positive integers
  * @pre init_population > init_infected
  * @pre all should be non zeros
  * @post creates IG object with specified values
  * @note v_input values should be reasonable but left up to user
  */
  IG(double input_desire, double step_size, const vector<double>& v_inputP,
    const vector<double>& v_inputRates, const vector<double>& v_inputBase,
    const vector<double>& v_inputState, const vector<double> k_input);

  /*! 
  * @brief copy constructor
  * @param[in] otherIG to be copied from
  * @pre ---------------------------------------------------------
  * @post copies contents from otherIG to this
  */

  IG(const IG& otherIG);

  /*!
  * @brief steps default h
  * @post steps Euler object with default step (h)
  */

  void operator()();

  /*!
  * @brief steps given input_step
  * @param[in] input_non zero step positive number
  * @post steps Euler object with input_step given
  */
  void operator()(double input_step);

  /*!
  * @brief outputes state vector values of Obj
  * @param[in] os ostream object
  * @param[in] Obj IG object to print values from
  * @post prints values in form
 Susceptible: <S>, Infected: <I>, Recovered: <R>, Deceased: <D>
  */

  friend ostream& operator << (ostream& os, const IG& Obj);

  /*!
  * @brief copies source contents to this object
  * @param[in] source IG reference
  * @post copies contents of IG to this if not same
  */

  IG& operator = (const IG& source);
    
};


#endif
