#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
	public:
		Node(string data);
		string data;
		int count;
		Node* left;
		Node* right;
		Node* parent;
};

#endif