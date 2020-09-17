#include "Node.h"


Node::Node(string k) {
    key = k;
    left = nullptr;
    right = nullptr;
    height = 1;
}
Node::~Node() {

    }
string Node::getKey() {
    return key;
}

Node* Node::getRight() {
    return right;
}
int Node::getHeight() {
    return height;
}
Node* Node::getLeft() {
    return left;
}
void Node::setHeight(int h) {
    height = h;
}
void Node::setLeft(Node* l) {
    this->left = l;
}
void Node::setRight(Node* r) {
    this->right =  r;
}
