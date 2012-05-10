#include "rationalnumberarray.h"
#include "rationalnumber.h"


using namespace rnum;
using namespace std;

RationalNumberArray::RationalNumberArray(){
    RATIONALNUMBERARRAY_DEFAULT_SIZE = 12;
    rn = new RationalNumber[RATIONALNUMBERARRAY_DEFAULT_SIZE];
}

RationalNumberArray::RationalNumberArray(unsigned int cap){
    rn = new RationalNumber[cap];
}

/**
  * Destructor
  */
RationalNumberArray::~RationalNumberArray(){
    delete[] rn;
}

/**
  * Copy Constructor
  */
RationalNumberArray::RationalNumberArray(const RationalNumberArray& r){
    for (unsigned int i = 0; i < r.size; ++i) {
        this->rn[i] = r.rn[i];
    }
}

/**
  * Return the amount of RationalNumbers a RationalNumberArray contains.
  */
unsigned int RationalNumberArray::arraySize(){
    return this->size;
}

/**
  * Returns the possible amount of RationalNumbers which can be stored inside.
  */
unsigned int RationalNumberArray::arrayCapacity(){
    return this->capacity;
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
            this->capacity -= offset;

            for (unsigned int i = from; i <= this->arraySize(); ++i) {
                if(i+offset < this->arraySize()) {
                    this->rn[i] = this->rn[i+offset];
                }
            }
            this->size -= offset;
        }
    }
}

///**
//  * Adds a RationalNumber to the RationalNumberArray
//  */
//void RationalNumberArray::addElements(const RationalNumber& rn){
//        if((arraySize(this) + 1) > arrayCapacity())  {
//            arrayResize(rna, 2 * arrayCapacity(rna) + 2);
//        }

//        rna->rn[arraySize(rna)] = *rn;
//        rna->size += 1;
//}
