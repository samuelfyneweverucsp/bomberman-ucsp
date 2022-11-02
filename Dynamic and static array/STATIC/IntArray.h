#ifndef __INTARRAY_H__
#define __INTARRAY_H__

/**
 * Arreglo de enteros estático representado en una clase
*/
class IntArray {
        int size;
        int *data;        
    public:
        IntArray(int size);
        IntArray(const IntArray &o);

        void setAt(int index, int value);
        int getAt(int index) const ;
        int getSize() const ;
        void print() const ;

        ~IntArray();
};

#endif