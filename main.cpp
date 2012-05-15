#include <iostream>
#include "rationalnumber.h"
#include <assert.h>
#include "rationalnumberarray.h"
#include "math.h"
#include <string>
#include <limits>


using namespace std;
using namespace rnum;



int main()
{
    cout << "Ladies and Gentleman..." << endl;
    cout << "Start of the Assertions..." << endl;

    RationalNumber a (2,3), b (5,3), c(0,1), d(2,3), e(9,3), f(-4,2), g(17,3);

    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    cout << "RationalNumbers: Add, Sub, Mul, Div" << endl;


    // RationalNumber operation Solutions
    RationalNumber r1 (7,3);
    RationalNumber r2 (-3,3);
    RationalNumber r3 (10,9);
    RationalNumber r4 (2,5);

    assert(r1 == a+b);
    assert(r2 == a-b);
    assert(r3 == a*b);
    assert(r4 == a/b);


    RationalNumber intTrNumPlus (11,3);
    RationalNumber intTrNumMinus (-7,3);
    RationalNumber intTrNumMult (6,3);
    RationalNumber intTrNumDiv (2,9);

    //Assert operator overloading with ints
    assert(a + 3 == intTrNumPlus);
    assert(a - 3 == intTrNumMinus);
    assert(a * 3 == intTrNumMult);
    assert(a / 3 == intTrNumDiv);

    RationalNumber doubleTrNumPlus(75233,18750);
    RationalNumber doubleTrNumMinus (-50233,18750);
    RationalNumber doubleTrNumMult (20911,9375);
    RationalNumber doubleTrNumDiv (12500,62733);

    //Assert operator overloading with doubles
    assert(a + 3.34576 == doubleTrNumPlus);
    assert(a - 3.34576 == doubleTrNumMinus);
    assert(a * 3.34576 == doubleTrNumMult);
    assert(a / 3.34576 == doubleTrNumDiv);

    // Given complex assertions
    RationalNumber solution(40,17);
    assert(c + d * e - f / g == solution);
    RationalNumber z(4, -2);
    assert(-f == z);

    cout << "Success!\n" << endl;
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    cout << "RationalNumbers: Conversions Double --> Rnum, Integer --> Rnum" << endl;

    double d_a = 2342.456742;
    RationalNumber rn_converted = rn_converted.decToFrac (d_a);
    cout << "Double representation of number: " << d_a << endl;
    rn_converted.print ();



    cout << "Success!\n" << endl;
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    cout << "RationalNumbers: <, >, >=, <=" << endl;
    assert(b > a);
    assert(b >= b);
    assert(b >= a);
    assert(a <= b);
    assert(b <= b);

    cout << "Success!\n" << endl;
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    cout << "RationalNumberArray: Create, Copy, Resize, Destroy, Add, Remove, " <<
            "Insert, Delete, Assign, Read/Write Index" << endl;

    // create rna
    cout << "testing whether RationalNumberArray adds RationalNumbers..." << endl;
    RationalNumberArray rna_a (2);
    rna_a.add (a);
    rna_a.add (b);
    rna_a.add (c);
    rna_a.add (d);
    rna_a.print ();
    cout << "Complete\n" << endl;

    cout << "testing whether RationalNumberArray removes RationalNumbers..." << endl;
    rna_a.remove (0,2);
    rna_a.print ();
    cout << "Complete\n" << endl;

    cout << "testing whether RationalNumberArray inserts a RationalNumber..." << endl;
    // Test RationalNumber insert
    rna_a.insert (g,7);
    rna_a.print ();

    cout << "testing copy constructor and destructor..." << endl;
    // Test call Default Constructor...
    RationalNumberArray rna_b (rna_a);
    rna_b.print ();
    cout << "Complete\n" << endl;


    // Test Assignment ops
    RationalNumberArray rna_c;
    rna_c.add (c);
    rna_c.add (d);
    cout << "Before assign" << endl;
    rna_c.print ();

    rna_c = rna_a;
    cout << "After assign" << endl;
    rna_c.print ();
    cout << "Complete\n" << endl;


    // Write rnum to index
    rna_c[0] = d;
    rna_c.print ();

    // Read rnum from index
    rna_c[7].print ();


    // Given stuff
    int i = 5, j = 4;
    RationalNumber aa(1,2), bb(7,3);

    RationalNumber aaa = i * aa, bbb = bb / j;
    RationalNumber ia (i);
    RationalNumber ja = j;
    cout <<"-------" << endl;
    aaa.print();
    bbb.print();
    ia.print();
    ja.print();


    cout << "Success!\n" << endl;
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

    // double test = (double)a;
    // cout << test << endl;

    //++++++++++++++++++

    cout << "The min value for double epsilon is:  "
         << numeric_limits<double>::epsilon( )
         << endl;
    cout << "The min value for long epsilon is:  "
         << numeric_limits<long>::epsilon( )
         << endl;
    cout << "The maximum value for type long is:  "
         << numeric_limits<long>::max( )
         << endl;
    cout << "The maximum value for type double is:  "
         << numeric_limits<double>::max( )
         << endl;

    //  double dd = 0.99999999;

    //  RationalNumber ab = ab.decToFrac (dd);
    //  ab.print ();
    //******************

    cout << "Fin" << endl;

    //Should never get here...
    return 0;
}
