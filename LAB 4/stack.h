#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;
template<typename T> 
class stack {
    private:
        T data [MAX_SIZE];
        int size;
    public:
        stack() {
            size = 0;
        }
        void push(T val) {
            try {
                if(size >= MAX_SIZE) {
                    throw overflow_error("Called push on full stack.");
                }
                else {
                    data[MAX_SIZE - size - 1] = val;
                    size += 1;
                }
            }
            catch(overflow_error &exception) {
                cout << exception.what();   
            }
        }
        void pop() {
            try {
                if(size <= 0) {
                    throw underflow_error("Called pop on empty stack.");
                }
                else {
                    size -= 1;
                }
            }
            catch(underflow_error &exception) {
                cout << exception.what();
            }
        }
        T top() const {
            T val;
            try {
                if(size <= 0) {
                    throw underflow_error("Called top on empty stack.");
                }
                else {
                    val = data[MAX_SIZE - size];
                }
            }
            catch(underflow_error &exception) {
                cout << exception.what() << endl;
                exit(1);
            }
            return val;
        }
        bool empty() const {
            if (size == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};



#endif