class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        vector<int> result;
        int j = 0, index = 0;
        for(int i = 0; i < s.size(); ++i) 
            last[s[i] - 'a'] = i;
        
         for(int i = 0; i < s.size(); ++i) {
             char c = s[i];
             index = max(index,last[c - 'a']);
             if(i == index) {
                 result.push_back(index - j + 1);
                 j = i+1;
             }
         }
        return result;
    }
};
