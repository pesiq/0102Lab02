#include <cassert>
#include <iostream>
#include "linkedListTest.h"
#include "../lower/dynamicArray.h"
#include "../sequence/sequence.h"
#include "../sequence/listSequence.h"

void listSeqConstructorDestructor(){
    listSequence<int> seq1;
    assert(seq1.length() == 0);
    seq1.append(10);
    seq1.append(20);
    seq1.prepend(30);
    assert(seq1.getFirst() == 30);
    assert(seq1.getLast() == 20);
    assert(seq1.get(1) == 10);

}

void listSeqOperations();
void listSeqAccess();

void listConDes(){
    linkedList<int> l1;

}
void listOperations();
void listAccess();

