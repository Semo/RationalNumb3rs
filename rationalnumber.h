#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {

public:

    RationalNumber();
    RationalNumber(int nominator, int denominator);
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

    //Utilities
    // RationalNumber floatToRnum(float f) const;
    RationalNumber convertToRnum(float num);

    // Type-Overloading
    operator double() ;

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
}

#endif // RATIONALNUMBER_H
