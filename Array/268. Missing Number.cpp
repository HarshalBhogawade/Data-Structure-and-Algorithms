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
int main(){
    vector<int>nums = {9,6,4,2,3,5,7,0,1};
    int num = missingnumber(nums);
    cout<<"Missing number is :"<<num;
    return 0;
}