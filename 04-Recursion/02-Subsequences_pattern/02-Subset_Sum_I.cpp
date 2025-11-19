#include <bits/stdc++.h>
using namespace std;
//compleixty O(N*2^N)
void subset_sum(int idx, vector<int> temp, vector<int> arr)
{
    int sum = 0;
    if (idx >= arr.size())
    {
        for (int i = 0; i < temp.size(); i++)
        {
            sum += temp[i];
        }
        cout << sum << " ";
        return;
    }

    temp.push_back(arr[idx]);
    subset_sum(idx + 1, temp, arr);
    temp.pop_back();
    subset_sum(idx + 1, temp, arr);
}

// little optimized by not recalculating sum every time ,
// instead passed a currsnetsum var
// tc depends on no of nodes , while sc depends on depth of recusrion tree
//optimized compleixy : O(2^N) Auxillary space : O(N) 
void subset2(int idx, int currsum, vector<int> &ans, vector<int> &arr)
{

    if (idx >= arr.size())
    {
        ans.push_back(currsum);
        return;
    }

    //take mean add curr idx elem to currsum
    subset2(idx + 1, currsum + arr[idx], ans, arr);
    //not take mean dont add current elem to sum variable
    subset2(idx + 1, currsum, ans, arr);
}
vector<int> subsetSums(vector<int> &arr)
{
    // code here
    vector<int> sum;
    subset2(0, 0, sum, arr);
    return sum;
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> temp;
    subset_sum(0, temp, arr);
}