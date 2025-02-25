class NeighborSum {
public:
vector<vector<int>> mat;
unordered_map<int, pair<int, int>> mpp;
int n, m;
    NeighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mpp[grid[i][j]] = {i, j};
            }
        }
    }

    int findTotalSum(int row, int col, int drow[], int dcol[]) {
        int sum = 0;
        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < 0 || ncol < 0 || nrow >= n || ncol >= m)  {
                continue;
            }
            sum += mat[nrow][ncol];
        }
        return sum;
    }
    
    int adjacentSum(int value) {
        auto ele = mpp[value];
        int row = ele.first, col = ele.second;
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return -1;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        return findTotalSum(row, col, drow, dcol);
    }
    
    int diagonalSum(int value) {
        auto ele = mpp[value];
        int row = ele.first, col = ele.second;
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return -1;
        }
        int drow[] = {-1, -1, 1, 1};
        int dcol[] = {-1, 1, -1, 1};

        return findTotalSum(row, col, drow, dcol);
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */