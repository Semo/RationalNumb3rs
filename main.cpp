#include <iostream>
#include "RationalNumber.h"
#include <assert.h>

using namespace std;
using namespace rnum;



int main()
{

    RationalNumber a (2,3);
    RationalNumber b (5,3);

    RationalNumber r (7,3);

    assert(r == a+b);

    cout << "Hello World!" << endl;
    return 0;
}

