#include <bits/stdc++.h>
using namespace std;

// tc => O(2^n) as we make two choices take or not take
// print subsequences for array including empty set
// num of subsequences = 2^n where n = num of elem in array
void printSubsequence(int idx, vector<int> ans, int arr[])
{
    if (idx >= 3)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        cout<<" ";
        if (ans.size() == 0)
        {
            cout << "{}";
        }
        return;
    }
    // take current element in your subsequence
    ans.push_back(arr[idx]);
    printSubsequence(idx + 1, ans, arr);

    // not take
    // current elment is not added in your subsqeucnee
    ans.pop_back();
    printSubsequence(idx + 1, ans, arr);
}


// print subsqeusnce of the string
void strSubsequence(int idx, string temp, string s)
{
    if (idx >= s.size())
    {
        for (char ch : temp)
        {
            cout << ch;
        }
        if (temp.size() == 0)
        {
            cout <<"empty";
        }
        cout << " ";
        return;
    }
    temp.push_back(s[idx]);
    strSubsequence(idx+1 , temp , s);
    temp.pop_back();
    strSubsequence(idx+1, temp , s);
}

int main()
{
    vector<int> ans;
    int arr[] = {3, 1, 2};
    printSubsequence(0, ans, arr);
    cout<<endl;
    string s = "abc";
    strSubsequence(0,"",s);
}