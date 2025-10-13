#include <bits/stdc++.h>
using namespace std;

//time complexity : O(N^2 * L) L is length of the words[i] 
//O(N) for erase function in worst case // to optimize , create new result and only push which are not anagrams;
//Sc : O(L) L is num of chars in the each word
bool checkanagram(string a, string b)
{
    unordered_map<char, int> mp;
    if (a.size() != b.size())
        return false;
    for (char ch : a)
    {
        mp[ch]++;
    }
    for (char ch : b)
    {
        if (mp.find(ch) != mp.end())
        {
            mp[ch]--;
            if (mp[ch] == 0)
                mp.erase(ch);
        }
        else
        {
            return false;
        }
    }
    return true;
}
vector<string> removeAnagrams(vector<string> &words)
{
    int i = 1;
    while (i < words.size())
    {
        if (checkanagram(words[i], words[i - 1]))
        {
            words.erase(words.begin() + i);
        }
        else
        {
            i++;
        }
    }
    return words;
}
int main()
{
    
    
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};

    vector<string> result = removeAnagrams(words);

    for(const string &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;

}