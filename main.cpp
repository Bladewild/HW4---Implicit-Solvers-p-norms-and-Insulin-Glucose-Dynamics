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
#include "SIRD.h"

using std::cout;
using std::cin;
using std::endl;

void operatorsTest();

int main(int argc, char* argv[])
{
  
  try
  {
    operatorsTest();
    /*
    double stepsize = 0.1;
    float days = 30;
    vector<double> v_ratesInput= {0.01, 0.1, 0.05 };
    SIRD modelTesting;
    if (argc == 3)
    {
      double initpop = std::atof(argv[1]);
      double initinfected= std::atof(argv[2]);
      modelTesting = SIRD(initpop, initinfected,
        stepsize, v_ratesInput);
    }


    cout.precision(8); // as requested
    int stepstoTake = days/stepsize;
    cout << modelTesting;
    for (int current_step = 0; current_step < stepstoTake; current_step++)
    {
      modelTesting();
      cout << modelTesting;
    }*/


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

void operatorsTest()
{
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

}