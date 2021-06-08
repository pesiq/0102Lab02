//
// Created by pesel on 28.05.2021.
//

#include "dynamicArrayTest.h"
#include <cassert>

void dynamicArrConstDestr(){
    dynamicArray<int> arr1;
    assert(arr1.length() == 0);
    arr1.deleteArray();
    int sarr[] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
    dynamicArray<int> arr2 = dynamicArray<int>(sarr, 10);
    for(int i = 0; i < 10; i++){
        assert(arr2[i] == i+1);
    }
    assert(arr2.length() == 10);
    arr2.resize(5);
    assert(arr2. length() == 15);
    for (int i = 0; i < 5; i++){
        arr2[i+10] = i;
    }
    for (int i = 0; i < 5; i++){
        assert(arr2[i+10] == i);
    }
}
void dynamicArrAccess(){
    dynamicArray<int> arr1(10);
    for(int i = 0; i < 10; i++){
        arr1[i] = i;
    }
    dynamicArray<int> arr2(arr1);

    for(int i = 0; i < 10;i++){
        assert(arr1.get(i) == i);
    }

    arr1.resize(-5);

    for(int i = 0; i < 5; i++){
        assert(arr1[i] == arr2[i]);
    }

    arr1.prepend(0);
    assert(arr1.get(0) == 0);
    arr1.append(5);
    assert(arr1.get(6) == 5);

}

void arraySequencePrimary(){
    arraySequence<int> as1;
    for (int i = 0; i < 10; i++) {
        as1.append(i);
    }
    for (int i = 0; i < 10; i++) {
        assert(as1.get(i) == i);
        assert(as1[i] == i);
    }
}