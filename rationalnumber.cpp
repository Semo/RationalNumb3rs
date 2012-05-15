#include "rationalnumber.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>

using namespace std;
using namespace rnum;

RationalNumber::RationalNumber(int nominator, int denominator): m_nominator(nominator),m_denominator(denominator) {
}

RationalNumber::RationalNumber() {}

RationalNumber::RationalNumber(const int &value) {
    RationalNumber r = intToFrac(value);
    m_nominator = r.nominator();
    m_denominator = r.denominator();
}

RationalNumber::RationalNumber(const double &value) {
    RationalNumber r = decToFrac(value);
    m_nominator = r.nominator();
    m_denominator = r.denominator();
}


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

/*########## Operator overloading for RationalNumbers #######################*/

RationalNumber RationalNumber::operator+(const RationalNumber &rightSide) const{
    return add(*this, rightSide);
}


RationalNumber RationalNumber::operator-(const RationalNumber &rightSide) const{
    return sub(*this, rightSide);
}

RationalNumber RationalNumber::operator*(const RationalNumber &rightSide) const{
    return mult(*this, rightSide);
}


RationalNumber RationalNumber::operator/(const RationalNumber &rightSide) const{
    return div(*this, rightSide);
}


/*########## Operator overloading for int values #######################*/


RationalNumber RationalNumber::operator+(const int &rightSide) const{
    RationalNumber r = intToFrac (rightSide);
    return add(*this, r);
}

RationalNumber RationalNumber::operator-(const int &rightSide) const{
    RationalNumber r = intToFrac (rightSide);
    return sub(*this, r);
}


RationalNumber RationalNumber::operator*(const int &rightSide) const{
    RationalNumber r = intToFrac (rightSide);
    return mult(*this, r);
}


RationalNumber RationalNumber::operator/(const int &rightSide) const{
    RationalNumber r = intToFrac (rightSide);
    return div(*this, r);
}

void RationalNumber::operator=(int &rightSide)  {
    RationalNumber r = intToFrac (rightSide);
    m_nominator = r.nominator();
    m_denominator = r.denominator();
}


/*########## Operator overloading for doubles values #######################*/

RationalNumber RationalNumber::operator+(const double &rightSide) const{
    RationalNumber r = this->decToFrac(rightSide);
    return add(*this, r);
}

RationalNumber RationalNumber::operator-(const double &rightSide) const{
    RationalNumber r = this->decToFrac(rightSide);
    return sub(*this, r);
}

RationalNumber RationalNumber::operator*(const double &rightSide) const{
    RationalNumber r = this->decToFrac(rightSide);
    return mult(*this, r);
}

RationalNumber RationalNumber::operator/(const double &rightSide) const{
    RationalNumber r = this->decToFrac(rightSide);
    return div(*this, r);
}

void RationalNumber::operator=(double rightSide)  {
    RationalNumber r = r.decToFrac (rightSide);
    m_nominator = r.nominator();
    m_denominator = r.denominator();
}


RationalNumber rnum::operator+(const double &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r + rightSide;
}

RationalNumber rnum::operator-(const double &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r - rightSide;
}

RationalNumber rnum::operator*(const double &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r * rightSide;
}
RationalNumber rnum::operator/(const double &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r / rightSide;
}


RationalNumber rnum::operator+(const int &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r + rightSide;
}

RationalNumber rnum::operator-(const int &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r - rightSide;
}

RationalNumber rnum::operator*(const int &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r * rightSide;
}

RationalNumber rnum::operator/(const int &leftSide, const RationalNumber &rightSide)  {
    RationalNumber r (leftSide);
    return r / rightSide;
}


/*###############################################################################################*/

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

//RationalNumber::operator double() {
//    return double ((double) ((this->nominator ())/ (double)(this->denominator ())));
//}

RationalNumber RationalNumber::intToFrac(const int &value) const {
    return RationalNumber (value, 1);
}


RationalNumber RationalNumber::decToFrac(const double &value) const{

    double delta;
    long nominator;
    long denominator;
    double intpart;
    double epsilon =0.00001;

    modf(value,&intpart);

    nominator =intpart;
    denominator =1;

    delta = (double)nominator/(double)denominator;

    while(!fabs(delta-value) < epsilon) {
        if((delta-value) < epsilon) {
            nominator +=1;
        } else {
            denominator +=1;
            nominator = value * denominator;
        }
        delta = (double)nominator/(double)denominator;

    }
    return RationalNumber(nominator,denominator);
}

void RationalNumber::print() {
    cout << "{" << nominator() << "/" << denominator() << "}" <<  endl;
}
