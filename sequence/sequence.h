//
// Created by pesel on 27.05.2021.
//

#include <cstdlib>

#ifndef LAB02_SEQUENCE_H
#define LAB02_SEQUENCE_H

template<class T>
class sequence{
public:
    virtual T getFirst();
    virtual T getLast();
    virtual T get(int index);
    virtual sequence<T> getSubsequence();
    virtual size_t length();
    virtual void append(T item);
    virtual void prepend(T item);
    virtual void insertAt(T item, int index);
    virtual sequence<T>*concatenate(sequence<T> *list);
};

#endif //LAB02_SEQUENCE_H
