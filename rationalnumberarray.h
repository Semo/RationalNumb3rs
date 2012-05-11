#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"
#include <iostream>


namespace rnum {
class RationalNumberArray {

public:
    // Standard Constructor
    RationalNumberArray();

    // Constructor
    RationalNumberArray(unsigned int cap);

    // Copy Constructor
    RationalNumberArray(RationalNumberArray &r);

    // Destructor
    ~RationalNumberArray();

    // Get amount of elements contained in a List
    unsigned int size();

    // Returns the possible amount of RationalNumbers which can be stored inside.
    unsigned int capacity();

    // Removes RationalNumbers regarding the correct order in a RationalNumberArray.
    void remove(const unsigned int from, const unsigned int to);

    // Adds a RationalNumber to the RationalNumberArray
    void add(const RationalNumber& m_rn);

    // Resizes the Capacity of the RationalNumberArray to hold more RationalNumbers
    void resize(const unsigned int m_capacity);

    // Gets a RationalNumber specified by Index8765
    RationalNumber getRationalNumber(const unsigned int index);

    // Inserts a RationalNumber element at position called index.
    void insert(const RationalNumber& rn, const unsigned int index);

    // Prints beautified RationalNumbers containes in the RationalNumberArray.
    void print();

    //    unsigned int rnaError();

private:
    unsigned int RATIONALNUMBERARRAY_DEFAULT_SIZE;

    RationalNumber *m_rn;

    unsigned int m_capacity;
    unsigned int m_size;
};
}
#endif // RATIONALNUMBERARRAY_H
