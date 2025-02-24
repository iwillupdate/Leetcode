class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> max_ele;
        for(int i = 0; i < m; i++)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int j = 0; j < n; j++)
            {
                if(pq.size() < limits[i])
                    pq.push(grid[i][j]);
                else if(pq.size() > 0 && pq.top() < grid[i][j])
                {
                    pq.pop();
                    pq.push(grid[i][j]);
                }
            }
            int curr_size = pq.size();
            for(int i = 0; i < curr_size; i++)
            {
                //cout << pq.top() << " ";
                max_ele.push_back(pq.top());
                pq.pop();
            }  
        } 
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        for(int i = 0; i < max_ele.size(); i++)
        {
            if(pq.size() < k)
                pq.push(max_ele[i]);
            else if(pq.size() > 0 && pq.top() < max_ele[i])
            {
                pq.pop();
                pq.push(max_ele[i]);
            }
        }
        int curr_size = pq.size();
        for(int i = 0; i < curr_size; i++)
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};