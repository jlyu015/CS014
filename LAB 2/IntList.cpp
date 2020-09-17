#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    // dummyHead->next = dummyTail;
    // dummyTail->prev = dummyHead;

}
IntList::~IntList() {
     while(dummyHead->next != nullptr) {
        IntNode* temp;
        temp = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        delete temp;
        }
}
void IntList::push_front(int value) {

    IntNode *temp = new IntNode(value);

    if(empty()) {
        dummyHead->next = temp;
        temp->prev = dummyHead;
        temp->next = dummyTail;
        dummyTail->prev = temp;
    }
    else {
        temp->next = dummyHead->next;
        dummyHead->next = temp;
        dummyHead->next->next->prev = temp;
        temp->prev = dummyHead;
    }
    
}
void IntList::pop_front() {
    if(dummyHead->next->next != dummyTail) {
        IntNode *temp = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        dummyHead->next->prev = dummyHead;
        delete temp;    
    }
    else {
        IntNode *temp = dummyHead->next;
        dummyHead->next = nullptr;
        dummyTail->prev = nullptr;
        delete temp;
    }
}
void IntList::push_back(int value) {
    IntNode *temp = new IntNode(value);

    if(empty()) {
        dummyTail->prev = temp;
        temp->prev = dummyHead;
        temp->next = dummyTail;
        dummyHead->next = temp;
    }
    else {
        temp->prev = dummyTail->prev;
        dummyTail->prev = temp;
        dummyTail->prev->prev->next = temp;
        temp->next = dummyTail;
    }
}
void IntList::pop_back() {
    if(dummyTail->prev->prev != dummyHead) {
        IntNode *temp = dummyTail->prev;
        dummyTail->prev = dummyTail->prev->prev;
        dummyTail->prev->next = dummyTail;
        delete temp;
    }
    else {
        IntNode *temp = dummyTail->prev;
        dummyHead->next = nullptr;
        dummyTail->prev = nullptr;
        delete temp;
    }

}
bool IntList::empty() const {
    if(dummyHead->next == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *curr = nullptr;
    curr = rhs.dummyHead->next;
    if(rhs.empty()) {
        
    }
    else {
        while(curr->next != rhs.dummyTail) {
        out << curr->data << ' ';
        curr = curr->next;
        }
        out << curr->data;
    }
    return out;

}
void IntList::printReverse() const {
    IntNode *curr = dummyTail->prev;
    if(empty()) {
        
    }
    else {
        while(curr->prev != dummyHead) {
            cout << curr->data << ' ';
            curr = curr->prev;
        }
        cout << curr->data;
    }
}
