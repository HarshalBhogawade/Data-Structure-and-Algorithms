#include<bits/stdc++.h>
using namespace std;
//TC : O(N^2) Sc : O(N) for storing the answer of addition
void matrixaddition(vector<vector<int>>&mat1 , vector<vector<int>>&mat2 , vector<vector<int>>&ans){
    int n = mat1.size();
    int m = mat1[0].size();
    for(int i= 0 ;i<n;i++){
        for(int j = 0;j<m;j++){
            ans[i][j]=mat1[i][j] + mat2[i][j];
        }
    }
}

//optimization  : can add result itself in mat1 or mat2 to save extra space


int main(){
    vector<vector<int>>A = {{1,2},{3,4}};
    vector<vector<int>>B = {{3,6},{1,9}};
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>>C(n,vector<int>(m));
    matrixaddition(A,B,C);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}