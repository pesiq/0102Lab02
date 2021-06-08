#include "tests/dynamicArrayTest.h"
#include "tests/linkedListTest.h"
#include <iostream>

int main(){
    try {
        dynamicArrConstDestr();
        std::cout << "DACD is good!" << std::endl;
        listSeqConstructorDestructor();
        std::cout << "LLCA is good!" << std::endl;
        dynamicArrAccess();
        std::cout << "DAA is good!" << std::endl;
        arraySequencePrimary();
        std::cout << "DASP is good!" << std::endl;
    } catch (indexOutOfRange& e){
        std::cout << "IOOR\n" << e.what() << std::endl;
    }
}