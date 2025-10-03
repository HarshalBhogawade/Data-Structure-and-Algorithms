#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = INT_MIN;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>buy){
                profit = max(profit , prices[i]-buy);
            }
            else if(buy > prices[i]){
                buy = prices[i];
            }
        }
        if(profit <=0) return 0;
        return profit;
}
int main(){
    vector<int>nums = {7,1,5,3,6,4};
    int maxprofit = maxProfit(nums);
    cout<<"Max Profit : "<<maxprofit<<endl;
    return 0;
}