#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &arr, int k)
{
    // code here
    int i = 0;
    int j = 0;
    int n = arr.size();
    int sum = 0;
    int maxm = INT_MIN;
    while (j < n)       //till end of array
    {
        sum += arr[j];      //store sum as moving ahead
        if (j - i + 1 < k)  
        {
            j++;
        }
        else if (j - i + 1 == k)    //window size becomes == k size window do operations
        {
            maxm = max(maxm, sum);  //storing max sum
            sum -= arr[i];          //to move window ahead remove previous element from total sum 
            i++;                    // move ahead from back
            j++;                    //move ahead fromt
        }
    }
    return maxm;
}
int main() {
    vector<int>arr={1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k= 4;
    cout<<"Max subarray sum: "<<maxSubarraySum(arr,k)<<endl;
}