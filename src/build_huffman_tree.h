#include <bits/stdc++.h>
#include "Min_Heap.h"
#include "Node.h"
using namespace std;
Node *build_huffman_tree(Min_Heap *pq)
{
    while (!pq->isEmpty() && pq->size() > 1)
    {
        Node *n1 = pq->top();
        pq->pop();
        Node *n2 = pq->top();
        pq->pop();
        Node *newnode = new Node('\0', n1->cost + n2->cost);
        newnode->left = n1;
        newnode->right = n2;
        pq->push(newnode);
    }
    Node *root = pq->top();
    pq->pop();
    return root;
}