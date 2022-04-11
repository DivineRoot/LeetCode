class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        // Rotate the grid for k times
        for (int rot = 0; rot < k; rot ++){
            // Save last value
            int tmpLast = grid[n][m];
            // Iterate from last grid position grid[m][n] to second row grid[1][0]
            for (int i = n; i >= 1; i--){
                for (int j = m; j >= 0; j--){
                    // If at grid positon grid[i][0], the last element of the previous colum is assigned.
                    if (j == 0){
                        grid[i][j] = grid[i - 1][m];
                    } else{
                        grid[i][j] = grid[i][j - 1];
                    }
                }
            }
            // First row until second element.
            for (int j = m; j >= 1; j--){
                grid[0][j] = grid[0][j - 1];
            }
            // First position
            grid[0][0] = tmpLast;
        }
        return grid;
    }
};