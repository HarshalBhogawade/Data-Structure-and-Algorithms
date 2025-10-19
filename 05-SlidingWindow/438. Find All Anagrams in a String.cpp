#include <bits/stdc++.h>
using namespace std;


//tc : o(N) Sc : O(N) for hashmap not considered answer vector
vector<int> findAnagrams(string s, string p)
{
    unordered_map<int, int> mp; //will store occured letters in p with freq
    vector<int> ans;
    for (char ch : p)
    {
        mp[ch]++;
    }
    int cnt = mp.size();    //count of uniques
    int i = 0;
    int j = 0;
    int k = p.size();   //size of required window
    while (j < s.size())
    {
        if (mp.find(s[j]) != mp.end())
        {   //if j present in mp then decrease its count  , if freq = 0 ,cnt--    
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                cnt--;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {   
            if (cnt == 0)
            {   //cnt becomes zero means current is the anagram of p
                ans.push_back(i);
            }
            if (mp.find(s[i]) != mp.end())
            {   //again set the count to original and freq also
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    cnt++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> a = findAnagrams(s, p);
}