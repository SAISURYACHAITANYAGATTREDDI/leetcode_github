class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n = n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int x = digitsum(nums[i]);
            if(x == i) return i;
        }
        return -1;
    }
};