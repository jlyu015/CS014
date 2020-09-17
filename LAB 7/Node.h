#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node {
public:
    Node(string);
    ~Node();
    string getKey();
    int getHeight();
    void setHeight(int);
    void setLeft(Node*);
    Node* getLeft();
    void setRight(Node*);
    Node* getRight();

private:
   string key;
   Node* left;
   Node* right;
   int height; 

};
#endif