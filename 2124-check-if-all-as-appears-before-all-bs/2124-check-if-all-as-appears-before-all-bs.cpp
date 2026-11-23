class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        bool flag1 = false;
        for(int i=0; i<n; i++){
            if(s[i] == 'a' && flag1 == true){
                return false;
            } 
            if(s[i] == 'b') flag1 = true;
        }
        return true;
    }
};