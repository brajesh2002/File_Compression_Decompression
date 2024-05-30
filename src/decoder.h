#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
void decoder(string code, Node *root, unordered_map<string,char> &mp)
{
    if(root==NULL){
         return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        mp[code] = root->ch;
        return;
    }
    if (root->left != NULL)
    {
        decoder(code + "0", root->left, mp);
    }
    if (root->right != NULL)
    {
        decoder(code + "1", root->right, mp);
    }
}