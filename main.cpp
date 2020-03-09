/*
* Author: Marky Santos-Tankia
* File: main.cpp Date: 2/28/20
* Class: CS 5201
* Instructor : Clayton Price
*
* main file
*/
#include <iostream>
#include <sstream>
#include <string>
#include "vector.h"
#include "Euler.h"
#include "IG.h"
#include <algorithm>    // std::max
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

void operatorsTest();
void norm();
void ODETEST();

//ask if we can private variables for Gb,Ib
// or does it need to be changed
int main()
{
  
  try
  {

    //operatorsTest();
    //norm();
    //ODETEST();
    std::ofstream fout;
    fout.open("data.csv");
    double stepsize = 0.15;
    float days = 100;
    IG modelTesting;
    
    //IG modelTesting = IG(100, 1,
    //  0.1, v_ratesInput);    
    fout.precision(8); // as requested
    int stepstoTake = days/stepsize;
    fout << "Timestep,Glucose,Insulin\n";
    for (int current_step = 0; current_step < stepstoTake; current_step++)
    {
      fout << current_step<<",";
      modelTesting();
      fout << modelTesting;
    }


  }
  catch (const std::out_of_range & oor) {
    std::cerr << "\nOut of Range error: " << oor.what() << '\n';
  }
  catch (const std::invalid_argument & ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
  catch (const std::length_error & le) {
    std::cerr << "Length error: " << le.what() << '\n';
  }
  catch (const std::domain_error & de) {
    std::cerr << "Domain error: " << de.what() << '\n';
  }
  catch (...)
  {
    std::cerr << "An uknown error has occured." << '\n';
  }

  return 0;
}

void ODETEST()
{
  /*
  vector<double> p = { 0.05,0.5,0.0001,0.00001,150,0.05 };
  //GXI
  vector<double> state = { 400,0,200 };
  vector<double> vBase = { 300,40 };
  vector<double> vRates = { 1,1,1 };

  auto ode =
    [=](vector<double> stateGiven)
  {
    //dGdt=−(p1+X)G+p1Gb+uG GLUCOSE
    double glucose = -(p[0] + stateGiven[1]) * p[0] + p[0] * vBase[0] + vRates[0];
    //dXdt = −p2X + p3(I−Ib) helper
    double helper = -(p[1] * stateGiven[1]) + p[2] * (stateGiven[2] - vBase[1]);
    //dIdt = p4max(0, G−p5)−p6(I−Ib) + uI Insulin

    double insulin = p[3] * (std::max(0.0, (stateGiven[0] - p[4])))
      - p[5] * (stateGiven[2] - vBase[1]) + vRates[1];
    //-----
    vector<double> toReturn = { glucose, helper, insulin };
    return toReturn;
  };
  // e is error term
  //(in our case, the difference between the desired and actual blood glucose levels)

  double Kp = 5 + (rand() % 15);
  double Kd = Kp / (10 * (1 + rand() % 1));
  double Ki = Kp / (10 * (1 + rand() % 1));
  vector<double> vK = { Kp,Kd,Kp};
  auto ode =
    [=](double error)
  {
    double first = Kp * error;
    double second = Ki * error;
    double toReturn = first + second + third;
    return toReturn;
  };
*/
  /*
  dGdt=−(p1+X)G+p1Gb+uG
  dXdt=−p2X+p3(I−Ib)
  dIdt=p4max(0,G−p5)−p6(I−Ib)+uI
  */
}

void norm()
{

  cout << "NORM----------- " << endl;
  vector<int> first = { 1,-3,0,4};
  cout << (first^(1))<<endl;
  cout << (first ^ (2)) << endl;
  cout << (first ^ (99)) << endl;
  cout << "NORM----------- " << endl;

}
void operatorsTest()
{
  cout << "OPERATORS----------- " << endl;
  vector<int> first = { 1,1,1,1,1,1 };
  vector<int> second = { 2,2,2,2,2,2 };
  vector<int> plusequalsTest = { 3,3,3,3,3,3 };
  vector<int> minusEqualsTest = { 3,3,3,3,3,3 };
  vector<int> plusTest = first + first;
  vector<int> minusTest = first - first;
  plusequalsTest += plusequalsTest;
  minusEqualsTest -= first;



  vector<int> multiplyfirst = { 1,1,1,1,1,1 };
  vector<int> multiplysecond = { 2,2,2,2,2,2 };
  int multTest1 = multiplyfirst * multiplysecond;
  vector<int> multTest2 = 5 * multiplyfirst;
  vector<int> multTest3 = multiplyfirst * 10;

  
  cout << "plusTest: " << plusTest << endl;
  cout << "minusTest: " << minusTest << endl;
  cout << "plusequalsTest: " << plusequalsTest << endl;
  cout << "minusEqualsTest: " << minusEqualsTest << endl;
  cout << "multTest1: " << multTest1 << endl;
  cout << "multTest2: " << multTest2 << endl;
  cout << "multTest3: " << multTest3 << endl;
  cout << "OPERATORS----------- " << endl;

}