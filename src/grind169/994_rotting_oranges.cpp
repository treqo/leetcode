#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
        int dirs[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        int m, n;
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();
            int fresh_count = 0;
            queue<pair<int,int>> q;
    
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 1) {
                        fresh_count++;
                    } else if(grid[i][j] == 2) {
                        q.push({i,j});
                    }
                }
            }
    
            if(fresh_count == 0) return 0;
    
            int minutes = 0;
            while(!q.empty()) {
                int q_size = q.size();
                bool any_rotted = false;
                for(int i = 0; i < q_size; i++) {
                    auto [x,y] = q.front(); q.pop();
                    for(auto& [dx,dy] : dirs) {
                        if(validCoords(x+dx, y+dy) && grid[x+dx][y+dy] == 1) {
                            any_rotted = true;
                            fresh_count--;
                            grid[x+dx][y+dy] = 2;
                            q.push({x+dx, y+dy});
                        }
                    }
                }
                minutes += any_rotted;
            }
    
            return (fresh_count == 0) ? minutes : -1;
        }
    
        bool validCoords(int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        }
    };