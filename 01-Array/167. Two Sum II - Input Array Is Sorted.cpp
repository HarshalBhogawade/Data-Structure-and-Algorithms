#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0;
        int right = numbers.size()-1;
        while(left<=right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1,right+1};
            }
            else if(sum>target){
                right--;
            }else{
                left++;
            }
        }
        return {-1,-1};
    }
int main(){
    vector<int>numbers = {1,2,3,4,5,6,7};
    int target = 10;
    twoSum(numbers,target);
    return 0;
}