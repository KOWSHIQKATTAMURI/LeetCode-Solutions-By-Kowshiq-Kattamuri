class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        vector<int> kow(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            kow[nums[i]]++;
        }
        int dup = 0, miss = 0;
        for(int i = 1; i < kow.size(); i++){
            if(kow[i] == 0){
                miss = i;
            }
            if(kow[i] >  1){
                dup = i;
            }
        }
        return {dup, miss};
    }
};