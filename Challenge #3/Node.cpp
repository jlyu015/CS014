#include "Node.h"
#include <string>

using namespace std;

Node::Node(string dat) {
	this->data = dat;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->count = 1;
}