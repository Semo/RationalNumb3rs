#include <iostream>
#include "RationalNumber.h"
#include <assert.h>

using namespace std;
using namespace rnum;



int main()
{

    RationalNumber a (2,3);
    RationalNumber b (5,3);


    RationalNumber c(0,1), d(2,3), e(9,3), f(-4,2), g(17,3);
    RationalNumber testMe(40,17);
    RationalNumber testMeToo(-59,12);
    RationalNumber foo(3,4);
    RationalNumber bar(4,2);

    RationalNumber r1 (7,3);
    RationalNumber r2 (-3,3);
    RationalNumber r3 (10,9);
    RationalNumber r4 (2,5);

    // our own assertions
        assert(r1 == a+b);
        assert(r2 == a-b);
        assert(r3 == a*b);
        assert(r4 == a/b);
        assert(b > a);
        assert(b>=b);
        assert(b>=a);
        assert(b<=b);
        assert(a<=b);


    RationalNumber r_temp = ((d+d)/d);
    RationalNumber r = d+d-d;

    // Hartmut's assertions!
    assert(c + d*e - f/g == testMe);
    RationalNumber numb((-f), 1);



    cout << "Hello World!" << endl;
    return 0;
}

