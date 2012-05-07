#include "RationalNumber.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace rnum;

RationalNumber::RationalNumber(int nominator, int denominator) {
    this->m_nominator = nominator;
    this->m_denominator = denominator;
}

RationalNumber::~RationalNumber(){}

int RationalNumber::gcd (int n1, int n2) {
    int a = n1;
    int b = n2;

    while(true) {
        a = a % b;
        if( a == 0 )
            return b;

        b = b % a;
        if( b == 0 )
            return a;
    }
}

int RationalNumber::lcd (int n1, int n2) {
    return abs(n1 * n2) / gcd(n1, n2);
}

RationalNumber& RationalNumber::operator+(const RationalNumber &rightSide){
    int lcd = this->lcd(m_denominator, rightSide.m_denominator);
    RationalNumber r_1  (m_nominator * (m_denominator / lcd), lcd);
    RationalNumber r_2  (rightSide.m_nominator * (rightSide.m_denominator / lcd), lcd);

    RationalNumber r  (r_1.m_nominator + r_2.m_nominator, lcd);
    return r;
}

RationalNumber& RationalNumber::operator-(const RationalNumber &rightSide) {
    int lcd = this->lcd(m_denominator, rightSide.m_denominator);
    RationalNumber r_1 (m_nominator * (m_denominator / lcd), lcd);
    RationalNumber r_2 (rightSide.m_nominator * (rightSide.m_denominator / lcd), lcd);

    RationalNumber r (r_1.m_nominator - r_2.m_nominator, lcd);
    return r;
}

RationalNumber& RationalNumber::operator*(const RationalNumber &rightSide) {
    RationalNumber r (m_nominator * rightSide.m_nominator, m_denominator * rightSide.m_denominator);
    return r;
}

RationalNumber& RationalNumber::operator/(const RationalNumber &rightSide) {
    RationalNumber r (m_nominator*rightSide.m_denominator, m_denominator * rightSide.m_nominator);
    return r;
}

bool RationalNumber::rnIsValid(const RationalNumber &n) {
    if (n.m_denominator != 0) {
        return true;
    }
    return false;
}

bool RationalNumber::rnIsNaN(const RationalNumber &n){
    return !(this->rnIsValid(n));
}

bool RationalNumber::operator==(const RationalNumber &rightSide) {
    if (this->rnIsValid(*this) && this->rnIsValid(rightSide)) {
        int reducer_1 = this->gcd(m_nominator, m_denominator);
        int reducer_2 = this->gcd(rightSide.m_nominator, rightSide.m_denominator);
        RationalNumber r_1  (m_nominator / reducer_1, m_denominator / reducer_1);
        RationalNumber r_2 (rightSide.m_nominator / reducer_2, rightSide.m_denominator/ reducer_2);
        if (r_1.m_nominator == r_2.m_nominator && r_1.m_denominator == r_2.m_denominator) return true;
        return false;
    }
    return false;
}

//bool rnLessThan(RationalNumber n1, RationalNumber n2){
//    if (rnIsValid(n1) && rnIsValid(n2)) {
//        int lcd = leastCommonMultiple(n1.denominator, n2.denominator);
//        RationalNumber r_1 = {n1.nominator * (n1.denominator / lcd), lcd};
//        RationalNumber r_2 = {n2.nominator * (n2.denominator / lcd), lcd};

//        if (r_1.nominator < r_2.nominator ) {
//            return true;
//        }
//        return false;
//    }
//    return false;
//}


