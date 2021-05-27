//
// Created by pesel on 04.05.2021.
//

#include "linkedList.h"

template<class T>
void linkedList<T>::append(T val) {
    size++;
    auto *temp = new struct item;
    temp->value = val;
    temp->next = nullptr;
    temp->previous = last;
    if(first == nullptr){
        first = temp;
    }
    last = temp;
}

template<class T>
void linkedList<T>::prepend(T val) {
    size++;
    auto *temp = new struct item;
    temp->value = val;
    temp->previous = nullptr;
    temp->previous = first;
    if(last == nullptr){
        last = temp;
    }
    first = temp;
}

template<class T>
void linkedList<T>::insertAt(T val, int index) {

    if(abs(index) > size){
        //TODO throw index out of range
    }

    if(index == 0){
        prepend(val);
        return;
    }
    if(index == size-1){
        append(val);
        return;
    }

    struct item *ptr = first;
    auto *newItem = new struct item;
    newItem->value = val;

    if(size == 0){
        newItem->next = nullptr;
        newItem->previous = nullptr;
        first = newItem;
        last = newItem;
        size++;
        return;
    }
    if(index > 0){
        while(index){
            ptr = ptr->next;
            index--;
        }
        newItem->previous = ptr->previous;
        ptr->previous = newItem;
        newItem->previous->next = newItem;
        newItem->next = ptr;

    } else {
        while (index){
            ptr = ptr->previous;
            index++;
        }
        newItem->previous = ptr->previous;
        ptr->previous = newItem;
        newItem->previous->next = newItem;
        newItem->next = ptr;
    }
    size++;
}

template<class T>
linkedList<T> &linkedList<T>::getSublist(size_t start, size_t end) {
    size_t resultSize = end - start + 1;
    T array[] = new T[resultSize];
    struct item *ptr = start;
    for (int i = 0; i < start; i++){
        ptr = ptr->next;
    }
    for (int i = 0; i < resultSize; i++){
        array[i] = ptr->value;
        ptr = ptr->next;
    }
    return linkedList<T>(array, resultSize);
}

template<class T>
T linkedList<T>::get(int index) {
    if(index > size || index < 0){
        //TODO throw index out of range
    }
    T temp;
    struct item *ptr = first;
    for(int i = 0; i < index; i++){
        ptr = ptr->next;
    }
    return ptr->value;
}

template<class T>
T linkedList<T>::getFirst() {
    if(first == nullptr) {
        //TODO throw index out of range
    }
    return first->value;
}

template<class T>
T linkedList<T>::getLast() {
    if(last == nullptr) {
        //TODO throw index out of range
    }
    return last->value;
}

template<class T>
size_t linkedList<T>::length() {
    return size;
}

template<class T>
void linkedList<T>::concatenate(linkedList<T> list) {
    struct item *ptr = list.first;
    for (int i = 0; i < list.size; i++) {
        append(ptr->value);
        ptr->next;
    }
}

template<class T>
linkedList<T>::linkedList() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

template<class T>
linkedList<T>::linkedList(T *items, size_t amount) {
    first = nullptr;
    last = nullptr;
    size = 0;
    for(int i = 0; i < amount; i++){
        append(items[i]);
    }
}

template<class T>
linkedList<T>::linkedList(const linkedList<T> &list) {
    first = nullptr;
    last = nullptr;
    size = 0;
    struct item *ptr = list.first;
    for(int i = 0; i < list.size; i++){
        append(ptr->value);
        ptr = ptr->next;
    }
}