class Solution {
public:
    int bfs(vector<vector<pair<int, int>>> &graph, int src, int &seg, vector<int>& vis)
    {
        //cout << endl;
        //vis[src] = seg;
        queue<int> to_visit;
        to_visit.push(src);
        int ans = INT_MAX;
        while(to_visit.size())
        {
            int curr = to_visit.front();
            to_visit.pop();
            if(vis[curr])
                continue;
            vis[curr] = seg;
            for(auto x : graph[curr])
            {
                if(vis[x.first] == 0)
                {
                    ans &= x.second;
                    //cout << curr << " " << x.first << " " << ans << endl;
                    to_visit.push(x.first);
                }
            }
        }
        return ans;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, int> seg_to_val;
        int seg = 1;
        //int n = edges.size();
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                seg_to_val[seg] = bfs(graph, i, seg, vis);
                seg++;
            }
            //cout << i << " " << seg - 1 << " " << seg_to_val[seg - 1] << endl;
        }
        vector<int> ans(query.size());
        for(int i = 0; i < query.size(); i++)
        {
            if(vis[query[i][0]] == vis[query[i][1]])
                ans[i] = seg_to_val[vis[query[i][0]]];
            else
                ans[i] = -1;
        }
        return ans;
    }
};