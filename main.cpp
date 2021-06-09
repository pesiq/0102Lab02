#include <iostream>
#include "higher/Vector.h"
#include "higher/Set.h"
#include "exceptions/exceptions.h"

using namespace std;

template<class T>
arraySequence<T>& enterCoords(int amount){
    auto result = new arraySequence<T>;
    cout<<"Enter " << amount << " coordinates" << endl;
    T temp;
    for (int i = 0; i < amount; i++) {
        cin>>temp;
        result->append(temp);
    }
    return *result;
}

template<class T>
listSequence<T> &enterSet(){
    cout << "Enter amount of items" << endl;
    int amount;
    cin >> amount;
    if(amount < 1){
        throw invalidArgument();
    }
    auto *result = new listSequence<T>;
    for (int i = 0; i < amount; i++) {
        T temp;
        cin >> temp;
        result->append(temp);
    }
    return *result;
}

template<class T>
void menuVectors2(Vector<T> &vector1){
    bool work = true;
    cout<<vector1<<endl;
    while (work) {
        cout << "Choose action:" << endl;
        cout << "1. Add vectors" << endl;
        cout << "2. Subtract vectors" << endl;
        cout << "3. Multiply by a scalar" << endl;
        cout << "4. Dot product" << endl;
        cout << "5. Output current vector" << endl;
        cout << "6.Exit" << endl;
        int response;
        cin >> response;
        switch (response) {
            case 1: {
                Vector<T> vector2(enterCoords<T>(vector1.dim()));
                Vector<T> result = vector1.addVectors(vector2);
                cout << "Result:" << endl << result << endl;
                vector1 = result;
                break;
            }
            case 2: {
                Vector<T> vector2(enterCoords<T>(vector1.dim()));
                Vector<T> result = vector1.subVectors(vector2);
                cout << "Result:" << endl << result << endl;
                vector1 = result;
                break;
            }
            case 3: {
                T scalar;
                cout << "Enter a scalar number" << endl;
                cin >> scalar;
                Vector<T> result = vector1 * scalar;
                cout << "Result:" << endl << result << endl;
                vector1 = result;
                break;
            }
            case 4: {
                Vector<T> vector2(enterCoords<T>(vector1.dim()));
                T result = vector1 * vector2;
                cout << "Result:" << endl << result << endl;
                break;
            }
            case 5:
                cout << vector1 << endl;
                break;
            default:
                work=false;
                break;
        }
    }
}

template<class T>
void menuSets2(Set<T> &set1){
    bool work = true;
    while (work) {
        cout << "Current set : " << set1 << endl;
        cout << "1. Add to set" << endl;
        cout << "2. Delete from set" << endl;
        cout << "3. Union of sets" << endl;
        cout << "4. Intersection of sets" << endl;
        cout << "5. Difference of sets" << endl;
        cout << "6. Contain an element" << endl;
        cout << "7. Contain subset" << endl;
        cout << "8. Check equality of sets" << endl;
        cout << "9. Output current set" << endl;
        cout << "0. Exit" << endl;
        int response;
        cin >> response;
        switch (response) {
            case 1:{
                cout << "Enter value to add" << endl;
                T temp;
                cin >> temp;
                set1.add(temp);
                break;
            }
            case 2:{
                cout << "Enter value to remove" << endl;
                T temp;
                cin >> temp;
                set1.remove(temp);
                break;
            }
            case 3:{
                cout << "Enter set to test against" << endl;
                Set<T> set2(enterSet<T>());
                cout << set2 << endl;
                set1.unionize(set2);
                break;
            }
            case 4:{
                cout << "Enter set to test against" << endl;
                Set<T> set2(enterSet<T>());
                cout << set2 << endl;
                Set<T> tmp = set1.intersection(set2);
                cout << tmp << endl;
                break;
            }
            case 5:{
                cout << "Enter set to test against" << endl;
                Set<T> set2(enterSet<T>());
                cout << set2 << endl;
                Set<T> tmp = set1.difference(set2);
                cout << tmp << endl;
                break;
            }
            case 6:{
                T value;
                cout << "Enter a value to test" << endl;
                cin >> value;
                bool res = set1.includeElement(value);
                cout << res << endl;
            }
            case 7:{
                cout << "Enter set to test against" << endl;
                Set<T> set2(enterSet<T>());
                cout << set2 << endl;
                bool tmp = set1.includeSubset(set2);
                cout << tmp << endl;
                break;
            }

            case 8:{
                Set<T> set2(enterSet<T>());
                cout << set2 << endl;
                bool tmp = set1.equal(set2);
                cout << tmp << endl;
                break;
            }

            case 9:
                cout << set1 << endl;
                break;

            default:
                work = false;
                break;
        }
    }
}

void menuVector(int type){
    cout<<"Enter dimensions of a vector"<<endl;
    int dim;
    cin>>dim;

    switch (type) {
        case 1:{
            Vector<int> v(enterCoords<int>(dim));
            menuVectors2<int>(v);
            break;
        }
        case 2:{
            Vector<float> v(enterCoords<float>(dim));
            menuVectors2<float>(v);
            break;
        }
    }
}

void menuSet(int type){
    switch (type) {
        case 1:{
            Set<int> s;
            menuSets2<int>(s);
            break;
        }
        case 2:{
            Set<float> s;
            menuSets2<float>(s);
            break;
        }
    }
}

int main() {
    try {
        cout << "Welcome to MENU" << endl << "To use menu enter the corresponding number" << endl;
        cout << "What polymorphic class to use:" << endl << "1. Vector" << endl << "2. Set" << endl << "3. Exit"
             << endl;
        int classType;
        cin >> classType;
        if (classType == 3) {
            return 0;
        }
        cout << "Choose type of variables" << endl << "1. Integer" << endl << "2. Float" << endl;
        int type;
        cin >> type;
        switch (classType) {
            case 1: {
                menuVector(type);
                break;
            }
            case 2: {
                menuSet(type);
                break;
            }
            default:
                cout << "Done!" << endl;
                return 0;
        }
    } catch (exception &e){
        cout << e.what() <<endl;
    }
}
