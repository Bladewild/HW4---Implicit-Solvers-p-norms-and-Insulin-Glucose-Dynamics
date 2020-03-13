
#ifndef GLOBAL_H
#define GLOBAL_H


#include <functional>

/*!
* @brief pow function for ints
* @param[in] input_element value to pow
* @param[in] input_pow how much to exponentiate
* @pre input_pow>=0
* @post returns pow of input_element
* @throw invalid_argument input_pow<0
*/
double customPow(const double input_element, const int input_pow);

/*!
* @brief  calculates nth root
* @param[in] 
* @param[in] 
* @post returns double scalar of given arguements
* @throw invalid_argument N<0
*/

double nthRoot(double value, int N);

/*!
* @brief 
* @param[in] 
* @param[in] error 
* @post returns integral between a,b, of n (yfunction)
* @post 
*/
//double trapezoidalIntegral(double a, double b, int n, double error);

#endif