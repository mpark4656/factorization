/*
 * primeFactorization.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: mpark
 */

#include <vector>
#include <iostream>
#include <cmath>
#include "primeFactorization.h"

primeFactorization::primeFactorization ( long long n ): integerManipulation ( n )
{
	first125000PrimeNum ( first125000Primes, 125000 );
}

void primeFactorization::factorization ()
{
    long long copyNum = getNum ();       // Create a working copy of num

    int index = 0;

    std::vector <int> factors;

    for ( index ; index < 125000 ; index ++ )
        while ( copyNum % first125000Primes [index] == 0 && index < 125000 )
        {
            factors.push_back ( first125000Primes [index] );
            copyNum /= first125000Primes [index];
        }

    if ( factors.size () < 2 )
        std::cout << getNum () << " is a prime number. Its factorization is:\n" << getNum () << " = " << getNum ();
    else
    {
        std::cout << getNum () << " is not a prime number. Its factorization is:\n" << getNum () << " = " << factors.at ( 0 );

        for ( int i = 1 ; i < factors.size () ; i ++ )
            std::cout << " * " << factors.at ( i );

        if ( copyNum > 1 )
            std:: cout << " * " << copyNum;
    }
}

void primeFactorization::first125000PrimeNum ( long long list[], int length )
{
    int i = 0;                                   // Used to control while loop & as index for first125000Primes array

    long long currentNumber = 2;

    while ( i < length )
    {
        bool isPrime = true;

        int sqrtCurrentNumber = std::sqrt ( currentNumber );     // Find sqrt of currentNumber

        // For any numbers less than the number of primes found so far and the prime number is not larger than the sqrt of currentNumber
        for ( int l = 0 ; l < i && first125000Primes [ l ] <= sqrtCurrentNumber ; l ++ )
        {
            if ( currentNumber % first125000Primes[ l ] == 0 )    // Find out if currentNumber is divisible by the primes already found
            {
                isPrime = false;
                break;
            }
        }

        if ( isPrime )
        {
            first125000Primes[ i ] = currentNumber;

            i ++;                                               // Increment if the number is a prime
        }

        currentNumber ++;                                       // Increment at the end of each while loop
    }
}
