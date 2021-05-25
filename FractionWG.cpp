/**
 * Program Name: cis25Spring2021WilliamGHw3.cpp
 * Discussion:   FractionWG
 * Written By:   William Golovlev
 * Date:         2021/05/17
 */

#include <iostream>
#include "FractionWG.h"
using namespace std;

FractionWG::FractionWG() : numWG{ 0 }, denomWG { 1 } { 
	cout << "Calling FunctionWG() !\n";
}

FractionWG::FractionWG(const FractionWG& other) : numWG{ other.numWG }, denomWG{ other.denomWG } {
	cout << "    Calling FunctionWG(const FractionWG &) !\n\n";
}

FractionWG::FractionWG(int n, int d) : numWG{ n }, denomWG{ d }
{
	cout << "    Calling FunctionWG(int, int) !\n\n";
}

FractionWG::~FractionWG()
{
	cout << "    (Calling destructor!)" << endl;
}

void FractionWG::setDenom(int d)  
{

	if (d == 0) 
	{
		cout << "    Denominator cannot be 0";
	}
	else 
	{
		denomWG = (d > 0) ? d : -d; 
	}
}

void FractionWG::updateWG(int n, int d)
{
	if (d == 0) 
	{
		cout << "    Denominator cannot be zero!";
		return;
	}
	numWG = n; 
	denomWG = d; 
}

//Courtesy of TutorialsPoint
int FractionWG::gcdWG(int n, int d) {

	if (d == 0)
		return n;
	return gcdWG(d, n % d);
}

bool FractionWG::isPalindromeWG() {
	return FractionWG::isPalindromeWG(getNum())
		&& FractionWG::isPalindromeWG(getDenom());
}

bool FractionWG::isPalindromeWG(int x) {
	x = (x > 0) ? x : -x;
	int reverseWG = 0;
	int tempWG = x;

	while (tempWG > 0) {
		reverseWG *= 10;
		reverseWG += tempWG % 10;
		tempWG /= 10;
	}
	return x == reverseWG;
}
