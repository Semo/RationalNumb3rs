#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"
#include <iostream>

/**
  * RationalNumberArray is a Program which creates the functionality to handle
  * and process dynamic Array functionality.
  *
  * @author Francois Dubois <siokdub@gmail.com>
  * @author Sebastian Morkisch <semox78@gmail.com>
  * @date 2012/05/15
  * @version 1.0
  *
  * (C) All rights reserved. 2012
  */

namespace rnum {
  class RationalNumberArray {

  public:
    /**
      * Standard Constructor
      */
    RationalNumberArray();

    /**
      * Constructor
      * @param unsigned int capacity
      */
    RationalNumberArray(unsigned int cap);

    /**
      * Copy Constructor
      *
      * @param Reference of RationalNUmberArray
      */
    RationalNumberArray(RationalNumberArray &r);

    /**
      * Destructor
      */
    ~RationalNumberArray();

    /**
      * Get amount of elements contained in a List
      */
    unsigned int size() const;

    /**
      * Returns the possible amount of RationalNumbers which can be stored inside.
      */
    unsigned int capacity();

    /**
      * Removes RationalNumbers regarding the correct order in a RationalNumberArray.
      *
      * @param unsigned int from  - which index
      * @param unsigned int to - which index
      */
    void remove(const unsigned int from, const unsigned int to);

    /**
      * Adds a RationalNumber to the RationalNumberArray
      *
      * @param referenced member of RationalNumber
      */
    void add(const RationalNumber& m_rn);

    /**
      * Resizes the Capacity of the RationalNumberArray to hold more RationalNumbers
      *
      * @param unsigned int from member m_capacity
      */
    void resize(const unsigned int m_capacity);

    /**
      * Gets a RationalNumber specified by Index
      *
      * @param unsigned int index
      */
    RationalNumber getRationalNumber(const unsigned int index);

    /**
      * Inserts a RationalNumber element at position called index.
      *
      * @param referenced member of RationalNumber
      * @param unsigned int index
      */
    void insert(const RationalNumber& rn, const unsigned int index);

    /**
      * Prints beautified RationalNumbers containes in the RationalNumberArray.
      */
    void print();

    /**
      * Assignment operator overloaded.
      *
      * @param referenced member of RationalNumberArray
      */
    void operator=(RationalNumberArray &rightSide);

    /**
      * Index operator
      *
      * @param unsigned int index
      */
    RationalNumber& operator[] (const unsigned int index);

    const RationalNumber& operator[] (const unsigned int index) const;

  private:
    // used to initialize the array with a default value of 12.
    unsigned int RATIONALNUMBERARRAY_DEFAULT_SIZE;

    // hidden impl of RationalNumber
    RationalNumber *m_rn;

    // the members of RationalNumberArray
    unsigned int m_capacity;
    unsigned int m_size;

    bool operator==(const RationalNumberArray &rightSide) const;
    void createCopy(RationalNumberArray &r);
  };
}
#endif // RATIONALNUMBERARRAY_H
