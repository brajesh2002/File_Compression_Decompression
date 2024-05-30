#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
void encoder(string code, Node *root, unordered_map<char, string> &mp)
{
    if(root==NULL){
         return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        mp[root->ch] = code;
        return;
    }
    if (root->left != NULL)
    {
        encoder(code + "0", root->left, mp);
    }
    if (root->right != NULL)
    {
        encoder(code + "1", root->right, mp);
    }
}