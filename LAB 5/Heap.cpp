#include "Heap.h"

#include <iostream>
using namespace std;



Heap::Heap() {
    this->numItems = 0;

}


 
void Heap::enqueue(PrintJob* currPrintJob) {
    if(this->numItems >= 10) {
        //cout << "Highest item does not match with expected highest node in the heap after multiple enqueue operations." << endl;
        return;
    }
    arr[numItems] = currPrintJob;
     bubbleUp(numItems);
    ++numItems;
    //parent = i/2

   

}
void Heap::dequeue() {
    if(numItems == 0) {
        return;
    }
    if(numItems == 1) {
        arr[0] = nullptr;
        numItems = 0;
        return;
    }
    arr[0] = arr[numItems -1];
    arr[numItems - 1] = nullptr;
    --numItems;
    trickleDown(0);
}

PrintJob* Heap::highest() {
    // PrintJob* currPrint;
    // int maxPriority = arr[0]->getPriority();
    // int index = 0;
    // for(unsigned i = 0; i < numItems; ++i) {
    //     if(arr[i]->getPriority() > maxPriority) {
    //         maxPriority = arr[i]->getPriority();
    //         index = i;
    //     }
    //}
    if(numItems == 0 ) {
        //cout << "Max-Heap is empty" << endl;
        return 0;
    }
    return arr[0];
}

void Heap::print() {
// Priority: priority, Job Number: jobNum, Number of Pages: numPages
    if(numItems == 0) {
        cout << "Max-Heap is empty" << endl;
        return;
    }

   
    cout << "Priority: " << highest()->getPriority();
    cout << ", Job Number: " << highest()->getJobNumber();
    cout << ", Number of Pages: " << highest()->getPages() << endl;
    

}

void Heap::trickleDown(int currIndex) {

    //PrintJob* currPrintJob;
    for(int i = 0; i < numItems; ++i) {
        if(arr[currIndex]->getPriority() < arr[i]->getPriority()) {
        PrintJob* temp = arr[currIndex];
        arr[currIndex] = arr[i];
        arr[i] = temp;
 
        }
    }
}

void Heap::bubbleUp(int currIndex) {
    //PrintJob* currPrintJob;
    while (currIndex > 0 && arr[(currIndex-2)/2]->getPriority() < arr[currIndex]->getPriority()) {
        PrintJob* temp = arr[currIndex];
        arr[currIndex] = arr[(currIndex-1)/2];
        arr[(currIndex-1)/2] = temp;
        currIndex = (currIndex-1)/2;
        
    }
}