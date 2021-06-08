//
// Created by pesel on 28.05.2021.
//

#ifndef LAB02_LISTSEQUENCE_H
#define LAB02_LISTSEQUENCE_H

#include "sequence.h"
#include "../lower/linkedList.h"
#include "../lower/linkedList.cpp"

template<class T>
class listSequence : public sequence<T>{
private:
    linkedList<T> list;
public:

    listSequence(){
        list = linkedList<T>();
    }

    listSequence(T* arr, int amount){
        list = listSequence(arr, amount);
    }

    listSequence(linkedList<T> const &arr){
        list = linkedList<T>(arr);
    }

    ~listSequence(){
        list.deleteList();
    }

    void deleteSequence(){
        list.deleteList();
    }


    int length(){
       return list.length();
    }

    void append(T val){
        list.append(val);
    }

    void prepend(T val){
        list.prepend(val);
    }

    void insertAt(T val, int index){
        list.insertAt(index,val);
    }

    T get(int index){
        return list.get(index);
    }

    T getFirst(){
        return list.getFirst();
    }

    T getLast(){
        return list.getLast();
    }

    void deleteItem(int index){

    }

    void set(T val, int index){

    }

    sequence<T>* getSubsequence(int start, int end){
        auto newlist = list.getSublist(start, end);
        listSequence<T> *newseq = new listSequence<T>();
        for(int i = 0; i < newseq->length(); i++){
            newseq->append(newlist.get(i));
        }
        return newseq;
    }

    void concatenate(sequence<T> *li){
        for(int i = 0; i<li->length(); i++){
            this->append(li->get(i));
        }
    }

};

#endif //LAB02_LISTSEQUENCE_H
