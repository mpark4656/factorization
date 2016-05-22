/*
 * primeFactorization.h
 *
 *  Created on: Dec 10, 2015
 *      Author: mpark
 */

#ifndef PRIMEFACTORIZATION_H_
#define PRIMEFACTORIZATION_H_

#include "integerManipulation.h"

class primeFactorization: public integerManipulation
{
public:
	void factorization ();

	primeFactorization ( long long n = 0 );

private:
	long long first125000Primes [ 125000 ];

	void first125000PrimeNum ( long long list[], int length );
};

#endif /* PRIMEFACTORIZATION_H_ */
