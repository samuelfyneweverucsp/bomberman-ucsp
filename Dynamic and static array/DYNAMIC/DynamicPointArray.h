#ifndef __DYNAMICPOINTARRAY_H__
#define __DYNAMICPOINTARRAY_H__
#include "Point.h"

class DynamicPointArray {
        int size;
        Point *data;
    public:
        DynamicPointArray();
        DynamicPointArray(const Point arr[], int size);
        DynamicPointArray(const DynamicPointArray &o);

        int getSize() const;
        void print() const;

        void push_back(Point elem);
        void insert(Point elem, int pos);
        void remove(int pos);

        ~DynamicPointArray();
};

#endif