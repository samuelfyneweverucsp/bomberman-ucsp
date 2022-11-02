#include <iostream>
#include "IntArray.h"

IntArray::IntArray(int size) {
    data = new int[size];
    this->size = size;
}

IntArray::IntArray(const IntArray &o) {
    size = o.size;
    data = new int[o.size];
    for(int i = 0; i < size; i++)
        data[i] = o.data[i];
}

void IntArray::setAt(int index, int value) {
    if(index >= 0 && index < size)
        data[index] = value;
}

int IntArray::getAt(int index) const {
    if(index >= 0 && index < size)
        return data[index];            
}

int IntArray::getSize() const {
    return size;
}

void IntArray::print() const {
    for(int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

IntArray::~IntArray() {
    delete [] data;
}
