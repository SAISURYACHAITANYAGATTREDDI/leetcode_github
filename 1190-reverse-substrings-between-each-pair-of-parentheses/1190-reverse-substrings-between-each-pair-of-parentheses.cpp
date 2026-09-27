class Solution {
public:
    void reversestring(string &s, int i, int j){
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int left = st.top() + 1;
                st.pop();
                int right = i-1;
                reversestring(s, left, right);
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == ')') continue;
            else ans += s[i];
        }
        return ans;
    }
};