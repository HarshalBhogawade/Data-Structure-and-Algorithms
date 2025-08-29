#include <bits/stdc++.h>
using namespace std;

    //TC : O(N.m) m = for neg SC : O(N)
vector<int> firstNegInt(vector<int> &arr, int k)
{
    // write code here
    vector<int> ans; // stores final ans ie first negatives
    vector<int> neg; // will store only occured negative num
    int i = 0, j = 0;
    while (j < arr.size())
    {
        if (arr[j] < 0)
        { // push the negative
            neg.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (!neg.empty())
            { // if not empty push front in answer
                ans.push_back(neg.front());
                if (arr[i] == neg.front())
                { // this condition checks if current windows first elemt is equal to negfront , potential neg condition
                    neg.erase(neg.begin());
                }
            }
            else
            { // if neg empty then push 0 as no first negative
                ans.push_back(0);
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> num = firstNegInt(nums, k);
    for (int n : num)
    {
        cout << n << " ";
    }
    return 0;
}