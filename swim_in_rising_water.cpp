#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

        min_heap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!min_heap.empty()) {
            auto curr = min_heap.top();
            min_heap.pop();

            int time = curr[0], r = curr[1], c = curr[2];

            if (r == n - 1 && c == n - 1) return time;

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    min_heap.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };


    int result = sol.swimInWater(grid);
    cout << "Minimum time to reach bottom-right: " << result << endl;

    return 0;
}