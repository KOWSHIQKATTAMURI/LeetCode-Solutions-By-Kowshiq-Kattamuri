class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> kow;
        for(auto st : strs){
            string str = st;
            sort(str.begin(), str.end());
            kow[str].push_back(st);
        }
        vector<vector<string>> res;
        for(auto it : kow){
            res.push_back(it.second);
        }
        return res;
    }
};