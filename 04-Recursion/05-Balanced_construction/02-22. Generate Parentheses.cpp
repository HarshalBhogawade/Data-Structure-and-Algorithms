#include <bits/stdc++.h>
using namespace std;

//compleity : O(2^N) 
void generate(int opencnt, int closecnt, int n, string temp, vector<string> &ans)
{
    if (temp.size() == n * 2)
    {
        ans.push_back(temp);
        return;
    }
    char open = '(';

    char close = ')';
    if (opencnt < n)
    {
        generate(opencnt + 1,closecnt, n, temp+open, ans);
    }

    if(closecnt<opencnt){
        generate(opencnt,closecnt + 1,n,temp+close, ans);
    }
}
vector<string> parantheses(int n)
{
    vector<string> ans;
    generate(0, 0, n, "", ans);
    return ans;
}
int main()
{
    vector<string> ans = parantheses(3);
    for (auto &it : ans)
    {
        for (char ch : it)
        {
            cout << ch;
        }
        cout << " ";
    }
}