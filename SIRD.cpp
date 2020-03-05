/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: SIRD.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of SIRD
*/


#include "SIRD.h"

SIRD::SIRD() :
  h(0.1), vRates(vector<double>{0.01, 0.1, 0.05 }),
  state(vector<double>{ 99, 1, 0.0, 0.0}), SIRDeuler()
{
  createODE();

}

SIRD::SIRD(double init_population, double init_infected, double step_size, const vector<double> & v_input) :
  h(step_size), vRates(v_input),
  state(vector<double>{ (init_population - init_infected), init_infected, 0.0, 0.0}), SIRDeuler()
{
  createODE();
}

SIRD::SIRD(const SIRD& otherSIRD) :
  h(otherSIRD.h), vRates(otherSIRD.vRates),
  state(otherSIRD.state), SIRDeuler(otherSIRD.SIRDeuler){};



void SIRD::operator()()
{
  state = SIRDeuler();
}


void SIRD::operator()(double input_step)
{
   if (input_step <= 0)
  {
    throw std::invalid_argument("input_step cannot be < 0 or = 0");
  }
  state = SIRDeuler(input_step);
}

ostream& operator<<(ostream& os, const SIRD& Obj)
{
  cout.precision(8); // as requested
  os <<"Susceptible: "<< Obj.state[0]<<", "
     <<"Infected: "<<Obj.state[1] << ", "
     <<"Recovered: "<< Obj.state[2] << ", "
     <<"Deceased: "<< Obj.state[3] <<"\n";
  return os;
}


SIRD& SIRD::operator=(const SIRD& source)
{
  if (this != &source)
  {
    h=source.h;
    vRates= source.vRates;
    state= source.state;
    SIRDeuler= source.SIRDeuler;
  }

  return *this;
}



void SIRD::createODE()
{
  //using vRates directly causes issues, much safer to use variables
  double infectionRate = vRates[0];
  double recoveryRate = vRates[1];
  double deathRate = vRates[2];
  auto ODESIRD =
	  [=](vector<double> stateGiven) 
      {
	  double susceptibility = -(infectionRate * stateGiven[1] * stateGiven[0]);
	  //infected
	  double first = (infectionRate * stateGiven[1] * stateGiven[0]);
	  double second = (recoveryRate * stateGiven[1]);
	  double third = (deathRate * stateGiven[1]);

	  double infected = (first - second - third);
	  //-----
	  double recovered = recoveryRate * stateGiven[1];
	  double dead = deathRate * stateGiven[1];
	  vector<double> toReturn = { susceptibility, infected, recovered, dead };
	  return toReturn;
	};

  SIRDeuler = Euler<vector<double>>(ODESIRD, state, h);
}