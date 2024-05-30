#include <iostream>
#include <fstream>
using namespace std;
string getTextString(string file_name)
{
    ifstream fin;
    fin.open(file_name);
    string line, text="";
    while (getline(fin, line))
    { 
        text = text + line;
    }
    fin.close();
    return text;
}