class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){
        int n = maze.size();
        int m = maze[0].size();
        queue<vector<int>> kow;
        kow.push({entrance[0] - 1, entrance[1]});
        kow.push({entrance[0] + 1, entrance[1]});
        kow.push({entrance[0], entrance[1] + 1});
        kow.push({entrance[0], entrance[1] - 1});
        int count = 0;
        maze[entrance[0]][entrance[1]] = '+';
        while(!kow.empty()){
            count += 1;
            int size = kow.size();
            for(int i = 0; i < size; i++){
                vector<int> x = kow.front();
                kow.pop();
                if(x[0] < 0 or x[0] >= n or x[1] < 0 or x[1] >= m){
                    continue;
                }
                if(maze[x[0]][x[1]] == '+'){
                    continue;
                }
                if(x[0] == 0 or x[1] == 0 or x[0] == n - 1 or x[1] == m - 1){
                    return count;
                }
                maze[x[0]][x[1]] = '+';
                kow.push({x[0] - 1, x[1]});
                kow.push({x[0] + 1, x[1]});
                kow.push({x[0], x[1] - 1});
                kow.push({x[0], x[1] + 1});
            }
        }
        return -1;
    }
};