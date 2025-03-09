class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int prev = -1, start = 0, n = colors.size();
        int ans = 0;
        for(int i = 0; i < colors.size() + k - 1; i++)
        {
            if(colors[i % n] != prev)
            {
                if(i - start == k - 1)
                {
                    ans++;
                    start++;
                }
            }
            else
                start = i;
            prev = colors[i % n];
        }
        return ans;
    }
};