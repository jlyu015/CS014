#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>
#include <cstdlib>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned minIndex;
    T min = vals.at(index);
    for(unsigned i = index; i < vals.size();++i) {
        if(vals.at(i) < min) {
            min = vals.at(i);
        }
    }
    for(unsigned i = index; i < vals.size(); ++i) {
        if(vals.at(i) == min) {
            minIndex = i;
            break;
        }
    }
    return minIndex;
}
template<typename T>
void selection_sort(vector<T> &vals){
    unsigned minIndex;
    T temp;
    for(unsigned i = 0; i < vals.size(); ++i) {
        minIndex = min_index(vals, i);
        temp = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp;
    }
}
template<typename T>
void display(const vector<T> &vals) {
    for(unsigned i = 0; i < vals.size(); ++i) {
        cout << vals.at(i) << endl;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}
int main(){
    vector <int> list;
    cout << "making int vector " << endl;
    list.push_back(6);
    list.push_back(5);
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    display(list);
    cout << endl;
    selection_sort(list);
    display(list);

    cout << endl << "making double vector " << endl;
    vector <double> list2;
    list2.push_back(6.4);
    list2.push_back(5.5);
    list2.push_back(4.2);
    list2.push_back(3.1);
    list2.push_back(2.6);
    list2.push_back(1.3);
    display(list2);
    cout << endl;
    selection_sort(list2);
    display(list2);

    cout << endl << "making string vector " << endl;
    vector<string> list3;
    list3.push_back("g");
    list3.push_back("f");
    list3.push_back("e");
    list3.push_back("d");
    list3.push_back("c");
    list3.push_back("b");
    list3.push_back("a");
    display(list3);
    cout << endl;
    selection_sort(list3);
    display(list3);

     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (const out_of_range& excpt) {
            cout << excpt.what() << endl;
            cout << "out of range exception occured" << endl;

        }

    }

    return 0;
}