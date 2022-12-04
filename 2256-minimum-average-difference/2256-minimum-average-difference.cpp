class Solution {
public:
    int minimumAverageDifference(vector<int>& nums){
        if(nums.size() == 1 and nums[0] == 0){
            return 0;
        }
        vector<long long int> prefix(nums.size()), suffix(nums.size());
        prefix[0] = nums[0], suffix[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + (long long int)nums[i];
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] + (long long int)nums[i];
        }
        int ans = INT_MAX, index = INT_MIN;
        long long int a, b, i = 0;
        while(i < nums.size()){
            if(i == nums.size() - 1){
                a = prefix[i]/(i + 1);
                if(ans > a){
                    ans = a;
                    if(i > index){
                        index = i;
                    }
                }
            }else{
                a = prefix[i]/(i + 1);
                b = suffix[i + 1]/(nums.size() - (i + 1));
                if(ans > abs(a - b)){
                    ans = abs(a - b);
                    if(i > index){
                        index = i;
                    }
                }
            }
            i++;
        }
        return index;
    }
};