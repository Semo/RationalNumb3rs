#include "rationalnumberarray.h"
#include "rationalnumber.h"
#include <cstdlib>
#include <assert.h>
#include <exception.h>

using namespace rnum;
using namespace std;
using namespace exceptions;

/**
  * The Default-Constructor starts to construct an Object with space for 12 elements.
  * Initializes member size with 0 elements.
  */
RationalNumberArray::RationalNumberArray(): m_capacity(12), m_size(0){
  m_rn = new RationalNumber[this->m_capacity];
}

/**
  * Creates Constructor of Capacity x.
  */
RationalNumberArray::RationalNumberArray(unsigned int cap): m_size(0) {
  m_rn = new RationalNumber[cap];
  this->m_capacity = cap;
}

/**
  * Destructor
  */
RationalNumberArray::~RationalNumberArray(){
  delete[] m_rn;
}

/**
  * Copy Constructor skilled in deep-Copy. :-)
  */
RationalNumberArray::RationalNumberArray(RationalNumberArray &r){
  createCopy(r);
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
  if(to < from) {
      throw Exception("InvalidSequence");
    }
  if (from < to) {
      if(!(to <= this->size ())){
          throw Exception("IndexOutOfBounds");

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
  this->m_size++;

}

/**
  * Resizes the Array of RationalNumbers and copying everything.
  */

void RationalNumberArray::resize(const unsigned int capacity){
  // Call for space for new array of RationalNumbers
  RationalNumber* rn_temp = new RationalNumber[capacity];

  //Set new Capacity
  m_capacity = capacity;

  //Copy old RationalNumbers to new Array of RationalNumbers.
  for (unsigned int i = 0; i < this->m_size; ++i) {
      rn_temp[i] = this->m_rn[i];
    }
  // delete old content to free the old Array.
  delete[] m_rn;

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
      // if current array to small to insert -> resize it.
      if(size() + 1 > capacity()) {
          resize(2* capacity() + 2);
        }
      //deep-copy of all elements after resize
      for(unsigned int i = size() + 1 ; i > index; --i) {
          this->m_rn[i] = this->m_rn[i-1];
        }
      this->m_rn[index] = rn;
    }
  this->m_size += 1;
}

/**
   *Prints beautified RationalNumbers containes in the RationalNumberArray.
   */
void RationalNumberArray::print(){
  for (unsigned int i = 0; i < size(); ++i) {
      cout << "{" << this->m_rn[i].nominator() << "/" << this->m_rn[i].denominator() << "} ";
    }

  // e.g. {17/3}
  cout << endl;
}

RationalNumber& RationalNumberArray::operator[] (const unsigned int index) {
  if (index > size ()) {
      throw Exception("IndexOutOfBounds");
  }
  return m_rn[index];
}

void RationalNumberArray::operator=(RationalNumberArray &rightSide) {
  delete[] m_rn;
  createCopy(rightSide);
}

void RationalNumberArray::createCopy(RationalNumberArray &r) {
  m_rn = new RationalNumber[r.capacity()];
  this->m_size = r.size();
  this->m_capacity = r.capacity();

  for (unsigned int i = 0; i < m_size; ++i) {
      this->m_rn[i] = r.m_rn[i];
    }

}
