#include<iostream>
#include<vector>
using namespace std;

int missingnumber(vector<int>nums){

    int n = nums.size();
    int xor1 = 0,xor2=0;
    for(int it:nums){
        xor1 ^= it;
    }
    for(int i=1;i<=n;i++){
        xor2 ^= i;
    }
    return xor1^xor2;
}

// Sum method: sum of 0 to n minus the sum of the given elements.
int missingnumberSum(vector<int> nums){
    long long n = nums.size();
    long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;

    for(int it : nums){
        actualSum += it;
    }

    return static_cast<int>(expectedSum - actualSum);
}

int main(){
    vector<int>nums = {9,6,4,2,3,5,7,0,1};
    int xorNum = missingnumber(nums);
    int sumNum = missingnumberSum(nums);

    cout<<"Missing number using XOR method : "<<xorNum<<endl;
    cout<<"Missing number using Sum method : "<<sumNum;
    return 0;
}
