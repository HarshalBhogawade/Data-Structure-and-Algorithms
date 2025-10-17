#include<bits/stdc++.h>
using namespace std;

//tc: O(4N) no space required
vector<int> boundry(vector<vector<int>>mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int>ans;
    //1) traverse from l to r first row only index 0
    for(int j = 0;j<m;j++){
        ans.push_back(mat[0][j]);
    } 

    //2)traverse from second row to last row in last column as we getting only boundry elems
    for(int i = 1;i<n;i++){
        ans.push_back(mat[i][m-1]);
    }

    //3) traverse last row from right to left from second column 
    for(int j = m-2;j>=0;j--){
        ans.push_back(mat[n-1][j]);
    }
    
    //4) traverse from bottom to top in first column // 0 th row boundry and last row boundry already included
    for(int i = n-2;i>0;i--){
        ans.push_back(mat[i][0]);
    }

    return ans;

}

int main(){

    vector<vector<int>>mat = {{1,2,3,4} , {5,6,7,8} ,{9,10,11,12} };
    vector<int>ans = boundry(mat);
    for(int num : ans){
        cout<<num<<" ";
    }

    return 0;

}