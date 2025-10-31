#include <bits/stdc++.h>
using namespace std;
void ispalindrome(string &s, int start, int end)
{
    if (start >= end)
    {
        cout << "Palindrome string" << endl;
        return;
    }
    if (s[start] != s[end])
    {
        cout << "Not Palindrome";
        return;
    }
    ispalindrome(s, start + 1, end - 1);
}
int main()
{
    string s = "ssfmfks";
    int start = 0;
    int end = s.size() - 1;
    ispalindrome(s, start, end);
}