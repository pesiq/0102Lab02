#include <iostream>
#include "lower/linkedList.h"
#include "lower/linkedList.cpp"

int main() {
    linkedList<int> list1;
    linkedList<int> list2;
    list2.append(20);
    list1.append(10);
    list1.concatenate(list2);

    int l1 = list1.getLast();
    int l2 = list2.getFirst();
    int c1 = list1.getFirst();
    int c2 = list1.getLast();

    std::cout << l1 << l2 << c1 << c2 << std::endl;
}
