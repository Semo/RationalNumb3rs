#include "rationalnumberarray.h"
#include "rationalnumber.h"
#include <cstdlib>

using namespace rnum;
using namespace std;


/**
  * The Default-Constructor
  */
RationalNumberArray::RationalNumberArray(){
    RATIONALNUMBERARRAY_DEFAULT_SIZE = 12;
    m_rn = new RationalNumber[RATIONALNUMBERARRAY_DEFAULT_SIZE];
    this->m_capacity = RATIONALNUMBERARRAY_DEFAULT_SIZE;
    this->m_size = 0;
}

/**
  * Creates Constructor of Capacity x.
  */
RationalNumberArray::RationalNumberArray(unsigned int cap){
    m_rn = new RationalNumber[cap];
    this->m_capacity = cap;
    this->m_size = 0;
}

/**
  * Destructor
  */
RationalNumberArray::~RationalNumberArray(){
    delete[] m_rn;
}

/**
  * Copy Constructor
  */
RationalNumberArray::RationalNumberArray(RationalNumberArray &r){
    this->resize (r.capacity ());
    this->m_size = r.size ();

    for (unsigned int i = 0; i < m_size; ++i) {
        this->m_rn[i] = r.m_rn[i];
    }
}

/**
  * Return the amount of RationalNumbers a RationalNumberArray contains.
  */
unsigned int RationalNumberArray::size(){
    return this->m_size;
}

/**
  * Returns the possible amount of RationalNumbers which can be stored inside.
  */
unsigned int RationalNumberArray::capacity(){
    return this->m_capacity;
}

/**
  * Removes RationalNumbers regarding the correct order in a RationalNumberArray.
  */
void RationalNumberArray::remove(const unsigned int from, const unsigned int to){
    if (from < to) {
        if(!(to <= this->size ())){
            cout << "index out of bounds" << endl;
        } else {
            int offset = to - from;
            for (unsigned int i = from; i <= this->size(); ++i) {
                if(i+offset < this->size()) {
                    this->m_rn[i] = this->m_rn[i+offset];
                }
            }
            this->m_size -= offset;
        }
    }
}

/**
  * Adds a RationalNumber to the RationalNumberArray
  */
void RationalNumberArray::add(const RationalNumber& rn){
    if((size() + 1) > capacity())  {
        resize(2 * capacity() + 2);
    }
    this->m_rn[size ()] = rn;
    this->m_size += 1;

}

/**
  * Resizes the Array of RationalNumbers.
  */

void RationalNumberArray::resize(const unsigned int capacity){




    RationalNumber* rn_temp = new RationalNumber[capacity];

    //Set new Capacity


    //Copy old RationalNumbers to new Array of RationalNumbers.
    for (unsigned int i = 0; i < this->m_size; ++i) {
        rn_temp[i] = this->m_rn[i];
    }
    //    delete[] m_rn;
    m_rn = 0;

    m_capacity = capacity;
    // Replace ye olde Array of RationalNumber
    m_rn = rn_temp;

}

/**
      * Gets a RationalNumber specified by Index
      */
RationalNumber RationalNumberArray::getRationalNumber(const unsigned int index){
    return this->m_rn[index];
}

/**
      * Inserts a RationalNumber element at position called index.
      */
void RationalNumberArray::insert(const RationalNumber& rn, const unsigned int index){
    if(index > size()) {
        // fill not initialised Fields with {0,1}
        RationalNumber def (0,1);
        // filling cup
        for(unsigned int j = size(); j < index; ++j) {
            add(def);
        }
        this->m_rn[index] = rn;
    } else {
        if(size() + 1 > capacity()) {
            resize(2* capacity() + 2);
        }
        for(unsigned int i = size() + 1 ; i > index; --i) {
            this->m_rn[i] = this->m_rn[i-1];
        }
        this->m_rn[index] = rn;
    }
    this->m_size += 1;

}

/**
      * Prints beautified RationalNumbers containes in the RationalNumberArray.
      */
void RationalNumberArray::print(){
    for (unsigned int i = 0; i < capacity(); ++i) {
        cout << "{" << this->m_rn[i].nominator() << "/" << this->m_rn[i].denominator() << "} ";
    }
    cout << endl;
}

