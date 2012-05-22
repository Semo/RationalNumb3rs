#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


/**
  * RationalNumber is a Program which handles RationalNumbers.
  *
  * @author Francois Dubois <siokdub@gmail.com>
  * @author Sebastian Morkisch <semox78@gmail.com>
  * @date 2012/05/15
  * @version 1.0
  *
  * (C) All rights reserved. 2012
  */

namespace rnum {
class RationalNumber {



public:

    RationalNumber(int nominator = 0, int denominator = 1);
//   RationalNumber(const int &value);
    RationalNumber(const double &value);
    ~RationalNumber();

    // mutator
    int nominator();
    int denominator();

    // accessor
    void nominator(int n);
    void denominator (int n);

    // Operatorenüberladung
    RationalNumber operator+(const RationalNumber &rightSide) const;
    RationalNumber operator-(const RationalNumber &rightSide) const;
    RationalNumber operator*(const RationalNumber &rightSide) const;
    RationalNumber operator/(const RationalNumber &rightSide) const;

    //Overrider für ints
    RationalNumber operator+(const int &rightSide) const;
    RationalNumber operator-(const int &rightSide) const;
    RationalNumber operator*(const int &rightSide) const;
    RationalNumber operator/(const int &rightSide) const;
    void operator=(int &rightside);

    //Overrider für doubles
    RationalNumber operator+(const double &rightSide) const;
    RationalNumber operator-(const double &rightSide) const;
    RationalNumber operator*(const double &rightSide) const;
    RationalNumber operator/(const double &rightSide) const;


    void operator=(double rightside);

    //Utilities
    RationalNumber intToFrac(const int &value) const;
    RationalNumber decToFrac(const double &value) const;
    void print();

    // Type-Overloading
    //operator double() ;


    RationalNumber add(const RationalNumber &lhs,const RationalNumber &rhs) const;
    RationalNumber sub(const RationalNumber &lhs,const RationalNumber &rhs) const;
    RationalNumber mult(const RationalNumber &lhs,const RationalNumber &rhs) const;
    RationalNumber div(const RationalNumber &lhs,const RationalNumber &rhs) const;

    //Boolsche Operatorenüberladung
    bool operator==(const RationalNumber &rightSide) const;
    bool operator<(const RationalNumber &rightSide) const;
    bool operator>(const RationalNumber &rightSide) const;
    bool operator<=(const RationalNumber &rightSide) const;
    bool operator>=(const RationalNumber &rightSide) const;

    //To have a unary Operator
    RationalNumber operator-();

    bool rnIsValid(const RationalNumber &n) const;
    bool rnIsNaN(const RationalNumber &n)const;

private:

    int m_nominator;
    int m_denominator;

    int gcd(int a, int b) const;
    int lcm(int n1, int n2) const;
    float calculateDenominator(float num);
};

RationalNumber operator+(const double &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator-(const double &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator*(const double &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator/(const double &leftSide, const RationalNumber &rightSide) ;

RationalNumber operator+(const int &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator-(const int &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator*(const int &leftSide, const RationalNumber &rightSide) ;
RationalNumber operator/(const int &leftSide, const RationalNumber &rightSide) ;

}

#endif // RATIONALNUMBER_H
