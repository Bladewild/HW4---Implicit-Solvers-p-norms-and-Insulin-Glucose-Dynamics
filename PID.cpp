/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: IG.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of PID
*/

#include "PID.h"

/*
PID::PID(std::function <double(double)> f_error, std::function <double(double)> f_PID,
  vector<double> input_K, double input_PE, double input_stepSize) :
  calculateError(f_error), PIDfunction(f_PID),
  K(input_K), previousError(input_PE), h(input_stepSize)  
{
  cout << "Input\n";
}
*/

/*
function evaluation operator () that “steps” the controller, 
calculating the control signal (in our case, insulin level) 
given an input signal (in our case, glucose concentration output from the model)
*/


vector<double> PID::operator()()
{

  return (*this)(h);
}

vector<double> PID::operator()(double input_step)
{
  double error = calculateError();
  double iError = trapezoidalIntegral(0, input_step, input_step * 50.0, error);
  double dError = previousError - error;
  double u = PIDfunction(K, error, iError, dError);
  vector<double> new_U(2);
  new_U[0] = (u > 0) ? u : 0;
  new_U[1] = (u < 0) ? -u : 0;
  return new_U;
}


PID& PID::operator = (const PID& source)
{
  if (this != &source)
  {
    calculateError = source.calculateError;
    PIDfunction = source.PIDfunction;
    K = source.K;
    previousError = source.previousError;
    h = source.h;
  }

  return *this;
}

const double PID::operator[](const int index_var) const
{
  double toReturn = K[index_var];
  return toReturn;
}

double& PID::operator[](const int index_var)
{
  return K[index_var];
}