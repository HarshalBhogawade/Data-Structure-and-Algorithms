#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}};
void backtrack(int idx, string &digits, string &currstr, vector<string> &res)
{
    if (idx == digits.size())
    {
        res.push_back(currstr);
        return;
    }
    string letters = mp[digits[idx]];
    for (char c : letters)
    {
        currstr.push_back(c);
        backtrack(idx + 1, digits, currstr, res);
        currstr.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};
    vector<string> res;
    string currstr = "";
    backtrack(0, digits, currstr, res);
    return res;
}
int main()
{
    string s = "23";
    vector<string>ans = letterCombinations(s);
    for(auto &it: ans){
        for(char ch : it){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}