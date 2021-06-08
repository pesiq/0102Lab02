#include <iostream>
#include "higher/Vector.h"
#include "higher/Set.h"

using namespace std;

void menuVector(){

}

void menuSet(){

}

int main() {
    cout<<"Welcome to MENU"<<endl<<"To use menu enter the corresponding number"<<endl;
    cout<<"What polymorphic class to use:"<<endl<<"1. Vector"<<endl<<"2. Set"<<endl<<"3. Exit";
    int classType;
    cin >> classType;
    int type;
    cin >> type;
    switch (classType) {
        case 1:{
            menuVector();
            break;
        }
        case 2:{
            menuSet();
            break;
        }
        default:
            return 0;
    }
}
