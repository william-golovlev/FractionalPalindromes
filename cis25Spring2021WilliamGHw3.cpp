/**
 * Program Name: cis25Spring2021WilliamGHw3.cpp
 * Discussion:   Exercise 3
 * Written By:   William Golovlev
 * Date:         2021/05/17
 */

#include <iostream>
#include "FractionWG.h"
#include "fractionUtilityWG.h"
using namespace std;

void initFWG(FractionWG*& fwg);
FractionWG* fwg(FractionWG*& fwg);
FractionWG* createWG(void);
FractionWG* updateWG(FractionWG* fwg);
void printWG(FractionWG*& obj);

int main() {
	int optionWG;
	FractionWG* fwg{ nullptr };
	fractionUtilityWG utilityWG;
	
	utilityWG.displayClassInfoWG();
	do {
		cout << 
			"********************************************\n"
			"* MENU                                     *\n" 
			"* 1. Initializing                          *\n"
			"* 2. isPalindrome()                        *\n"
			"* 3. using displayCommonPalindromeDigitWG()*\n"
			"* 4. Printing                              *\n"
			"* 5. Quit                                  *\n"
			"********************************************\n"
			"Enter option (integer only): ";
		cin >> optionWG;

		switch (optionWG) {
		case 1:
			cout << "\n  INITIALIZING option -\n";
			initFWG(fwg);
			break;
		case 2:
			cout << "\n  Palindrome Option --" << endl;

			if (fwg == nullptr) {
				cout << "\n    Not a proper option as there "
					"is no Fraction!\n\n";
			} else {
				cout << "    The current Fraction is ";
				if (fwg->isPalindromeWG() == false) {
					cout << "not ";
				}
				cout << "a Palindrome!\n" << endl;
			}
			break;
		case 3:
			if (fwg == nullptr) {
				cout << "\n    Not a proper option as there "
					"is no Fraction!\n\n";
			}
			cout << "\n  displayCommonPalindromeDigit() "
					"Option -";
			if (fwg->isPalindromeWG() == false) {
				cout << "\n    The current Fraction is "
					"not a Palindrome!\n\n" << endl;
			} else {
				 utilityWG.displayCommonPalindromeDigitWG(fwg);
			}
			break;
		case 4:
			if (fwg != nullptr)
			{
				cout << "\n";
				printWG(fwg);
			} 
			else
			{
				cout << "\nNo fraction has been created!\n\n";
			}
			break;
		case 5:
			cout << "\n  Having fun...\n";
			delete fwg;
			fwg = nullptr;
			break;
		default:
			cout << "\n  WRONG OPTION!\n\n";
			break;
		}
	} while (optionWG != 5);

    return 0;
}

void initFWG(FractionWG*& fwg) {
	int subOptionWG;
	cout << "    Calling initFWG()!\n\n";
	do {
		cout << 
			"    **************************\n"
			"    * Sub-Menu: Initializing *\n"
			"    * 1. Creating            *\n"
			"    * 2. Updating            *\n"
			"    * 3. Returning           *\n"
			"    **************************\n"
			"    Select an option (integer only): ";
		cin >> subOptionWG;
		switch (subOptionWG) {
		case 1:
			if (fwg != nullptr) 
			{
				cout << "\n    Please update or return!\n\n";
				break;
			}
			cout << "\n      Creating 1 NEW FractionWG object!\n";
			fwg = createWG();
			break;
		case 2:
			if (fwg == nullptr) {
				cout << "\n      No fraction has been created yet!\n\n";
				break;
			}
			cout << "\n      Updating an EXISTING FractionWG object!\n";
			updateWG(fwg);
			break;
		case 3:
			cout << "\n      Returning to previous menu\n\n";		
			break;
		default:
			cout << "\n        Wrong option!\n\n";
			break;
		}
	} while (subOptionWG != 3);
}

/*FractionWG* fwg(FractionWG*& fwg)
{
	return nullptr;
}*/

