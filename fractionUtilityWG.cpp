/**
 * Program Name: cis25Spring2021WilliamGHw3.cpp
 * Discussion:   fraction Utility
 * Written By:   William Golovlev
 * Date:         2021/05/17
 */

#include <iostream>
#include "fractionUtilityWG.h"
#include "FractionWG.h"
using namespace std;

void fractionUtilityWG::displayCommonPalindromeDigitWG(FractionWG* fwg) {
    int commonWG = 0;
    int dWG = (fwg->getDenom() > 0) ? fwg->getDenom() : -(fwg->getDenom());
    int nWG = (fwg->getNum() > 0) ? fwg->getNum() : -(fwg->getNum());
    bool numerator_set[10]{};
    bool denominator_set[10]{};
   
    for (auto i = 0; i < nWG; i++) {
        numerator_set[nWG % 10] = true;
        nWG /= 10;
    }

    for (auto i = 0; i < dWG; i++) {
        denominator_set[dWG % 10] = true;
        dWG /= 10;
    }

    for (auto i = 0; i < 10; i++) {
        if (numerator_set[i] && denominator_set[i]) {
            commonWG++;
        }
    }
    std::cout << "\n    There is/are " << commonWG << " common digit(s) of ";
    for (auto i = 0; i < 10; i++) {
        if (numerator_set[i] && denominator_set[i]) {
            std::cout << "\n      " << i;
        }
    }
    std::cout << "\n" << std::endl;
}

void fractionUtilityWG::displayClassInfoWG() {
    cout << "CIS 25 - C++ Programming\n"
        "Laney College\n"
        "William Golovlev\n"
        "\n"
        "Information --\n"
        "   Assignment:                      HW #3 Exercise #1\n"
        "   Implemented by:                  William Golovlev\n"
        "   Submitted Date:                  2020/05/17\n"
        "   Current Number of LEB available: 2\n"
        "   Allowed Number of LEB Used:      0\n"
        "   Remaining Number of LEB:         2\n" << endl;
}

