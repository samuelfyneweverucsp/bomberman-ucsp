#include <iostream>
#include "DynamicIntArray.h"

using namespace std;

int main() {

    DynamicIntArray da;
    cout << da.getSize() << endl;

    int arreglo[] = {8, 9, 11, 5};
    DynamicIntArray da2(arreglo, 4);
    da2.print();
    DynamicIntArray da3 = da2;
    da3.print();

    da2.push_back(20);
    da2.print();
    da2.insert(30, 1);
    da2.print();
    da2.insert(5, 0);
    da2.print();

    da2.insert(100, 6);
    da2.print();

    return 0;
}
