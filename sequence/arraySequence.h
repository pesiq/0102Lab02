//
// Created by pesel on 28.05.2021.
//

#ifndef LAB02_ARRAYSEQUENCE_H
#define LAB02_ARRAYSEQUENCE_H

#include "../lower/dynamicArray.h"
#include "sequence.h"

template<class T>
class arraySequence : public sequence<T> {
private:
    dynamicArray<T> array;
public:
    arraySequence(){
        array = dynamicArray<T>();
    }
    arraySequence(T* arr, int amount){
        array = dynamicArray(arr, amount);
    }
    explicit arraySequence(int amount){
        array = dynamicArray<T>(amount);
    }
    arraySequence(arraySequence<T> const &arr){
        array = dynamicArray(arr);
    }
};

#endif //LAB02_ARRAYSEQUENCE_H
