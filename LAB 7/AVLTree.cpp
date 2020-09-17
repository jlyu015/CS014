#include "AVLTree.h"

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::insert(const string &key) {
    root = insert(root, key);
}

Node* AVLTree::insert(Node* node, string key) {
    int balance; 
    if(node == nullptr) {
        Node* newNode = new Node(key); //creates a new tree where key is the root value
        return newNode;
    }
    if(node->getKey() > key) {
        node->setLeft(insert(node->getLeft(), key));
    }
    else if(node->getKey() < key) {
        node->setRight(insert(node->getRight(), key));
    }
    else {
        return node; //bc it can't be equal
    }

    if(height(node->getLeft()) > height(node->getRight())) { //update height
        node->setHeight(height(node->getLeft()) +1); 
    }
    else {
        node->setHeight(height(node->getRight())+1);
    }

    balance = balanceFactor(node); //check for balance, if its within the intervals [-1,1]

    if(balance < -1 || balance > 1) {
        return rotate(node, key, balance);
    }
    return node;
}


int AVLTree::height(Node* node) {
    if(node == nullptr) {
        return 0;
    }
    else {
        return node->getHeight();
    }
}

Node* AVLTree::rotate(Node* node, string key, int balance) { // balance can only be [-1,1], if over, we have to rotate
    if(balance > 1 && key < node->getLeft()->getKey()) { // ll case
        return rotateRight(node);
    }
    if(balance < -1 && key > node->getRight()->getKey()) { //rr case
        return rotateLeft(node);
    }
    if(balance > 1 && key > node->getLeft()->getKey()) { // lr case
        node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    if(balance < -1 && key < node->getRight()->getKey()) { //rl case
        node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }
    return node;
}


Node* AVLTree::rotateRight(Node* node) { // updating might be wrong
    Node* lRoot = node->getLeft();
    Node* lrRoot = lRoot->getRight();

    lRoot->setRight(node); // shifts each variable one to the right
    node->setLeft(lrRoot); // if lRoot had a right value before the shift, then it becomes the new left value of the right side

    
    if(height(node->getLeft()) > height(node->getRight())) {
        node->setHeight(height(node->getLeft()) +1); // since we're shifting left, we want to update the height of the parentnode->left
    }
    else {
        node->setHeight(height(node->getRight())+1);
    }

    if(height(lRoot->getLeft()) > height(lRoot->getRight())) {
        lRoot->setHeight(height(lRoot->getLeft()) +1); // to change the parent height by 1 higher than the bigger side;
    }
    else {
        lRoot->setHeight(height(lRoot->getRight()) + 1);
    }

    return lRoot;

}
Node* AVLTree::rotateLeft(Node* node) { // might be wrong
    Node* rRoot = node->getRight();
    Node* rlRoot = rRoot->getLeft(); //rl = right left

    rRoot->setLeft(node);
    node->setRight(rlRoot);

    if(height(node->getLeft()) > height(node->getRight())) {
        node->setHeight(height(node->getLeft()) +1); // since we're shifting left, we want to update the height of the parentnode->left
    }
    else {
        node->setHeight(height(node->getRight())+1);
    }

    if(height(rRoot->getLeft()) > height(rRoot->getRight())) {
        rRoot->setHeight(height(rRoot->getLeft()) +1); // to change the parent height by 1 higher than the bigger side;
    }
    else {
        rRoot->setHeight(height(rRoot->getRight()) + 1);
    }
    

    return rRoot; // updated root
}


int AVLTree::balanceFactor(Node* node) {
    if(node == nullptr) {
        return 0;
    }
    else {
        return height(node->getLeft()) - height(node->getRight()); // returns both left and right height of the parent
    }
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
}
void AVLTree::printBalanceFactors(Node* node) {
    if(node != nullptr) {
        printBalanceFactors(node->getLeft());
        cout << node->getKey() << '(' << balanceFactor(node) << "), ";
        printBalanceFactors(node->getRight());
    }
}

void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()) {
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4) + ".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n) {
    if(n){
        if(n->getLeft()){
            visualizeTree(outFS,n->getLeft());
            outFS << n->getKey() <<" -> " << n->getLeft()->getKey() << ";" << endl;    
        }

        if(n->getRight()) {
            visualizeTree(outFS,n->getRight());
            outFS<<n->getKey() <<" -> " <<n->getRight()->getKey() << ";" << endl;    
        }
    }
}
