#include <bits/stdc++.h>
using namespace std;

    //TC : O(N) SC : O(1)
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int i = 0, j = 0;
    int n = arr.size();
    int sum = 0;
    int avg = 0;
    int cnt = 0;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        { // window size = j-i+1 this is formmula
            j++;
        }
        else if (j - i + 1 == k)
        {
            avg = sum / k;
            if (avg >= threshold)
            { // checks if avg greater than or equal to the threshold
                cnt++;
            }
            sum -= arr[i]; // remove num from back
            i++;           // move window from back
            j++;           // move window from front
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int thres = 4;
    cout << "ANs :" << numOfSubarrays(nums, k, thres);
}