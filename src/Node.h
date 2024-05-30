#include <bits/stdc++.h>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    char ch;
    int cost;
    Node *left; 
    Node *right;
    Node(char ch, int cost)
    {
        this->ch = ch;
        this->cost = cost;
        this->left = NULL;
        this->right = NULL;
    }
};
  
#endif