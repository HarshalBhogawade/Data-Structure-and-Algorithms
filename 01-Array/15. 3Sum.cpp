#include<bits/stdc++.h>
using namespace std;
void threesum(vector<int>& nums){
    int n= nums.size();
    
    vector<vector<int>>ans;     //STORING THE RESULT

    sort(nums.begin(),nums.end());

    //move i ahead if j crosses k
    for(int i=0;i<n;i++){
        
        //for same value of i keep moving it
        if(i>0 && nums[i]==nums[i-1]){
            continue;  //do i++
        }
        
        int j= i+1;
        int k = n-1;
        
        while(j<k){
            //doing sum of current index elements
            int sum = nums[i]+nums[j]+nums[k];

            if(sum==0){
                //adds answer to ans
                ans.push_back({nums[i],nums[j],nums[k]});
            }else if (sum>0){
                k--;
            }else{
                j++;
            }

            //if duplicate value then move ahead , as next combination for zero may miss
            while(j<k && nums[j]==nums[j+1]){
                j++;
            }

            //same here
            while(j<k && nums[k]==nums[k-1]){
                k--;
            }

            j++;
            k--;
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
