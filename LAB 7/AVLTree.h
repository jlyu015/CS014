#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"
using namespace std;

class AVLTree {
public:
    AVLTree();
    void insert(const string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    void visualizeTree(const string &);

private:
    int height(Node* node);
    Node* root;
    Node* insert(Node* node, string key);
    Node* rotate(Node* node, string key, int balance);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);

    int findUnbalancedNode();
    void printBalanceFactors(Node*);
    void visualizeTree(ofstream &, Node*);

};
#endif