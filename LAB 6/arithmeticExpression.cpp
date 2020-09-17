#include "arithmeticExpression.h"
// collaborated with Ryan Ly

arithmeticExpression::arithmeticExpression(const string &userInput) {
    root = nullptr;
    infixExpression = userInput;
}

void arithmeticExpression::buildTree() {
    string postFix = infix_to_postfix();
    stack<TreeNode*> treeStack;
    TreeNode* parent, *nodeLeft, *nodeRight;
    char key = 'a';
    char currChar;
    for(unsigned i = 0; i < postFix.length(); ++i) {
        currChar = postFix.at(i);
        parent = new TreeNode(currChar, key);
        if (priority(currChar) != 0) {
			nodeRight = treeStack.top();
			treeStack.pop();
			nodeLeft = treeStack.top();
			treeStack.pop();
			parent->left = nodeLeft;
			parent->right = nodeRight;
		}
		treeStack.push(parent);
        ++key;
    }
    this->root = treeStack.top();
}

void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}
    
void arithmeticExpression::postfix() {
    postfix(root);
}
    
void arithmeticExpression::visualizeTree(ofstream &fout, TreeNode* node) {
	if (node != nullptr) {
		if (node->left != nullptr) {
			fout << node->key << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->data << "\"" << "];" << endl;
			fout << node->left->key << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->left->data << "\"" << "];" << endl;
			fout << node->key << " -> " << node->left->key << endl;
			if (node->right != nullptr) {
				fout << node->right->key << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->right->data << "\"" << "];" << endl;
				fout << node->key << " -> " << node->right->key << endl;
				visualizeTree(fout, node->left);
				visualizeTree(fout, node->right);
			}
			else {
				visualizeTree(fout, node->right);
			}
		}
		else {
			if (node->right != nullptr) {
				fout << node->key << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->data << "\"" << "];" << endl;
				fout << node->right->key << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->right->data << "\"" << "];" << endl;
				fout << node->key << " -> " << node->right->key << endl;
				visualizeTree(fout, node->right);
                visualizeTree(fout, node->left);
			}
		}
	}
    
}
    
int arithmeticExpression::priority(char op) {
     int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}
   
string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode *currNode) {
    if(currNode != nullptr) {
        if(currNode->left != nullptr) {
            cout << "(";
        }
        infix(currNode->left);
        cout << currNode->data;
        infix(currNode->right);
        if(currNode->right != nullptr) {
            cout << ")";
        }
    }
}

void arithmeticExpression::prefix(TreeNode *currNode) {
    if(currNode != nullptr) {
        cout << currNode->data;
        prefix(currNode->left);
        prefix(currNode->right);
    }
}


void arithmeticExpression::postfix(TreeNode *currNode) {
    if(currNode != nullptr) {
        postfix(currNode->left);
        postfix(currNode->right);
        cout << currNode->data;
    }
}

void arithmeticExpression::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
    
}