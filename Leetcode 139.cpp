/* 
139 - Word Break
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.size() + 1;
        
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = i -1; j >= 0; --j) {
                if(dp[j]) {
                    string str = s.substr(j, i - j);
                    if(find(dict.begin(), dict.end(), str) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
