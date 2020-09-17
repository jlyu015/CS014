#include <iostream>

#include "IntList.h"


using namespace std;


int main() {
    //pushfront 0, 1 2, 3, 4, 5, 6
    cout << "THIS IS MAIN" << endl;
    IntList list;

    cout << "TESTING EMPTY()" << endl;
    if(list.empty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
        cout << list << endl;
    }
    
    cout << "TESTING PUSHFRONT" << endl;
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    cout << "DONE TESTING PUSHFRONT" << endl;
    cout << list << endl;

    cout << "TESTING PUSHBACK" << endl;
    list.push_back(6);
    cout << "DONE TESTING PUSHBACK" << endl;
    cout << list << endl;

    cout << "TESTING POPFRONT " << endl;
    list.pop_front();
    cout << "DONE TESTING POPFRONT"<< endl;
    cout << list << endl;

    cout << "TESTING POPBACK" << endl;
    list.pop_back();
    cout << "DONE TESTING POPFRONT" << endl;
    cout << list << endl;

    cout << "TESTING PRINT REVERSE" << endl;
    list.printReverse();
    cout << "DONE TESTING PRINT REVERSE" << endl;

    return 0;
}