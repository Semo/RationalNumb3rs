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
    this->m_capacity = ++cap;
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
RationalNumberArray::RationalNumberArray(const RationalNumberArray& r){
    for (unsigned int i = 0; i < r.m_size; ++i) {
        this->m_rn[i] = r.m_rn[i];
    }
}

/**
  * Return the amount of RationalNumbers a RationalNumberArray contains.
  */
unsigned int RationalNumberArray::arraySize(){
    return this->m_size;
}

/**
  * Returns the possible amount of RationalNumbers which can be stored inside.
  */
unsigned int RationalNumberArray::arrayCapacity(){
    return this->m_capacity;
}

/**
  * Removes RationalNumbers regarding the correct order in a RationalNumberArray.
  */
void RationalNumberArray::removeElements(const unsigned int from, const unsigned int to){
    if (from < to) {
        if(!(to <= this->arraySize ())){
            cout << "index out of bounds" << endl;
        } else {
            int offset = to - from;
            this->m_capacity -= offset;

            for (unsigned int i = from; i <= this->arraySize(); ++i) {
                if(i+offset < this->arraySize()) {
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
void RationalNumberArray::addElements(const RationalNumber& rn){
    if((arraySize() + 1) > arrayCapacity())  {
        arrayResize(2 * arrayCapacity() + 2);
    } else {
        this->m_rn[arraySize() + sizeof(this->m_rn)] = rn;
        this->m_size += 1;
    }
}

/**
  * Resizes the Array of RationalNumbers.
  */

void RationalNumberArray::arrayResize(const unsigned int capacity){

    //Allocate new Array for RationalNumbers with malloc
    RationalNumber* temp = (RationalNumber*) malloc(sizeof(this->m_rn) + capacity * sizeof(RationalNumber));

    //Set new Capacity
    this->m_capacity = capacity;

    //Copy old RationalNumbers to new Array of RationalNumbers.
    for (unsigned int i = 0; i < this->m_size; ++i) {
        temp[i] = this->m_rn[i];
    }

    // Replace ye olde Array of RationalNumber
    this->m_rn = temp;
}

