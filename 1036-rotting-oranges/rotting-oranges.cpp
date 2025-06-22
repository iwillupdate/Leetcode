class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int cntfresh=0;
        int m=grid.size();
        int n=grid[0].size();
        // Queue for BFS: har entry mein (row, col) aur us waqt ka time hoga
        queue<pair<pair<int,int>,int>>q;
        // Grid ko traverse karke rotten aur fresh oranges dhundhna
        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1) cntfresh++;
                else if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        // 4 direction ke liye row aur column change arrays
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;// kitne fresh oranges rotten banaye gaye
        int tm=0;// maximum time taken to rot all reachable fresh oranges

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            tm=max(tm,time);
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=row+drow[i];
                int newcol=col+dcol[i];
                // Agar naya cell valid hai aur fresh orange mila toh
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]==1){
                    q.push({{newrow,newcol},time+1});
                    grid[newrow][newcol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) return -1;
        else return tm;


        
    }
};