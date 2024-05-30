#include <bits/stdc++.h>
using namespace std;
void freq_of_char(string &text, unordered_map<char, int> &mp)
{
    int n = text.length();
    for (int i = 0; i < n; i++)
    {
        mp[text[i]]++;
    }
}