#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {

    IntArray a(2);    

    a.setAt(0, 34);
    a.setAt(1, 35);

    a.print();

    if(true) {
        IntArray b = a;
    }
 
    return 0;
}
