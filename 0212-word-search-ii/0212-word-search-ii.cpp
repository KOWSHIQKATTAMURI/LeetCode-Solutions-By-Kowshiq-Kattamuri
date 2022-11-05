class Solution {
public:
     bool isValid(int i, int j, int r, int c, vector<vector<int>>& vis) {
        if (i >= 0 && i < r && j >= 0 && j < c && vis[i][j] == 0) {
            return true;
        }
        return false;
    }
public:
    
    void dfs(int i, int j, int r, int c, string& temp, vector<vector<int>>& vis, vector<vector<char>>& board,
	unordered_map<string, int>& mp, unordered_map<string, int>& mpAns) {
        if (mp.find(temp) != mp.end()) {
            mpAns[temp] = 1;
        }
        if (temp.size() == 10) {
            return;
        }
        if (isValid(i, j + 1, r, c, vis)) {
            vis[i][j + 1] = 1;
            temp.push_back(board[i][j + 1]);
            dfs(i, j + 1, r, c, temp, vis, board, mp, mpAns);
            vis[i][j + 1] = 0;
            temp.pop_back();
        }
        if (isValid(i + 1, j, r, c, vis)) {
            vis[i + 1][j] = 1;
            temp.push_back(board[i + 1][j]);
            dfs(i + 1, j, r, c, temp, vis, board, mp, mpAns);
            vis[i + 1][j] = 0;
            temp.pop_back();
        }
        if (isValid(i, j - 1, r, c, vis)) {
            vis[i][j - 1] = 1;
            temp.push_back(board[i][j - 1]);
            dfs(i, j - 1, r, c, temp, vis, board, mp, mpAns);
            vis[i][j - 1] = 0;
            temp.pop_back();
        }
        if (isValid(i - 1, j, r, c, vis)) {
            vis[i - 1][j] = 1;
            temp.push_back(board[i - 1][j]);
            dfs(i - 1, j, r, c, temp, vis, board, mp, mpAns);
            vis[i - 1][j] = 0;
            temp.pop_back();
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r = board.size(), c = board[0].size();
        unordered_map<string, int> mp;
        for (auto it : words) {
            mp[it] = 1;
        }
        unordered_map<string, int> mpAns;
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                vector<vector<int>> vis(r, vector<int>(c, 0));
                string temp = "";
                temp.push_back(board[i][j]);
                vis[i][j] = 1;
                dfs(i, j, r, c, temp, vis, board, mp, mpAns);
            }
        }
        vector<string> ans;
        for (auto it : mpAns) {
            ans.push_back(it.first);
        }
        return ans;
    }
};