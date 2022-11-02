#include <iostream>
#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray() {
    this->size = 0;
    data = new int[0];
}

DynamicIntArray::DynamicIntArray(const int arr[], int size){
    this->size = size;
    data = new int[size];
    for(int i = 0; i < size; i++)
        data[i] = arr[i];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray &o) {
    this->size = o.size;
    this->data = new int[o.size];
    for(int i = 0; i < size; i++)
        data[i] = o.data[i];
}

int DynamicIntArray::getSize() const {
    return size;
}

void DynamicIntArray::print() const {
    std::cout << "[ ";
    for(int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "]" << std::endl;
}

void DynamicIntArray::push_back(int elem) {
    // 1
    int *tmp = new int[size + 1];
    // 2
    for(int i = 0; i < size; i++)
        tmp[i] = data[i];
    // 3
    tmp[size] = elem;
    // 4
    size += 1;
    // 5
    delete [] data;
    // 6
    data = tmp;
}

void DynamicIntArray::insert(int elem, int pos) {
    // 1
    int *tmp = new int[size + 1];
    // 2
    for(int i = 0, j = 0; i < size; i++, j++) {
        if( j == pos) {
            tmp[pos] = elem;
            i--;
        } else {
            tmp[j] = data[i];
        }        
    }
    // 3
    size += 1;
    // 4
    delete [] data;
    // 5
    data = tmp;
} 

void DynamicIntArray::remove(int pos) {
    int *tmp = new int [size-1];
    for(int i = 0, j = 0; i < size; i++, j++) {
        if( i == pos) {
            j--;
        } else {
            tmp[j] = data[i];
        }        
    }
    size -= 1;
    delete [] data;
    data = tmp;
}

DynamicIntArray::~DynamicIntArray() {
    delete[] data;
}
