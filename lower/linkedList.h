#ifndef LAB02_LINKEDLIST_H
#define LAB02_LINKEDLIST_H

#include <cstdlib>

template <class T>
class linkedList{
private:
    struct item{
        T value;
        struct item* next;
        struct item* previous;
    };
    size_t size;
    struct item* first;
    struct item* last;

public:
    //creation
    linkedList(T* items, size_t amount); //create linkedList from static array
    linkedList(); //create empty linkedList
    linkedList(linkedList<T> const &list);  // copy existing linkedList

    //decomposition
    T getFirst(); //get first element
    T getLast(); //get last element
    T get(int index); //get element at index
    linkedList<T> &getSublist(size_t start, size_t end); //create linkedList of elements with index start to the element with index end
    size_t length(); //get size of linkedList

    //operations
    void append(T val); //add to the end
    void prepend(T val); //add to the beginning
    void insertAt(T val, int index); //add at the index
    void concatenate(linkedList<T> list); //concatenate 2 lists

};

#endif //LAB02_LINKEDLIST_H
