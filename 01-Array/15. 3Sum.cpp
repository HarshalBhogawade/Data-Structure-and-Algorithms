#include<bits/stdc++.h>
using namespace std;
void threesum(vector<int>& nums){
    int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate values of i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers
                    j++;
                    k--;

                    // Skip duplicate j values
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate k values
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }

                }
                else if (sum > 0) {

                    // Sum is too large, decrease k
                    k--;

                }
                else {

                    // Sum is too small, increase j
                    j++;
                }
            }
        }

    //final answer
    for(vector row : ans){
        for(int it : row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    threesum(nums);

}
