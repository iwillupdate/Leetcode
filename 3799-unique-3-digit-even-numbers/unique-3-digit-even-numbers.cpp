class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<bool> first(10, false);
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] == 0 || first[digits[i]])
                continue;
            first[digits[i]] = true;
            vector<bool> second(10, false);
            for(int j = 0; j < digits.size(); j++)
            {
                if(i == j || second[digits[j]])
                    continue;
                second[digits[j]] = true;
                vector<bool> third(10, false);
                for(int k = 0; k < digits.size(); k++)
                {
                    if(i == k || j == k || third[digits[k]])
                        continue;
                    third[digits[k]] = true;
                    if(digits[k] % 2 == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};