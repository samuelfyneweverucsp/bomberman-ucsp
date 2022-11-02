#ifndef __STATICPOINTARRAY_H__
#define __STATICPOINTARRAY_H__
#include "Point.h"

class StaticPointArray {
        int size;
        Point *data;        
    public:
        StaticPointArray(int size);
        StaticPointArray(const StaticPointArray &o);

        void setAt(int index, Point value);
        Point getAt(int index) const ;
        int getSize() const ;
        void printPointArray() const ;

        ~StaticPointArray();
};

#endif