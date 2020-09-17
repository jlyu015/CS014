#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree() {
    root = nullptr;

}

void BSTree::insert(const string &newString){
    if(newString == "/n") {
        cout << "ERROR: cannot create node with no data" << endl;
        return;
    }
    Node *newNode = new Node(newString);
    if(root == nullptr) {
        root= newNode;
        root->right = nullptr;
        root->left = nullptr;
        root->count++;
    }
    else {
        Node *tempNode = root;
        while(tempNode != nullptr) {
            if(newNode->data == tempNode->data){
                tempNode->count++;
                return;
            }
            if(newNode->data < tempNode->data) {
                if(tempNode->left == nullptr) {
                    tempNode->left = newNode;
                    newNode->count++;
                    tempNode = nullptr;
                }
                else {
                    tempNode = tempNode->left;
                }
            }
            else {
                if(newNode->data > tempNode->data) {
                    if(tempNode->right == nullptr) {
                        tempNode->right = newNode;
                        newNode->count++;
                        tempNode = nullptr;
                    }
                }
            }   
        }
    }

}

void BSTree::remove(const string &key) {
    if(root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
        return;
    }
    remove(root, key);
}

void BSTree::remove(Node* node, const string &key) {

}

string BSTree::smallest() const {
	string smallest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->left != nullptr) {
			currNode = currNode->left;
		}
		smallest = currNode->data;
	}
	return smallest;
}

string BSTree::largest() const {
	string largest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->right != nullptr) {
			currNode = currNode->right;
		}
		largest = currNode->data;
	}
	return largest;
}
void BSTree::inOrder() const {
	inOrder(root);
}

void BSTree::postOrder() const {
	postOrder(root);
}

void BSTree::preOrder() const {
	preOrder(root);
}
        /* Printing */
        /* For all printing orders, each node should be displayed as follows:
           <string> (<count>)
           e.g. goodbye(1), Hello World(3)
           */
void BSTree::postOrder(Node* node) const {
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << "(" << node->count << "), ";
	}
	else {
		return;
	}
}


void BSTree::preOrder(Node* node) const {
	if (node != nullptr) {
		cout << node->data << "(" << node->count << "), ";
		preOrder(node->left);
		preOrder(node->right);
	}
	else {
		return;
	}
}


void BSTree::inOrder(Node* node) const {
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->data << "(" << node->count << "), ";
		inOrder(node->right);
	}
	else {
		return;
	}
}