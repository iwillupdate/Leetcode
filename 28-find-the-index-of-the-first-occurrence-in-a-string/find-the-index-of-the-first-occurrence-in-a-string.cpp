class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) return 0; //needle empty

        vector<int> lps = findLPS(needle);

        int i = 0, j = 0; // Pointers for haystack and needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == m) 
                    return i - j; 
            } 
            else {
                //if mismatch occurs
                if (j > 0) {
                    //LPS[i] tells me the longest proper prefix of needle[0:i] that is also a suffix.
                    j = lps[j - 1]; 
                } 
                else {
                    i++; 
                }
            }
        }
        return -1; 
    }

private:
    vector<int> findLPS(string needle) {
        int m = needle.length();
        int len = 0;

        vector<int> lps(m, 0);

        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1]; // Move len using LPS array
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

//brute force = O(n*m) -> compare each character one by one , if mismatch occur , start from next index



//build longest prefix sum=O(m)
//search in haystack = O(n)
//TC= O(m+n)
