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

public:
  /*!
  * Controller is public so that the user can control the
  * the signal rate
  */
  PID controller;


  /*!
  * @brief Default Constructor
  * @brief β=0.01, ν=0.1, and δ=0.05
  * @brief vBase = 300,40
  * @brief p1-6 : 0.05, 0.5, 0.0001, 0.00001, 150, 0.05
  * @brief state : 400,0,200
  * @brief desiredGlucose 100
  * @brief default Kvalues 5.5,0.005,0.25
  * @brief h=0.15
  * @post creates IG object with default values
  */
  IG();


  /*!
  * @brief creates IG object with given paramater
  * @param[in] input_desire desiredGlucose to go towards
  * @param[in] step_size how much to simulate in timesteps
  * @param[in] v_inputP p constants for the ODE
  * @param[in] v_inputRates initial Rates added (this is overwritten anyway)
  * @param[in] v_inputBase Base Glucose and Insulin Concentrations
  * @param[in] v_inputState Initial state of the model (G,X,I) in this order
  * @param[in] v_Kinput constants to change the magnitude of PID variables
  * @pre step_size>0, for step function () to work
  * @pre constants to be used in equations should be reasonable,
  * @pre but keep in mind that some should be positive
  * @pre (v_inputP,v_inputBase,v_inputState,v_inputKInput)
  * @post creates an Insulin/Glucose simulation
  */
  IG(double input_desire, double step_size, const vector<double>& v_inputP,
    const vector<double>& v_inputRates, const vector<double>& v_inputBase,
    const vector<double>& v_inputState, const vector<double> v_Kinput);

  /*! 
  * @brief copy constructor
  * @param[in] otherIG to be copied from
  * @post copies contents from otherIG to this
  */

  IG(const IG& otherIG);

  /*!
  * @brief steps default h
  * @post steps controller by h, updates Rates
  * @post steps Euler object with default step (h)
  */

  void operator()();

  /*!
  * @brief steps given input_step
  * @param[in] input_step non zero step positive number
  * @post steps controller by input_step, updates Rates
  * @post steps Euler object with input_step given
  */
  void operator()(double input_step);

  /*!
  * @brief outputs state vector values of Obj
  * @param[in] os ostream object
  * @param[in] Obj IG object to print values from
  * @post prints values in form
    Glucose: <G>, Insulin: <I>
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
