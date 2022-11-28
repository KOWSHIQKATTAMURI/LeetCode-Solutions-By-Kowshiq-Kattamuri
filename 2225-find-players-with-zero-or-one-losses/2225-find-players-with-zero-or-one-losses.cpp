class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, loss;
        vector<vector<int>> kow;
        for(int i = 0; i < matches.size(); i++){
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }
        vector<int> winners, loosers;
        for(auto it : win){
            if(loss.find(it.first) == loss.end()){
                winners.push_back(it.first);
            }
        }
        kow.push_back(winners);
        for(auto it : loss){
            if(it.second == 1){
                loosers.push_back(it.first);
            }
        }
        kow.push_back(loosers);
        return kow;
    }
};