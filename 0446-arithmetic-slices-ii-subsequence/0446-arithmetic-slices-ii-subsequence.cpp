class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums){
        long long x = 0, i, j, n = nums.size(), d;
        vector <unordered_map<long, long>> kow(n);
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                d = (long)nums[i] - (long)nums[j];
                kow[i][d] += kow[j][d] + 1;
                x += kow[j][d];
            }
        }
        return x;
    }
};