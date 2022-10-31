class Solution {
public:
    bool check(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(i >= m){
            return true;
        }
        int a = i, c = j;
        if(a + 1 < m){
            while(c < n){
                if(c + 1 < n and matrix[a][c] != matrix[a + 1][c + 1]){
                    return false;
                }
                c++;
            }
        }
        return check(matrix, i + 1, j, m, n);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        return check(matrix, 0, 0, m, n);
    }
};