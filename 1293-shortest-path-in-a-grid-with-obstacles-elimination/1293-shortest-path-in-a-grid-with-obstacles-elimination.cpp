class Solution {
public:
    int solve(vector<vector<int>>& grid, int start_row, int start_col, int end_row, int end_col, int left, vector<vector<bool>>& visited, vector<vector<vector<int>>> &kow){
        if(start_row < 0 or start_col < 0 or start_row >= end_row or start_col >= end_col or visited[start_row][start_col]){
            return 1e6;
        }
        if(start_row == end_row - 1 and start_col == end_col - 1){
            return 0;
        }
        if(kow[start_row][start_col][left] != -1){
            return kow[start_row][start_col][left];
        }
        if(left == 0 and grid[start_row][start_col] == 1){
            return 1e6;
        }else if(grid[start_row][start_col] == 1){
            left--;
        }
        visited[start_row][start_col] = true;
        int a = 1 + solve(grid, start_row + 1, start_col, end_row, end_col, left, visited, kow);
        int b = 1 + solve(grid, start_row - 1, start_col, end_row, end_col, left, visited, kow);
        int c = 1 + solve(grid, start_row, start_col + 1, end_row, end_col, left, visited, kow);
        int d = 1 + solve(grid, start_row, start_col - 1, end_row, end_col, left, visited, kow);
        visited[start_row][start_col] = false;
        return kow[start_row][start_col][left] = min({a, b, c, d});
    }
    int shortestPath(vector<vector<int>>& grid, int k){
        int count_i = 0;
        if(grid.size() == 1 and grid[0].size() == 1){
            return 0;
        }
        vector<vector<vector<int>>> kow(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, -1)));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][grid[0].size() - 1] == 1){
                break;
            }else{
                count_i++;
            }
        }
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[0][j] == 1){
                break;
            }else{
                count_i++;
            }
        }
        cout << count_i << endl;
        if(count_i == grid.size() + grid[0].size()){
            return count_i - 2;
        }
        int x = solve(grid, 0, 0, grid.size(), grid[0].size(), k, visited, kow);
        return x > grid.size()*grid[0].size() ? -1 : x;
    }
};