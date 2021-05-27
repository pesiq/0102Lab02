#include <cstdlib>

#ifndef LAB02_ARRAY_H
#define LAB02_ARRAY_H

template <class T>
class dynamicArray{
protected:
    T *items;
    size_t size;
    size_t bufferSize;
    const size_t elementSize = sizeof(T);

public:
    //array creation
    dynamicArray(T* arr, size_t amount); //create array from static
    explicit dynamicArray(size_t amount); //create empty buffer
    dynamicArray(dynamicArray<T> const &array);// copy existing array

    //array destruction
    ~dynamicArray(); //destructor
    void deleteArray(); //deletion function

    //decomposition
    T get(int index); //get element at index
    size_t length(); //get size of array

    //operations
    void set(int index, T value); //set element at index
    //change size of array
    //negative value to reduce
    //positive value to increase
    void resize(int amount);
};

#endif //LAB02_ARRAY_H
