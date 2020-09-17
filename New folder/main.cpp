#include <iostream>

using namespace std;

int main() {
    char input;
    bool isError = false;
    int count = 0;
    while(!isError) {
    cout << "enter a five bit word and press enter" << endl;


        while(input > 47 && input <58 && count <= 5) {
            cin >> input;
        }
    }
    





    return 0;
}