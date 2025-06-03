class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool>vis(n,false);
        for(int v:initialBoxes){
            dfs(v,status,keys,containedBoxes,vis);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]&&status[i]==1){
                cnt+=candies[i];
            }
        }
        return cnt;
    }
    void dfs(int v,vector<int>&status,vector<vector<int>>&keys,vector<vector<int>>&containedBoxes,vector<bool>&vis){
        vis[v]=true;
        for(int vKey:keys[v]){
            if(vKey==v) continue;
            status[vKey]=1;
        }
        for(int vContained:containedBoxes[v]){
            if(!vis[vContained]){
                dfs(vContained,status,keys,containedBoxes,vis);
            }
        }
    }
};