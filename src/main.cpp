#include <bits/stdc++.h>
#include "getTextString.h"
#include "frequency_of_character.h"
#include "creat_node.h"  
#include "insert_nodes_in_minHeap.h"
#include "build_huffman_tree.h"
#include "compress_file.h"
#include "decompress_file.h"
using namespace std;

int main()
{
    int x;
    cout << "***-----------------------------------------------------***" << endl;
    cout << "*** welcome to compress and decompress file application ***" << endl;
    cout << "*** Enter 1 for compressing the file                    ***" << endl;
    cout << "*** Enter -1 for Exit                                   ***" << endl;
    cout << "***-----------------------------------------------------***" << endl;
    cin >> x;
    if (x == -1)
    {
        return 0;
    }
    else
    {
        string file;
        cout << "Enter name of the file: ";
        cin >> file;
        string text = getTextString(file);
        unordered_map<char, int> mp;
        freq_of_char(text, mp);
        vector<Node *> nodes = createNode(mp);
        Min_Heap *pq = new Min_Heap();
        insert_nodes_in_minHeap(pq,nodes);
        Node *root = build_huffman_tree(pq);
        string compressed_file = compress_file(file, root);
        cout << "*** Enter 2 for decompressing the file                  ***" << endl;
        cin >> x;
        if (x == 2)
        {
            string decompressed_file = decompress_file(compressed_file, root);
        }
    }
    return 0;
}