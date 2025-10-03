#include<bits/stdc++.h>
using namespace std;
/*  Time complexity : O(N) 
    SC : O(1)
    Approach :: 
    We just have to find the maxarea of rectangle 
    indexes are used for calculating width between boreder or walls of container
    height of each border is determined by value at each index
    using opposite pointers to solve*/
int maxArea(vector<int>& height) {
        int hei = 0;
        int width = 0;
        int area = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<=right){
            hei = min(height[left] , height[right]);    //gets minimum height of wall as water will be this level
            width = right-left; //calculates width of contianer
            area = max(area , hei*width);   //AREA OF container ie water 

            if(height[left]<height[right]){ //we do this because we may find the wall with more heigh then current
                left++;
            }else right--;
        }
        return area;
}

int main(){
    vector<int>nums = {1,8,6,2,5,4,8,3,7};
    int area = maxArea(nums);
    cout<<"Container with most water : "<<area<<endl;
    return 0;
}