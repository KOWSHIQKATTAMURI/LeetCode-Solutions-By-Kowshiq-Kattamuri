class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> kow;
        unordered_set<int> x;
        for(int n : arr){
            kow[n]++;
        }
        for(auto& c : kow){
             x.insert(c.second);   
        }
        return kow.size() == x.size();
    }
};