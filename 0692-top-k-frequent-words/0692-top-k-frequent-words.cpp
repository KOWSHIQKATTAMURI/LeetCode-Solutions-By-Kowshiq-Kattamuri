class Solution {
public:
     static bool compare(pair<int, string> &a, pair<int, string> &b){
        if(a.first > b.first){
            return true;
        }
        if(a.first < b.first){
            return false;
        }
        if(a.second < b.second){
            return true;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k){
        unordered_map<string, int> kow;
        vector<string> ans;
        for(auto word : words){
            kow[word]++;
        }
        vector<pair<int, string>> x;
        for(auto it : kow){
            x.push_back({it.second, it.first});
        }
        sort(x.begin(), x.end(), compare);
        for(int i = 0; i < k; i++){
            ans.push_back(x[i].second);
        }
        return ans;
    }
};