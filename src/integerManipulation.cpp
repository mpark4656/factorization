/*
 * integerManipulation.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: mpark
 */

#include <iostream>
#include <cmath>
#include <vector>
#include "integerManipulation.h"

void integerManipulation::setNum ( long long n )
{
	num = n;
}

long long integerManipulation::getNum ()
{
	return num;
}

void integerManipulation::reverseNum ()
{
	// Prevent accidental changes to the original member variable
	long long copyOfNum = num;

	int storeNumberOfDigits = 1;

	bool isNegative = false;



	while ( copyOfNum / 10 != 0 )
	{
		storeNumberOfDigits ++;

		copyOfNum = copyOfNum / 10;
	}

	//std::cerr << storeNumberOfDigits << std::endl;

	// Reset copyOfNum variable
	copyOfNum = num;



	if ( copyOfNum < 0 )
	{
		isNegative = true;
		copyOfNum = std::abs ( copyOfNum );
	}

	for ( ; storeNumberOfDigits > 0 ; storeNumberOfDigits -- )
	{
		int digit = copyOfNum % 10;

		//std::cerr << digit << std::endl;

        int exponent = storeNumberOfDigits - 1;

        //std::cerr << exponent << std::endl;

        //std::cerr << pow ( 10, 2 ) << std::endl;

        revNum = revNum + digit * std::pow ( 10, exponent );

        //std::cerr << storeRevNum << std::endl;

		copyOfNum = copyOfNum / 10;
	}

	if ( isNegative )
		revNum = - std::abs ( revNum );
}

void integerManipulation::classifyDigits ()
{
	long long temp;

	temp = std::abs ( num );

	int digit;

	while ( temp != 0 )
	{
		digit = temp - ( temp / 10 ) * 10;

		temp = temp / 10;

		if ( digit % 2 == 0 )
		{
			evensCount ++;

			if ( digit == 0 )
			{
				zerosCount ++;
			}
		}
		else
			oddsCount ++;
	}
}

int integerManipulation::getEvensCount ()
{
	return evensCount;
}

int integerManipulation::getOddsCount ()
{
	return oddsCount;
}

int integerManipulation::getZerosCount ()
{
	return zerosCount;
}

int integerManipulation::sumDigits ()
{
    int copyNum = std::abs ( num );     // Make a working copy of num

    std::vector <int> digits;           // Container for individual digits in num

    int sum = 0;                        // Stores sum of digits

    do
    {
        int nextDigit = copyNum % 10;   // Store the last digit of copyNum

        sum += nextDigit;

        copyNum /= 10;         // Integer-divide out the last digit
    }
    while ( copyNum != 0 );

    return sum;
}

integerManipulation::integerManipulation ( long long n )
{
	num = n;
	revNum = 0;
	evensCount = 0;
	oddsCount = 0;
	zerosCount = 0;
}
