class Solution {
public:
    int dfs(unordered_map<string,vector<string>>& kow, const string& s, set<string>& visited) {
        int res = 0;
        visited.insert(s);
        for(const string& coord : kow[s]){
            if(visited.find(coord + s) != visited.end() || visited.find(s + coord) != visited.end()){
                continue;
            }
            visited.insert(coord + s);
            visited.insert(s + coord);
            res += dfs(kow, coord, visited) + 1;
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones){
        unordered_map<string,vector<string>> kow;
        set<string> visited;
        for (int i = 0; i < stones.size(); i++) {
            string r = "r" + to_string(stones[i][1]), c = "c" + to_string(stones[i][0]);
            kow[r].push_back(c);
            kow[c].push_back(r);
        }
        int res = 0;
        for(const auto& p : kow){
            if(visited.find(p.first) != visited.end()){
                continue;
            }
            res += dfs(kow, p.first, visited) - 1;
        }
        return res;  
    }
};