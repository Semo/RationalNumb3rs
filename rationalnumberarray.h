#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

namespace rnum {
class RationalNumberArray {

public:
    //Standard Constructor
    RationalNumberArray();

    //Constructor
    RationalNumberArray(unsigned int cap);

    //Copy Constructor
   RationalNumberArray(const RationalNumberArray& r);

    //Destructor
    ~RationalNumberArray();

    //    unsigned int rnaSize();
    //    unsigned int rnaCapacity();
    //    void rnaRemove(const unsigned int from, const unsigned int to);
    //    void rnaResize(const unsigned int elements);
    //    void rnaAdd(const RationalNumber& rn);
    //    void rnaSet(const RationalNumber& rn, const unsigned int index);
    //    RationalNumber rnaGet(const unsigned int index);
    //    void rnaPrint();
    //    unsigned int rnaError();

    // accessors
    //    unsigned int capacity() const { return capacity; }
    //    unsigned int size() const { return size; }


private:
    RationalNumber *rn;
    unsigned int RATIONALNUMBERARRAY_DEFAULT_SIZE;
    unsigned int capacity;
    unsigned int size;
};
}
#endif // RATIONALNUMBERARRAY_H
