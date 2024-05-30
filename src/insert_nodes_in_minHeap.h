#include <bits/stdc++.h>
#include "Min_Heap.h"
#include "Node.h"
using namespace std;
void insert_nodes_in_minHeap(Min_Heap *pq,vector<Node*>&node){
     int size=node.size();
     for(int i=0; i<size; i++){
        pq->push(node[i]);
     }
}