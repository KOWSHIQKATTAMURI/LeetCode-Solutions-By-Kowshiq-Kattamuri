class Solution {
public:
    vector<string> find(string s){
        vector<string> finalise;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            s[i] = 'A';
            finalise.push_back(s);
            s[i] = 'T';
            finalise.push_back(s);
            s[i] = 'G';
            finalise.push_back(s);
            s[i] = 'C';
            finalise.push_back(s);
            s[i] = ch;
        }
        return finalise;
    }
    int minMutation(string start, string end, vector<string>& bank){
        map<string, int> kow;
        for(int i = 0; i < bank.size(); i++){
            kow[bank[i]] = -1;
        }
        queue<pair<string, int>> q;
        q.push({start, 0});
        kow[start] = 1;
        while(!q.empty()){
            pair<string, int> temp = q.front();
            q.pop();
            string s = temp.first;
            int x = temp.second;
            if(s == end){
                return x;
            }
            vector<string> checkers = find(s);
            for(int i = 0; i < checkers.size(); i++){
                if(kow[checkers[i]] == -1){
                    kow[checkers[i]] = 1;
                    q.push({checkers[i], x + 1});
                }
            }
        }
        return -1;
    }
};