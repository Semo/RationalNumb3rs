#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {

public:

    RationalNumber();
    RationalNumber(int nominator, int denominator);
    ~RationalNumber();

    // Operatorenüberladung
    RationalNumber operator+(const RationalNumber &rightSide) const;
    RationalNumber operator-(const RationalNumber &rightSide) const;
    RationalNumber operator*(const RationalNumber &rightSide) const;
    RationalNumber operator/(const RationalNumber &rightSide) const;
    bool operator==(const RationalNumber &rightSide) const;
    bool operator<(const RationalNumber &rightSide) const;
    bool operator>(const RationalNumber &rightSide) const;
    bool operator<=(const RationalNumber &rightSide) const;
    bool operator>=(const RationalNumber &rightSide) const;

    void operator-();

    bool rnIsValid(const RationalNumber &n) const;
    bool rnIsNaN(const RationalNumber &n)const;

private:


    int m_nominator;
    int m_denominator;
    int gcd(int a, int b) const;
    int lcm(int n1, int n2) const;
};
}

#endif // RATIONALNUMBER_H
