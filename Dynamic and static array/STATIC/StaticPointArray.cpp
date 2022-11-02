#include <iostream>
#include "StaticPointArray.h"

using namespace std;

StaticPointArray::StaticPointArray(int size) {
    data = new Point[size];
    this->size = size;
}

StaticPointArray::StaticPointArray(const StaticPointArray &o) {
    size = o.size;
    data = new Point[o.size];
    for(int i = 0; i < size; i++)
        data[i] = o.data[i];
}

void StaticPointArray::setAt(int index, Point value) {
    if(index >= 0 && index < size)
        data[index] =  value;
}

Point StaticPointArray::getAt(int index) const {
    if(index >= 0 && index < size)
        return data[index];            
}

int StaticPointArray::getSize() const {
    return size;
}

void StaticPointArray::printPointArray() const {
    cout<<"[";
    for(int i = 0; i < size; i++){
        data[i].print();
        cout<<", ";
    }
    cout<<endl;
}

StaticPointArray::~StaticPointArray() {
    delete [] data;
}
