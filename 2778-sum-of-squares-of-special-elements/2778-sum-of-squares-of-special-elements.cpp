class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(n%(i+1) == 0){
                int x = nums[i]*nums[i];
                sum += x;
            }
        }
        return sum;
    }
};