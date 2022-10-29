class Solution {
public:
    static bool compare(pair<int, int>&a, pair<int, int>&b){
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime){
        vector<pair<int, int>> kow(plantTime.size());
        for(int i = 0; i < plantTime.size(); i++){
            kow.push_back({plantTime[i], growTime[i]});
        }
        sort(kow.begin(), kow.end(), compare);
        int total = 0, start = 0;
        for(int i = 0; i < kow.size(); i++){
            start += kow[i].first;
            total = max(total, start + kow[i].second);
        }
        return total;
    }
};