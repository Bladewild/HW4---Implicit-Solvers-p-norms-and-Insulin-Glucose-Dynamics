/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: IG.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : CLATON PRICE
*
* Implementation file of IG
*/


#include "IG.h"

IG::IG() :
  desiredGlucose(100),
  h(0.15),
  p(vector<double>{0.05, 0.5, 0.0001, 0.00001, 150, 0.05}),
  vRates(vector<double>{10, 1}),
  vBase(vector<double>{ 300, 40 }),
  state(vector<double>{400, 0, 200}),
  IGeuler(
    Euler<vector<double>>(
  [this](vector<double> stateGiven)
  {
    //dGdt=−(p1+X)G+p1Gb+uG GLUCOSE
    double glucose = -(p[0] + stateGiven[1])* stateGiven[0] 
      + p[0] * vBase[0] 
      + vRates[0];
    //dXdt = −p2X + p3(I−Ib) helper
    double helper = -(p[1] * stateGiven[1])
      + p[2] * (stateGiven[2] - vBase[1]);
    //dIdt = p4max(0, G−p5)−p6(I−Ib) + uI Insulin

    double insulin = p[3] * (std::max(0.0, (stateGiven[0] - p[4])))
      - p[5] * (stateGiven[2] - vBase[1]) 
      + vRates[1];
    //-----
    vector<double> toReturn = { glucose, helper, insulin };
    return toReturn;
  }
      , state, h)),
    controller(
      PID(
        [this](void)
  {
    return desiredGlucose - state[0]; }, //calculateError
        [this](vector<double> k_input, double error, double iError, double dError)
  {
    double P = k_input[0] * error;
    double I = k_input[1] * iError;
    double D = k_input[2] * dError;

    return (P + I + D);
    }, {5,0.001,0.002}, (0), h,
    [this](double toChange){desiredGlucose = toChange;})
  )
{
  cout << "Default\n";
  /*
  cout << "stepsize: " <<h<<endl;
  cout << "vRates: " << vRates << endl;
  cout << "vBase: " << vBase << endl;
  cout << "state: " << vBase << endl;
  cout << "desiredGlucose: " << desiredGlucose << endl;*/
}

IG::IG(double input_desire, double step_size, const vector<double> & v_inputP,
  const vector<double>& v_inputRates,const vector<double> & v_inputBase,
  const vector<double> & v_inputState,const vector<double> v_Kinput):
  desiredGlucose(input_desire),h(step_size), p(v_inputP),
  vRates(v_inputRates), vBase(v_inputBase), state(v_inputState),
  IGeuler(
    Euler<vector<double>>(
  [this](vector<double> stateGiven)
  {
    //dGdt=−(p1+X)G+p1Gb+uG GLUCOSE
    double glucose = -(p[0] + stateGiven[1])* stateGiven[0] 
      + p[0] * vBase[0] 
      + vRates[0];
    //dXdt = −p2X + p3(I−Ib) helper
    double helper = -(p[1] * stateGiven[1])
      + p[2] * (stateGiven[2] - vBase[1]);
    //dIdt = p4max(0, G−p5)−p6(I−Ib) + uI Insulin

    double insulin = p[3] * (std::max(0.0, (stateGiven[0] - p[4])))
      - p[5] * (stateGiven[2] - vBase[1]) 
      + vRates[1];
    //-----
    vector<double> toReturn = { glucose, helper, insulin };
    return toReturn;
      }
      , state, h)), //EULER
    controller(
    PID(
    [this]() {return desiredGlucose - state[0]; }, //calculateError
    [this](vector<double> k_input, double error,double iError,double dError)
    {
      double P = k_input[0] * error;
      double I = k_input[1] * iError;
      double D = k_input[2] * dError;//derivative here

      return (P + I + D);
    }, v_Kinput,(v_inputState[1] -input_desire),step_size,    
    [this](double toChange){desiredGlucose = toChange;})
  )
{
  cout << "Input\n";/*
  cout << "stepsize: " << h << endl;
  cout << "vBase: " << vBase << endl;
  cout << "state: " << state << endl;
  cout << "desiredGlucose: " << desiredGlucose << endl; */
}
    // [*this](double s) {return desiredGlucose - state[0]; }, //calculateError

IG::IG(const IG& otherIG) :
  desiredGlucose(otherIG.desiredGlucose),h(otherIG.h),p(otherIG.p),
  vRates(otherIG.vRates), vBase(otherIG.vBase),
  state(otherIG.state), IGeuler(otherIG.IGeuler){}



void IG::operator()()
{
  //calculate U;
  vRates=controller();
  //test model
  state = IGeuler();
}


void IG::operator()(double input_step)
{
   if (input_step <= 0)
  {
    throw std::invalid_argument("input_step cannot be < 0 or = 0");
  }
  vRates = controller(input_step);
  state = IGeuler(input_step);
}

ostream& operator<<(ostream& os, const IG& Obj)
{
  os.precision(8); // as requested
  //os <<"Glucose: "<< Obj.state[0]<<", "
  //   <<"Insulin: "<< Obj.state[1] <<"\n";
  os << Obj.state[0] << ","<< Obj.state[1] << "\n";
  return os;
}


IG& IG::operator=(const IG& source)
{
  if (this != &source)
  {
    h=source.h;
    vRates= source.vRates;
    vBase = source.vBase;
    p = source.p;
    state= source.state;
    IGeuler= source.IGeuler;
  }

  return *this;
}


