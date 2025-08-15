class Solution {
public:

    
    int maxArea(vector<int>& height) {
        // int n = height.size();
        // int hei =0;
        // int width =0;
        // int area = INT_MIN;
        // int left =0;
        // int right = n-1;
        // while(left<right){
        //     hei = min(height[left],height[right]);
        //     width = right - left;
        //     area = max(area,hei*width);
        //     if(height[left]<height[right]){
        //         left++;
        //     }else{
        //         right--;
        //     }
        // }
        // return area;      

        int hei = 0;
        int width = 0;
        int left = 0;
        int right = height.size()-1;
        int area = INT_MIN;
        while(left<right){
            hei  = min(height[left],height[right]);
            width = right- left;
            area =max(area , width*hei);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;
    }
};
