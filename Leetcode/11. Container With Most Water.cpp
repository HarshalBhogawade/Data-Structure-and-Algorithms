#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
        int hei = 0;
        int width = 0;
        int area = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<=right){
            hei = min(height[left] , height[right]);
            width = right-left;
            area = max(area , hei*width);

            if(height[left]<height[right]){
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