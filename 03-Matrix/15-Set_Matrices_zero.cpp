#include<bits/stdc++.h>
using namespace std;

//tc : O(2 O^2 + 2N ) equals O^2 
//sc : O(1);
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // int col[m] = {0}; -> matrix[0][..]
        // int row[m] = {0}; -> matrox[..][0];
        int col0 = 1;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]==0){
                    //mark the i-th row
                    matrix[i][0] = 0;
                    //mark the j-th row
                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j]!=0){
                    //check for col and row
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        //for oth row
        if(matrix[0][0]==0){
            for(int j = 0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        //for zeroth col
        if(col0 == 0){
            for(int i = 0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
int main(){
    vector<vector<int>>mat={{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(mat);
    for(auto num : mat){
        for(auto it : num){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
