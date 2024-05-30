#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
vector<Node *> createNode(unordered_map<char, int>&mp)
{
    vector<Node *>v;
    for (auto it : mp)
    {
        Node*temp = new Node(it.first,it.second);
        v.push_back(temp);
    }
    return v; 
}