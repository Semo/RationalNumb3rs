#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {

public:

    RationalNumber();
    RationalNumber(int nominator, int denominator);
    ~RationalNumber();

    // Operatorenüberladung
    RationalNumber& operator+(const RationalNumber &rightSide);
    RationalNumber& operator-(const RationalNumber &rightSide);
    RationalNumber& operator*(const RationalNumber &rightSide);
    RationalNumber& operator/(const RationalNumber &rightSide);
    bool operator==(const RationalNumber &rightSide);

    bool rnIsValid(const RationalNumber &n);
    bool rnIsNaN(const RationalNumber &n)   ;

private:
    int m_nominator;
    int m_denominator;
    int gcd(int n1, int n2);
    int lcd(int n1, int n2);
};

}

#endif // RATIONALNUMBER_H
