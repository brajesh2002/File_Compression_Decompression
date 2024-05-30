#include <bits/stdc++.h>
#include "decoder.h"
using namespace std;
string decompress_file(string file_name,Node*root){
    unordered_map<string,char>decode;
    decoder("",root,decode);
    ifstream fin;
    ofstream fout;
    string new_file,line;
    int i=0;
    while(file_name[i]!='.'){
       new_file.push_back(file_name[i]);
       i++;
    }
    new_file+="_decompress.txt";
    fout.open(new_file);
    fin.open(file_name);
    while(fout && getline(fin,line)){
        string temp="";
        int len=line.length();
        for(int i=0; i<=len; i++){
              if(!temp.empty() && decode.find(temp)!=decode.end()){
                 fout<<decode[temp];
                 temp="";
              }
              if(i<len) temp.push_back(line[i]);
        }  
        fout<<endl; 
    }
    fout.close();
    fin.close();
    return new_file;  
}  