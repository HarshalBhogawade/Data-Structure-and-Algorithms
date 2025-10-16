#include<bits/stdc++.h>
using namespace std;
void interchange(vector<vector<int>>&mat){
    //exchanging elements of the first and the last columns of matrix
    int n = 0;//initialized to row zero will traverse all rows
    int m = 0;//first column selected
    int k = mat[0].size()-1;
    while(n<mat.size()){
        swap(mat[n][m],mat[n][k]);
        n++;
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
    interchange(mat);
    print(mat);

}