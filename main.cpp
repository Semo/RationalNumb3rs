#include <iostream>
#include "rationalnumber.h"
#include <assert.h>
#include "rationalnumberarray.h"

using namespace std;
using namespace rnum;



int main()
{
    cout << "Semo prod presentent:" << endl;
    cout << "Ladies and Gentleman..." << endl;
    cout << "Start of the Assertions..." << endl;

    RationalNumber a (2,3);
    RationalNumber b (5,3);
    RationalNumber c(0,1), d(2,3), e(9,3), f(-4,2), g(17,3);

    RationalNumber intTrNumPlus (11,3);
    RationalNumber intTrNumMinus (-7,3);
    RationalNumber intTrNumMult (6,3);
    RationalNumber intTrNumDiv (2,9);

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

    //Assert operator overloading with ints
    assert(a + 3 == intTrNumPlus);
    assert(a - 3 == intTrNumMinus);
    assert(a * 3 == intTrNumMult);
    assert(a / 3 == intTrNumDiv);

    RationalNumber r_temp = ((d+d)/d);
    RationalNumber r = d+d-d;

    // Hartmut's assertions!
    assert(c + d*e - f/g == testMe);
    RationalNumber z(4,-2);
    assert(-f == z);

    cout << z.nominator () << endl << z.denominator () << endl;

    // Part Two _ Reassurection

    RationalNumberArray rna (2);
    // Test of Adding RationalNumbers
    rna.add (a);
    rna.add (b);
    rna.add (c);
    rna.add (d);
    rna.print ();

    // Test RationalNumber removal
    rna.remove (0,2);
    rna.print ();

    // Test RationalNumber insert
    rna.insert (g,8);
    rna.print ();


    // Test another RationalNumber insert
    rna.insert (g,1);
    rna.print ();

     cout << "Before: rna.m_capacity: " << rna.capacity ()<< endl;
     cout << "Before: rna.m_size: " << rna.size ()<< endl;

    // Test call Default Constructor...
     rna.print ();
     RationalNumberArray rna_2 (rna);
    rna_2.print ();

    cout << "After: rna.m_capacity: " << rna.capacity ()<< endl;
    cout << "After: rna.m_size: " << rna.size ()<< endl;


    double test = (double)a;
    cout << test << endl;

    cout << "Fin" << endl;

    //Should never get here...
    return 0;
}
