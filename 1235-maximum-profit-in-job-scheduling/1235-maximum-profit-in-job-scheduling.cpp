class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size(), ans = 0;
        vector<vector<int>> kow;
        for(int i = 0; i < n; i++){
            kow.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(kow.begin(), kow.end());
        map<int, int> x;
        for(int i = n - 1; i >= 0; i--){
            int tmp = kow[i][2];
            auto it = x.lower_bound(kow[i][1]);
            if(it != x.end()){
                tmp += it->second;
            }
            ans = max(ans, tmp);
            x[kow[i][0]] = ans;
        }
        return ans;
    }
};