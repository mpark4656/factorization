/*
 * main.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: mpark
 */

#include <iostream>
#include "primeFactorization.h"

int main ()
{
	primeFactorization number;

	long long num;

	std::cout << "Enter an integer between 2 and 270,000,000,000,000: ";

	std::cin >> num;
	std::cout << std::endl;

	number.setNum ( num );

	number.factorization ();

	return 0;
}