FractionWG* createWG() {
	int denomWG = 0;
	int numWG;
	int gcdWG;
	FractionWG* fwg{ nullptr };

	cout << 
		"        Calling createWG()\n"
		"           Enter num: ";
	cin >> numWG;
	
	do {
		cout << "           Enter denom: ";
		cin >> denomWG;

		if (denomWG == 0) {
			cout << "\n              Cannot be 0, try again.\n\n";
		}
	} while (denomWG == 0);
	cout << "\n";

	gcdWG = fwg->gcdWG(numWG, denomWG);
	numWG /= gcdWG;
	denomWG /= gcdWG;

	return new FractionWG(numWG, denomWG);
}

FractionWG* updateWG(FractionWG* fwg) {
	int denomWG;
	int numWG;
	int gcdWG;

	cout <<
		"        Calling updateWG()\n"
		"           Enter num: ";
	cin >> numWG;
	cout << "           Enter denom: ";
	cin >> denomWG;
	cout << "\n";

	if (denomWG == 0) {
		cout << "              Cannot be 0, try again.\n\n";
		return nullptr;
	}

	gcdWG = fwg->gcdWG(numWG, denomWG);
	numWG /= gcdWG;
	denomWG /= gcdWG;

	fwg->updateWG(numWG, denomWG);
	return fwg;
}

void printWG(FractionWG*& fwg) {
	int n = fwg->getNum();
	int d = fwg->getDenom();
	
	cout << "\nPRINTING Option --\n"
		"  Address: "
		<< &fwg << "\n"
		<< "    num: "
		<< n 
		<< "\n    denom: "
		<< d << "\n\n"; 
} 

/*
* CIS 25 - C++ Programming
Laney College
William Golovlev

Information --
   Assignment:                      HW #3 Exercise #1
   Implemented by:                  William Golovlev
   Submitted Date:                  2020/05/17
   Current Number of LEB available: 2
   Allowed Number of LEB Used:      0
   Remaining Number of LEB:         2

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 6

  WRONG OPTION!

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 2

  Palindrome Option --

    Not a proper option as there is no Fraction!

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 1

  INITIALIZING option -
    Calling initFWG()!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 2

      No fraction has been created yet!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 5

      Wrong option!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 1

      Creating 1 NEW FractionWG object!
        Calling createWG()
           Enter num: 5
           Enter denom: -959

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 3

      Returning to previous menu

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 4

PRINTING Option --
  Address: 00F3F8BC
    num: -5
    denom: 959

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 2

  Palindrome Option --
    The current Fraction is a Palindrome!

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 3

  displayCommonPalindromeDigitWG() Option -
    There is/are 1 common digit(s) of
      5

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 1

  INITIALIZING option -
    Calling initFWG()!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 2

      Updating an EXISTING FractionWG object!
        Calling updateWG()
           Enter num: 156810000
           Enter denom: 49914173

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 3

      Returning to previous menu

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 4

PRINTING Option --
  Address: 00F3F8BC
    num: 156810000
    denom: 49914173

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 2

  Palindrome Option --
    The current Fraction is not a Palindrome!

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 3

  displayCommonPalindromeDigitWG() Option -
    The current Fraction is not a Palindrome!
*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 1

  INITIALIZING option -
    Calling initFWG()!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 1

    Please update or return!

    **************************
    * Sub-Menu: Initializing *
    * 1. Creating            *
    * 2. Updating            *
    * 3. Returning           *
    **************************
    Select an option (integer only): 3

      Returning to previous menu

*********************************************
*        MENU                               *
* 1. Initializing                           *
* 2. isPalindrome()                         *
* 3. using displayCommonPalindromeDigitWG() *
* 4. Printing                               *
* 5. Quit                                   *
*********************************************
Enter option (integer only): 5

  Goodbye
    (Calling destructor!)
*/

/* LOGIC_CODE_OUTPUT ISSUES
Don't put a non-integer in menu.
*/