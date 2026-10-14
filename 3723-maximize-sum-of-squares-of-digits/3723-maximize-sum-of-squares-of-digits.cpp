class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        string res = "";
        while(num){
            if(sum < 9){
                res += to_string(sum);
                sum -= sum;
                num--;
            }
            else{
                res += '9';
                sum = sum-9;
                num--;
            }
        }
        return res;
    }
};