#include <bits/stdc++.h>
using namespace std;
// return no of unique palindromes(reads the same forwards and backwards) of length 3 that are subsequences of s
// xAx coz only 3 length
// brute tc O(n^3) sc O(2N)
int brutepalindromesubsequence(string s)
{
    unordered_set<string> st; // push in set to avoid duplicates
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i]; // get left char
        for (int j = i + 1; j < n; j++)
        {
            char ch2 = s[j]; // say this is mid
            for (int k = j + 1; k < n; k++)
            {
                char ch3 = s[k]; // tis is right char

                if (ch1 == ch3)
                {
                    string temp = "";
                    temp.push_back(ch1);
                    temp.push_back(ch2);
                    temp.push_back(ch3);
                    st.insert(temp);
                }
            }
        }
    }
    return st.size(); // returns unique palindromes count
}

// better in O(N^2) complexity
// build left array store char to 0 to mid-1 and right array stores char mid+1 to n
int betterpalindrome(string s)
{
    int n = s.size();
    unordered_set<string> st; // avoid dupli
    for (int i = 0; i < n; i++)
    {
        int mid = i;
        vector<int> left(26, 0);  // stores left chars to mid
        vector<int> right(26, 0); // stores right chars to mid
        for (int j = 0; j < mid; j++)
        {
            left[s[j] - 'a']++;
        }

        for (int k = mid + 1; k < n; k++)
        {
            right[s[k] - 'a']++;
        }

        for (int ch = 0; ch < 26; ch++)
        {
            if (left[ch] > 0 && right[ch] > 0)
            {
                char x = 'a' + ch;
                string temp = "";
                temp.push_back(x);
                temp.push_back(s[mid]);
                temp.push_back(x);
                st.insert(temp);
            }
        }
    }
    return st.size();
}

// optimal approach
// complexity : O(26 * N) => O(N)
int optimalpalindrome(string s)
{
    unordered_set<string> st;
    // use 2 arrays to track elements

    vector<int> right(26, 0);
    vector<int> left(26, 0);
    // Build the `right` array

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']++;
    }
    // Build the `left` array and calculate palindromes

    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']--;
        // Check palindromes of the form xAx

        for (int ch = 0; ch < 26; ch++)
        {
            if (left[ch] > 0 && right[ch] > 0)
            {
                char x = 'a' + ch;
                string temp = "";
                temp.push_back(x);
                temp.push_back(s[i]);
                temp.push_back(x);
                st.insert(temp);
            }
        }
        left[s[i] - 'a']++;
    }
    return st.size();
}
int main()
{

    string s = "aabca";
    cout << "NO of pali subsequences: " << brutepalindromesubsequence(s) << endl;
    cout << "No of pali subs: " << betterpalindrome(s) << endl;
    cout << "No of pali subs : " << optimalpalindrome(s);
}