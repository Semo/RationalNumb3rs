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

int RationalNumber::gcd (int a, int b) const {

    // swap so that a is the number with the biggest value

    if(abs(b) > abs(a)) {
        int t = a; a=b; b=t;
    }

    // iteratively calculate the remainder r = a / b,
    // then make a the value of b and b the remainder, ...

    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;

    //    while(true) {
    //        a = a % b;
    //        if( a == 0 )
    //            return b;
    //        b = b % a;
    //        if( b == 0 )
    //            return a;
    //    }
}

int RationalNumber::lcm (int a, int b) const {
    return (a * b) / this->gcd(a, b);
}

RationalNumber RationalNumber::operator+(const RationalNumber &rightSide) const{
    RationalNumber r_1  (m_nominator * rightSide.m_denominator, m_denominator * rightSide.m_denominator);
    RationalNumber r_2  (rightSide.m_nominator * m_denominator, m_denominator * rightSide.m_denominator);
    RationalNumber r  (r_1.m_nominator + r_2.m_nominator, m_denominator * rightSide.m_denominator);
    int pirates = gcd(r.m_nominator, r.m_denominator);

    return RationalNumber (r.m_nominator/pirates, r.m_denominator/pirates);
}

RationalNumber RationalNumber::operator-(const RationalNumber &rightSide) const{
    RationalNumber r_1  (m_nominator * rightSide.m_denominator, m_denominator * rightSide.m_denominator);
    RationalNumber r_2  (rightSide.m_nominator * m_denominator, m_denominator * rightSide.m_denominator);
    RationalNumber r  (r_1.m_nominator - r_2.m_nominator, m_denominator * rightSide.m_denominator);
    int pirates = gcd(r.m_nominator, r.m_denominator);

    return RationalNumber (r.m_nominator/pirates, r.m_denominator/pirates);
}

RationalNumber RationalNumber::operator*(const RationalNumber &rightSide) const{
    RationalNumber r (m_nominator * rightSide.m_nominator, m_denominator * rightSide.m_denominator);
    return r;
}

RationalNumber RationalNumber::operator/(const RationalNumber &rightSide) const{
    RationalNumber r (m_nominator*rightSide.m_denominator, m_denominator * rightSide.m_nominator);
    return r;
}

bool RationalNumber::rnIsValid(const RationalNumber &n) const{
    if (n.m_denominator != 0) {
        return true;
    }
    return false;
}

bool RationalNumber::rnIsNaN(const RationalNumber &n) const{
    return !(this->rnIsValid(n));
}

bool RationalNumber::operator==(const RationalNumber &rightSide) const {
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

bool RationalNumber::operator<(const RationalNumber &rightSide) const{
    if (this->rnIsValid(*this) && this->rnIsValid(rightSide)) {
        int lcd = this->lcm(m_denominator, rightSide.m_denominator);
        RationalNumber r_1 (m_nominator * (m_denominator / lcd), lcd);
        RationalNumber r_2 (rightSide.m_nominator * (rightSide.m_denominator / lcd), lcd);

        if (r_1.m_nominator < r_2.m_nominator ) {
            return true;
        }
        return false;
    }
    return false;
}

bool RationalNumber::operator>(const RationalNumber &rightSide) const{
    if(!this->operator <(rightSide)) return true;
    return false;
}

bool RationalNumber::operator<=(const RationalNumber &rightSide) const{
    if(this->operator <(rightSide) || this->operator ==(rightSide)) return true;
    return false;
}

bool RationalNumber::operator>=(const RationalNumber &rightSide) const{
    if(this->operator >(rightSide) || this->operator ==(rightSide)) return true;
    return false;
}

RationalNumber RationalNumber::operator-(){
    return RationalNumber(-this->m_nominator,-this->m_denominator);
}

