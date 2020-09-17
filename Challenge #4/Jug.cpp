#include "Jug.h"
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;


Jug::Jug(int a,int b,int c,int d,int e,int f,int g,int h,int i) {
    capA = a;
    capB = b;
    final = c;
    cFillA = d;
    cFillB = e;
    cEmptyA = f;
    cEmptyB = g;
    cPourAB = h;
    cPourBA = i;
    Node* fA = new Node("fill A");
    Node* fB = new Node("fill B");
    Node* eA = new Node("empty A");
    Node* eB = new Node("empty B");
    Node* pAB = new Node("pour A B");
    Node* pBA = new Node("pour B A");
    Actions.push_back(fA);
    Actions.push_back(fB);
    Actions.push_back(eA);
    Actions.push_back(eB);
    Actions.push_back(pAB);
    Actions.push_back(pBA);


    pair<int,int> t;
    t.first = 0;
    t.second = 0;
    visitedPairs.push_back(t);
}


Jug::~Jug() {
    for (unsigned i = 0; i < Actions.size(); ++i) {
        delete Actions.at(i);
    }
}


int Jug::solve(string &solution) {
    solution = ""; 
    if (cFillA < 0 || cFillB < 0 || cEmptyA < 0 || cEmptyB < 0 || cPourAB < 0 || cPourBA < 0) {
        return -1;
    }
    if (!(0 < capA && capA <= capB)) {
        return -1;
    }
    if (!(final <= capB && capB <= 1000)) {
        return -1;
    }
    const string& temp = solution;
    solution = solve(temp);
    if (solution == "") {
        return 0;
    }
    return 1;
}
pair<int,int> Jug::fillA(const pair<int,int> &p) {

}
pair<int,int> Jug::fillB(const pair<int,int> &p) {

}
pair<int,int> Jug::emptyA(const pair<int,int> &p) {

}
pair<int,int> Jug::emptyB(const pair<int,int> &p) {

}
pair<int,int> Jug::pourAB(const pair<int,int> &p) {

}
pair<int,int> Jug::pourBA(const pair<int,int> &p) {

}
pair<int,int> Jug::makePair(int, int) {

}
Paths Jug::doAction(const pair<int,int> &p, Node* n1) {

}
bool Jug::prevVisited(const pair<int,int> &p) {

}
string Jug::solve(const string &solution) {

}
