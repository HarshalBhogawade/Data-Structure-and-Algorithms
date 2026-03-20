#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // queue will store: {{row, col}, distance}
        queue<pair<pair<int,int>,int>> q;

        // ans acts as both result + visited array (-1 means unvisited)
        vector<vector<int>> ans(n, vector<int>(m, -1));

        // Step 1: push all 0s into queue (multi-source BFS)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    ans[i][j] = 0; // distance of 0 from nearest 0 is 0
                }
            }
        }

        // directions: up, right, down, left
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};

        // Step 2: BFS
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            // explore 4 neighbors
            for(int k = 0; k < 4; k++){
                int rrow = i + nrow[k];
                int ccol = j + ncol[k];

                // valid cell check
                if(rrow >= 0 && rrow < n && ccol >= 0 && ccol < m){

                    // if not visited yet
                    if(ans[rrow][ccol] == -1){
                        ans[rrow][ccol] = dist + 1;   // assign shortest distance
                        q.push({{rrow, ccol}, dist + 1}); // push for further expansion
                    }
                }
            }
        }

        return ans;
}
int main(){

}