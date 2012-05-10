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
    RationalNumberArray(const RationalNumberArray& r);

    // Destructor
    ~RationalNumberArray();

    // Get amount of elements contained in a List
    unsigned int arraySize();

    // Returns the possible amount of RationalNumbers which can be stored inside.
    unsigned int arrayCapacity();

    // Removes RationalNumbers regarding the correct order in a RationalNumberArray.
    void removeElements(const unsigned int from, const unsigned int to);

    // Adds a RationalNumber to the RationalNumberArray
    void addElements(const RationalNumber& m_rn);

    // Resizes the Capacity of the RationalNumberArray to hold more RationalNumbers
    void arrayResize(const unsigned int m_capacity);


    //    void rnaSet(const RationalNumber& rn, const unsigned int index);
    //    RationalNumber rnaGet(const unsigned int index);
    //    void rnaPrint();
    //    unsigned int rnaError();

private:
    unsigned int RATIONALNUMBERARRAY_DEFAULT_SIZE;

    RationalNumber *m_rn;

    unsigned int m_capacity;
    unsigned int m_size;
};
}
#endif // RATIONALNUMBERARRAY_H
