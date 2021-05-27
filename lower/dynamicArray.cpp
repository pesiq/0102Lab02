#include "dynamicArray.h"

//constructors
template<class T>
dynamicArray<T>::dynamicArray(T *arr, size_t amount) {
    bufferSize = 2*amount;
    items = new T[bufferSize];
    size = amount;
    for(int i = 0; i < amount; i++){
        items[i] = arr[i];
    }
}

template<class T>
dynamicArray<T>::dynamicArray(size_t amount) {
    if(amount <= 0) {
        //TODO throw invalid argument
    }
    bufferSize = 2*amount;
    items = new T[bufferSize]; //allocating memory for dynamicArray
    size = amount;
}

template<class T>
dynamicArray<T>::dynamicArray(const dynamicArray<T> &array) {
    bufferSize = array.bufferSize;
    items = new T[bufferSize];
    size = array.size;
    for(int i = 0; i < array.size; i++){
        items[i] = array.items[i];
    }
}

//destructors
template<class T>
dynamicArray<T>::~dynamicArray() {
    delete[] items;
    delete this;
}

template<class T>
void dynamicArray<T>::deleteArray() {
    delete[] items;
    delete this;
}

//decomposition
template <class T>
T dynamicArray<T>::get(int index) {
    if(index > size || index < 0){
        //TODO throw index out of range
    }
    return items[index];
}

template<class T>
size_t dynamicArray<T>::length() {
    return size;
}

//operations
template<class T>
void dynamicArray<T>::set(int index, T value) {
    if(index > size || index < 0){
        //TODO throw index out of range
    }
    items[index] = value;
}

template<class T>
void dynamicArray<T>::resize(int amount) {

    if(amount == 0){
        return;
    }

    if (amount > 0){
        size += amount;
        if(size > bufferSize){
            T* temp = new T[size+(amount * 2)];
            bufferSize += amount * 2;
            for(int i = 0; i<size-amount; i++){
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
        }
        return;
    }

    if(amount < 0){
        if(size-amount > 0){
            size -= amount;
        } else {
            size = 0;
        }
        return;
    }
}

