/*
 * integerManipulation.h
 *
 *  Created on: Dec 8, 2015
 *      Author: mpark
 */

#ifndef INTEGERMANIPULATION_H_
#define INTEGERMANIPULATION_H_

class integerManipulation
{
public:
	void setNum ( long long n );

	long long getNum ();

	void reverseNum ();

	void classifyDigits ();

	int getEvensCount ();

	int getOddsCount ();

	int getZerosCount ();

	int sumDigits ();

	integerManipulation ( long long n = 0 );

private:
	long long num;
	long long revNum;
	int evensCount;
	int oddsCount;
	int zerosCount;
};

#endif /* INTEGERMANIPULATION_H_ */
