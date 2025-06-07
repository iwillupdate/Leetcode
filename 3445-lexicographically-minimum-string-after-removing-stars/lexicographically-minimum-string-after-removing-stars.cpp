class Solution {
private:
    struct Compare{
        bool operator()(const pair<char,int>&a , const pair <char,int>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
public:
    string clearStars(string s) {
        int n=s.size();
        priority_queue<char,vector<char> , greater<char>> pq;
        vector<vector<int>>indices(26);
        for(int i=0;i<n;i++){
            if(s[i] =='*'){
                char ch=pq.top();
                s[indices[ch-'a'].back()]='!';
                indices[ch-'a'].pop_back();
                if(indices[ch-'a'].empty()) pq.pop();
                continue;
            }
            if(indices[s[i]-'a'].empty()) pq.push(s[i]);
            indices[s[i]-'a'].push_back(i);
        }
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]>='a') res+=s[i];
        }
        return res;
        
    }
};