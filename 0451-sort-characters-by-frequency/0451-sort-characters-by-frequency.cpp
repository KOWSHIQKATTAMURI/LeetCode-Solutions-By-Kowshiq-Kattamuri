class Solution {
public:
    string frequencySort(string s){
        map<char, int> x;
        multimap<int, char> kow;
        for(int i = 0; i < s.length(); i++){
            x[s[i]]++;
        }
        for(auto it : x){
            kow.insert(make_pair(it.second, it.first));
        }
        string ans;
        for(auto it : kow){
            ans.append(it.first, it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};