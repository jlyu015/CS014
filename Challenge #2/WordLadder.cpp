#include "WordLadder.h"
#include <iostream>
#include <fstream>

using namespace std;

WordLadder::WordLadder(const string &fileName) {
    ifstream inFS;
    string currWord;
    inFS.open(fileName);
    if(!inFS.is_open()) {
        cout << "Error: could not open file. Exiting program" << endl;
        return;
    }
    while(inFS >> currWord) {
        if(currWord.length() == 5) {
            dict.push_back(currWord);
        }
        else {
            cout << "Error: one or more words in the file is not exactly 4 characters in length" << endl;
            return;    
        }
    }
    inFS.close();
}
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    list<string>::iterator iterator;
    stack<string> currStack;
    queue<stack<string>> currQueue;
    bool hayStart = false, hayEnd = false;
    ofstream outFS;

    outFS.open(outputFile);
    if(!outFS.is_open()){
        cout << "Error: could not open output file. Ending program." << endl;
        return;
    }

    if(dict.empty()) {
        cout << "list is empty" << endl;
        return;
    }


    for(iterator = dict.begin(); iterator != dict.end(); ++iterator) {
        if(*iterator == start){
            hayStart = true;

        }
        if(*iterator == end) {
            hayEnd = true;
        }
    }
    if(hayStart && hayEnd) {
        cout << "Both words exist in the dictionary" << endl;
    }
    else {
        cout << "Start word or end word does not exist in the dictionary" << endl;
        return;
    }
    if(start == end) {
        outFS << start;
        return;
    }
    currStack.push(start);
    currQueue.push(currStack);
    dict.remove(start);
    string currWord;

    while(!currQueue.empty()) {
        currWord = currQueue.front().top();
            for(iterator = dict.begin(); iterator != dict.end(); ++iterator) {
                if(similarityCount(currWord, *iterator)) {
                    if(*iterator == end) {
                        currQueue.front().push(end);
                        outputStack(currQueue.front(),outFS);
                        return;
                    }
                    currStack = currQueue.front();
                    currStack.push(*iterator);
                    currQueue.push(currStack);
                    iterator = dict.erase(iterator);
                    iterator--;
            }
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
           currQueue.pop();
    }

    outFS << "No Word Ladder Found.";
    cout << "No Word Ladder Found.";
    
}
bool WordLadder::similarityCount(const string& currWord, const string &currDictWord) {
    int similarities = 0; 
    for(unsigned i = 0; i < 5; ++i) {
        if(currWord.at(i) == currDictWord.at(i)) {
            ++similarities;
        }
    }
    if(similarities == 4 ) {
        return true;
    }
    else {
        return false;
    }
}

void WordLadder::outputStack(stack<string> stack, ofstream &outfile) { //changes the stack to a vector to output in correct order
    int count = 0;
    vector<string> ladder;
    while (!stack.empty()) {
        ladder.push_back(stack.top());
        stack.pop();
        count++;
    }
    if (outfile.is_open()) {
        while (count != 0) {
            count--;
            outfile << ladder.at(count);
            cout << ladder.at(count);
            if (count!=0) {
                outfile << " ";
                cout << " ";
            }
        }
        cout << endl;

    }
    outfile.close();
}