#include<bits/stdc++.h>
using namespace std;

//main key to solve matrix with optimized way is to find a formula to make changes
void revcols(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    for(int j=0;j<m;j++){
        for(int i=0;i<n/2;i++){
            
            swap(mat[i][j],mat[n-1-i][j]);
        }
    }
}

void print(vector<vector<int>>mat){
    for(auto & row : mat){
        for(auto & num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>>mat = {{8,9,7,6},{4,7,6,5},{3,2,1,8},{9,9,7,7}};
    revcols(mat);
    print(mat);

}


