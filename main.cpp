#include <iostream>
#include "RationalNumber.h"
#include <assert.h>

using namespace std;
using namespace rnum;



int main()
{

    RationalNumber a (2,3);
    RationalNumber b (5,3);

    RationalNumber r1 (7,3);
    RationalNumber r2 (-3,3);
    RationalNumber r3 (10,9);
    RationalNumber r4 (2,5);

    assert(r1 == a+b);
    assert(r2 == a-b);
    assert(r3 == a*b);
    assert(r4 == a/b);
    assert(a < b);
    cout << "Hello World!" << endl;
    return 0;
}

