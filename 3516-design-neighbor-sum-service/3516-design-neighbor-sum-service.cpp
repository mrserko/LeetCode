class NeighborSum {
public:

    std::unordered_map<int, int> adjSum;
    std::unordered_map<int, int> diagSum;

    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> bigGrid(n + 2, std::vector<int>(n + 2, 0));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                bigGrid[i + 1][j + 1] = grid[i][j];
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                adjSum[bigGrid[i][j]] = bigGrid[i - 1][j] + bigGrid[i + 1][j] + bigGrid[i][j - 1] + bigGrid[i][j + 1];
                diagSum[bigGrid[i][j]] = bigGrid[i - 1][j - 1] + bigGrid[i + 1][j + 1] + bigGrid[i + 1][j - 1] + bigGrid[i - 1][j + 1];
            }
        }
    }
    
    int adjacentSum(int value) {
        return adjSum[value];
    }
    
    int diagonalSum(int value) {
        return diagSum[value];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */