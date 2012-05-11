#include "rationalnumber.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace rnum;

RationalNumber::RationalNumber(int nominator, int denominator): m_nominator(nominator),m_denominator(denominator) {
/*    this->m_nominator = nominator;
    this->m_denominator = denominator;*/
}

RationalNumber::RationalNumber() {}

RationalNumber::~RationalNumber(){}

int RationalNumber::nominator() {
    return m_nominator;
}

int RationalNumber::denominator() {
    return m_denominator;
}

void RationalNumber::nominator(int n) {
    m_nominator = n;
}

void RationalNumber::denominator (int n) {
    m_denominator = n;
}

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
}

int RationalNumber::lcm (int a, int b) const {
    return (a * b) / this->gcd(a, b);
}

RationalNumber RationalNumber::operator+(const RationalNumber &rightSide) const{
    return add(*this,rightSide);
}

RationalNumber RationalNumber::operator+(const int &rightSide) const{
    RationalNumber r(rightSide,1);
    return add(*this, r);
}

RationalNumber RationalNumber::operator-(const RationalNumber &rightSide) const{
    return sub(*this,rightSide);
}

RationalNumber RationalNumber::operator-(const int &rightSide) const{
    RationalNumber r(rightSide,1);
    return sub(*this, r);
}

RationalNumber RationalNumber::operator*(const RationalNumber &rightSide) const{
    return mult(*this,rightSide);
}

RationalNumber RationalNumber::operator*(const int &rightSide) const{
    RationalNumber r(rightSide,1);
    return mult(*this, r);
}

RationalNumber RationalNumber::operator/(const RationalNumber &rightSide) const{
    return div(*this,rightSide);
}

RationalNumber RationalNumber::operator/(const int &rightSide) const{
    RationalNumber r(rightSide,1);
    return div(*this, r);
}


RationalNumber RationalNumber::add(const RationalNumber &ls,const RationalNumber &rhs) const {

    RationalNumber r_1  (ls.m_nominator * rhs.m_denominator, ls.m_denominator * rhs.m_denominator);
    RationalNumber r_2  (rhs.m_nominator * ls.m_denominator, ls.m_denominator * rhs.m_denominator);
    RationalNumber r  (r_1.m_nominator + r_2.m_nominator, ls.m_denominator * rhs.m_denominator);
    int pirates = gcd(r.m_nominator, r.m_denominator);

    return RationalNumber (r.m_nominator/pirates, r.m_denominator/pirates);
}
RationalNumber RationalNumber::sub(const RationalNumber &ls,const RationalNumber &rhs) const {

    RationalNumber r_1  (ls.m_nominator * rhs.m_denominator, ls.m_denominator * rhs.m_denominator);
    RationalNumber r_2  (rhs.m_nominator * ls.m_denominator, ls.m_denominator * rhs.m_denominator);
    RationalNumber r  (r_1.m_nominator - r_2.m_nominator, ls.m_denominator * rhs.m_denominator);
    int pirates = gcd(r.m_nominator, r.m_denominator);

    return RationalNumber (r.m_nominator/pirates, r.m_denominator/pirates);
}
RationalNumber RationalNumber::mult(const RationalNumber &ls,const RationalNumber &rhs) const {

    RationalNumber r (ls.m_nominator * rhs.m_nominator, ls.m_denominator * rhs.m_denominator);
    return r;
}
RationalNumber RationalNumber::div(const RationalNumber &ls,const RationalNumber &rhs) const {

    RationalNumber r (ls.m_nominator * rhs.m_denominator, ls.m_denominator * rhs.m_nominator);
    return r;
}

bool RationalNumber::rnIsValid(const RationalNumber &n) const{
    return n.m_denominator != 0;
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
        return r_1.m_nominator == r_2.m_nominator && r_1.m_denominator == r_2.m_denominator;
    }
    return false;
}

bool RationalNumber::operator<(const RationalNumber &rightSide) const{
    if (this->rnIsValid(*this) && this->rnIsValid(rightSide)) {
        int lcd = this->lcm(m_denominator, rightSide.m_denominator);
        RationalNumber r_1 (m_nominator * (m_denominator / lcd), lcd);
        RationalNumber r_2 (rightSide.m_nominator * (rightSide.m_denominator / lcd), lcd);
        return r_1.m_nominator < r_2.m_nominator;
    }
    return false;
}

bool RationalNumber::operator>(const RationalNumber &rightSide) const{
    return !this->operator <(rightSide);
}

bool RationalNumber::operator<=(const RationalNumber &rightSide) const{
    return this->operator <(rightSide) || this->operator ==(rightSide);
}

bool RationalNumber::operator>=(const RationalNumber &rightSide) const{
    return this->operator >(rightSide) || this->operator ==(rightSide);
}

RationalNumber RationalNumber::operator-(){
    return RationalNumber(-nominator (),-denominator ());
}

RationalNumber::operator double() {
    return double ((double)((this->nominator ())/ (double)(this->denominator ())));

}
