#pragma once
#ifndef FRACTIONWG_H_
#define FRACTIONWG_H_
class FractionWG {
public:
	FractionWG(void); 
	FractionWG(const FractionWG&); 
	FractionWG(int, int);
	~FractionWG();

	bool isPalindromeWG();
	bool isPalindromeWG(int);
	
	void setNum(int n) { numWG = n; } 
	void setDenom(int d);
	
	int getNum() const { return numWG; }
	int getDenom() const { return denomWG; }
 
	void updateWG(int n, int d);

	int gcdWG(int n, int d);

private:
	
	int numWG;
	int denomWG;
};
#endif

