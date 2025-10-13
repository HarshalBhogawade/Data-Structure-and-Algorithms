#include<bits/stdc++.h>
using namespace std;

//rotates clockwise
vector<vector<int>> rotateclockwise(vector<vector<int>>mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>res(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[j][n-i-1] = mat[i][j];
        }
    }
    return res;
}

//rotates anticlock wise
vector<vector<int>> rotateanticlockwise(vector<vector<int>>mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>res(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[m-j-1][i] = mat[i][j];
        }
    }
    return res;
}



int main(){
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // vector<vector<int>> res = rotateclockwise(mat);
    // for(auto &row : res){
    //     for(auto &num : row){
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>>res = rotateanticlockwise(mat);
    for(auto &row : res){
        for(auto &num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}