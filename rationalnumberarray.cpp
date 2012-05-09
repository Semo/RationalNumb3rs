#include "rationalnumberarray.h"
#include "rationalnumber.h"
#include <cstdlib>

using namespace rnum;

RationalNumberArray::RationalNumberArray(){
    RATIONALNUMBERARRAY_DEFAULT_SIZE = 12;
    rn = new RationalNumber[RATIONALNUMBERARRAY_DEFAULT_SIZE];
}

RationalNumberArray::RationalNumberArray(unsigned int cap){
    rn = new RationalNumber[cap];
}

/**
  * Destructor
  *
  */
RationalNumberArray::~RationalNumberArray(){
    delete[] rn;
}

/**
  * Copy Constructor
  *
  */
RationalNumberArray::RationalNumberArray(const RationalNumberArray& r){
    RationalNumberArray* rna = new RationalNumberArray(r.size);
    for (unsigned int i = 0; i < r.size; ++i) {
        rna->rn[i] = r.rn[i];
    }
}
