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
void apply();
void conversion();

//ask if we can private variables for Gb,Ib
// or does it need to be changed
int main()
{
  
  try
  {

    //operatorsTest();
    //norm();
    //apply();
    //conversion();

    
    std::ofstream fout;
    fout.open("data.csv");
    double stepsize = 0.15;
    float days = 200;
    IG modelTesting;

    fout.precision(8); // as requested
    int stepstoTake = days/stepsize;
    fout << "Timestep,Glucose,Insulin\n";
    for (int current_step = 0; current_step < stepstoTake; current_step++)
    {
      fout << current_step<<",";
      modelTesting();
      fout << modelTesting;
      if (current_step == 600)
      {
        modelTesting.controller.reset(300);
      }
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

void conversion()
{
  vector<double> test= {2,2,2,2};
  cout << (test ^ (2)) << endl;
  int n = static_cast<double>(test);   // OK: sets n to 7
  cout << n << endl;

}
void apply()
{
  vector<int> test = { 1,2,3,4 };
  test=test.apply([&](int n) {return n * 2; });
  cout << test << endl;
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