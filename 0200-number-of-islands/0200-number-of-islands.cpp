class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<bool>> isVisited(
            m,
            vector<bool>(n, false)
        );

        int count = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

              
                if (!isVisited[i][j] && grid[i][j] == '1') {

                    count++;

                   
                    dfs(grid, isVisited, i, j);
                }
            }
        }

        return count;
    }

    void dfs(
        vector<vector<char>>& grid,
        vector<vector<bool>>& isVisited,
        int i,
        int j
    ) {

        
        if (
            i < 0 ||
            i >= grid.size() ||
            j < 0 ||
            j >= grid[0].size()
        ) {
            return;
        }

       
        if (isVisited[i][j]) {
            return;
        }

        
        if (grid[i][j] != '1') {
            return;
        }

        isVisited[i][j] = true;

        dfs(grid, isVisited, i - 1, j);

     
        dfs(grid, isVisited, i + 1, j);

       
        dfs(grid, isVisited, i, j - 1);

       
        dfs(grid, isVisited, i, j + 1);
    }
};