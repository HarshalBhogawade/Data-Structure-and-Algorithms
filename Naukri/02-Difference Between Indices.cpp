/*Problem statement
You are given an array ‘arr’ of size ‘N’. You have to find two indices, ‘i’ and ‘j’, such that arr[j] > arr[i] and the difference between ‘j’ and ‘i’ is maximized. If there are no two indices such that arr[j] > arr[i] then return -1.

For example:
Consider arr =[1, 2, 3, 4, 5], we can take indices i = 0, and j = 4, so difference is 4 - 0 = 4, and arr[4] > arr[0]. Hence the answer is 4.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10 
1 <= N <= 10 ^ 6
1<= arr[i] <= 10 ^ 9 */
#include<bits/stdc++.h>
using namespace std;
int maxIndexDiff(vector<int> &arr, int n)
{
    vector<int>pre(n);
    vector<int>suff(n);
    pre[0]=arr[0];
    suff[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        pre[i]=min(arr[i],pre[i-1]);
    }

    for(int i=n-2;i>=0;i--){
        suff[i]=max(arr[i],suff[i+1]);
    }

    int ans =-1;
    int i=0,j=0;
    while(i<n && j<n){
        if(suff[j]>pre[i]){

            ans = max(ans,j-i);
            j++;
        }else{
            i++;
        }
    }
    return ans;
}
int main(){
    vector<int>nums={1, 2, 3, 4, 5};
    cout<<maxIndexDiff(nums,5);
}