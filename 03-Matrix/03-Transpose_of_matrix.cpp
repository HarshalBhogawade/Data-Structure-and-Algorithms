#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>> &mat){
    int r = mat.size();
    int c = mat[0].size();
    if(r!=c) return;
    for(int i=0;i<r;i++){
        for(int j = i+1;j<c;j++){
            
            swap(mat[i][j],mat[j][i]);
            
        }
    }
}
int main(){
    vector<vector<int>>mat = { {1,2,3} , { 2,3,4}, { 6,5,7}};
    transpose(mat);
    //output
    for(auto & row : mat){
        for(auto &elem : row){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
}