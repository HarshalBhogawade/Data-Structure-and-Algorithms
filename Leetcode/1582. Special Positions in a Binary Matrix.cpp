#include<bits/stdc++.h>
using namespace std;
//uses two pointer to check if left right top left have one 
    //if one return false
    //else travel till end and return false
    bool checkClear(vector<vector<int>>& mat, int i,int j, int rowSize, int colSize){
        int m = i;
        int n = 0; 
        int countOne = 0;

        //check left and right
        while(m<rowSize && n<colSize){
            if(mat[m][n]==1) countOne++;
            if(countOne == 2){
                return false;
            }
            n++;
        }

        //check top and bottom
        m = 0;
        n=j;
        countOne = 0;
        while(m<rowSize && n<colSize){
            if(mat[m][n]==1) countOne++;
            if(countOne == 2){
                return false;
            }
            m++;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;

        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    bool isClear = checkClear(mat,i,j,mat.size(),mat[i].size());
                    if(isClear){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
}
int main(){

}