class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            string next = "";
            
            for (int i = 0; i < (int)s.size(); i += k) {
                int sum = 0;
                int end = i + k;
                if (end > (int)s.size()) end = (int)s.size();
                
                for (int j = i; j < end; j++) {
                    sum += s[j] - '0';
                }
                
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};