class Solution {
public:
    bool find(vector<vector<char>>& board, string word, int i, int j, int n, int m, int pos){
        if(i < 0  or i >= n or j < 0 or j >= m or pos > word.length() or board[i][j] != word[pos]){
            return false;
        }
        if(pos >= word.size() - 1){
            return true;
        }
        bool ans;
        char temp = board[i][j];
        board[i][j] = '*';
        ans = ans or find(board, word, i + 1, j, n, m, pos + 1) or find(board, word, i, j + 1, n, m, pos + 1) or find(board, word, i, j - 1, n, m, pos + 1) or find(board, word, i - 1, j, n, m, pos + 1);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word){
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(find(board, word, i, j, n, m, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};