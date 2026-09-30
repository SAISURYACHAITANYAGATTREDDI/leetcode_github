class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                ans.push_back(cnt%2);
                cnt++;
            }
            else if(seq[i] == ')'){
                cnt--;
                ans.push_back(cnt%2);
            }
        }
        return ans;
    }
};