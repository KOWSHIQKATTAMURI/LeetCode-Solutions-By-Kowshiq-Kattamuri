class Solution {
public:
    int solve(int col, vector<vector<int>> &grid, int row, int n, int m){
        while(row < m){
            if(grid[row][col] == 1){
                if((col + 1 < n && grid[row][col + 1] == -1) || (col + 1 == n)){
                    return -1;
                } 
                row++;
                col++;
            }else{
                if((col - 1 >= 0 && grid[row][col - 1] == 1) || (col - 1 < 0)){
                    return -1;
                }
                row++;
                col--;
            }
        }
        return col;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> kow;
        for(int i = 0; i < m; i++){
           int x = solve(i, grid, 0, m, n);
           kow.push_back(x);
        }
        return kow;
    }
};