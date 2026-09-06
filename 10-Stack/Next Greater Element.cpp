#include<bits/stdc++.h>
using namespace std;

// Function to find Next Greater Element to the right
vector<int> nextLargerElement(vector<int> &arr)
{
    stack<int> st;          // monotonic stack (stores potential NGE values)
    int n = arr.size();

    vector<int> ans(n);     // result array

    // traverse from right → left
    for(int i = n - 1; i >= 0; i--)
    {
        // remove all elements smaller or equal to current
        // because they cannot be next greater
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        // if stack empty → no greater element on right
        if(st.empty()){
            ans[i] = -1;
        } else {
            ans[i] = st.top(); // next greater element
        }

        // push current element for future comparisons
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {6, 8, 0, 1, 3};

    vector<int> ans = nextLargerElement(nums);

    for(int num : ans){
        cout << num << " ";
    }

    return 0;
}