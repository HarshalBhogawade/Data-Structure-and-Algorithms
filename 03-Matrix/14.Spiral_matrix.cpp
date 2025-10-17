#include<bits/stdc++.h>
using namespace std;

//tc : O(n^2) sc o1
vector<int> spiralmatrix(vector<vector<int>>mat){
    //four pointer approach : all pointes will move inward 
    int n = mat.size();
    int m = mat[0].size();
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;

    vector<int>ans; //spirally elements

    while(left<=right && top<=bottom){
        //left to right traversal
        for(int i = left; i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++; // for next traversal

        //top to bottom traversal
        for(int i = top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;    //move inward from right
        
        //right to left traversal
        if(top<=bottom){
            for(int i = right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i = bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int>ans = spiralmatrix(mat);
    for(auto num : ans){
        cout<<num<<" ";
    }

}