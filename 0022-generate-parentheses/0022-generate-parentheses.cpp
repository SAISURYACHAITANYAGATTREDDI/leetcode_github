class Solution {
public:
    void solve(int n, int left, int right, vector<string> &ans, string s){
        if(left > n || right > n || left < right) return;
        if(left == n && right == n){
            ans.push_back(s);
            return;
        }
        solve(n, left+1, right, ans, s+'(');
        solve(n, left, right+1, ans, s+')');
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        solve(n, 0, 0, ans, s);
        return ans;
    }
};