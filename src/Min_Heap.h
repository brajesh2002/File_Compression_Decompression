#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

#ifndef MIN_HEAP_H
#define MIN_HEAP_H
class Min_Heap
{
private:
    vector<Node *> arr;

public:
    Node* top(){
        if(!isEmpty()){
           return arr[0];
        }
        return NULL;
    }
    void push(Node *node)
    {
        arr.push_back(node);
        heapify(); 
    }
    void pop()
    {
        if (isEmpty()){
            return;
        }
        if (arr.size() >= 1)
        {
            arr[0] = arr[arr.size() - 1];
            arr.pop_back();
            percolateDown(0);
        }
    }
    bool isEmpty()
    {
        if (arr.size() == 0){
            return true;
        }
        return false;
    }
    void heapify()
    {
        int n = arr.size();
        int child = n - 1, parent = (child - 1) / 2;
        while (1)
        {
            if (child > 0 && arr[child]->cost < arr[parent]->cost)
            {
                Node *temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
                child=parent;
                parent=(child-1)/2; 
            }
            else
            {
                break;
            }
        }
    }
    Node*getLeft(int parent){
        if(2*parent+1 < arr.size()){
            return arr[2*parent+1];
        } 
        return NULL;
    }
    Node*getRight(int parent){
        if(2*parent+2 < arr.size()){
            return arr[2*parent+2];
        } 
        return NULL;
    }
    void percolateDown(int parent){
        if(parent >= arr.size()){
            return ; 
        }
        int minCost=INT_MAX;
        Node* lNode=getLeft(parent),*rNode=getRight(parent);
        if(lNode!=NULL) minCost=min(minCost,lNode->cost); 
        if(rNode!=NULL) minCost=min(minCost,rNode->cost);
        

        if(lNode!=NULL && minCost!=arr[parent]->cost &&  minCost==lNode->cost){
             swap(arr[parent],arr[2*parent+1]);
             percolateDown(2*parent+1);
        }else if(rNode!=NULL && minCost!=arr[parent]->cost && minCost==rNode->cost){
             swap(arr[parent],arr[2*parent+2]);
             percolateDown(2*parent+2); 
        }else{
            return;      
        }
    }
    int size(){
        return arr.size();  
    }
};

#endif