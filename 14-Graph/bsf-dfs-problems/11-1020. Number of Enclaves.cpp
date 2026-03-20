#include<bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        //store the boundry ones and mark true
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j== m-1){
                    if(grid[i][j]==1){
                        grid[i][j] = -1;
                        q.push({i,j});
                       
                    }
                }
            }
        }

        int rowArr[] = {-1,0,+1,0};
        int colArr[] = {0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + rowArr[i];
                int ncol = col + colArr[i];

                if(nrow >=0 && nrow < n && ncol < m && ncol >=0 && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] =-1;              
                    q.push({nrow,ncol});   
                }
            }
        }

        //count the ones which are not marked -1 or 0
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
}
int main(){

}