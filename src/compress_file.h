#include <bits/stdc++.h>
#include "encoder.h"
using namespace std;
string compress_file(string file_name,Node*root){
    unordered_map<char, string> encode;
    encoder("",root,encode);
    ofstream fout;
    ifstream fin;
    string new_file,line;
    int i=0;
    while(file_name[i]!='.'){
       new_file.push_back(file_name[i]);
       i++;
    }
    new_file+="_compress.bin";
    fin.open(file_name);
    fout.open(new_file);
    while(fout && getline(fin,line)){
        for(int i=0; i<line.length(); i++){
              fout<<encode[line[i]];
        }
        fout<<endl;
    }
    fout.close();
    fin.close(); 
    return new_file;   
}