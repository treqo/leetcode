#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

class Solution {
private:
	int n;

	vector<tuple<int,int,char>> dirs = {
		{0,1,'R'},
		{0,-1,'L'},
		{1,0,'D'},
		{-1,0,'U'}
	};

	bool isValid(int x, int y, vector<vector<int>>& maze) {
		return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1;
	}

public:
	vector<string> ratInMaze(vector<vector<int>>& maze) {
		n = maze.size();
		vector<string> result;

		function<void(int,int,string&)> backtrack = [&] (int x, int y, string& s) {
			if(x == n - 1 && y == n - 1) {
				result.push_back(s);
			} else {
				maze[x][y] = 0;
				for(auto& dir : dirs) {
					int dx, dy;
					char c;
					tie(dx, dy, c) = dir;

					int nx = x + dx;
					int ny = y + dy;
					if(isValid(nx,ny,maze)) {
						s.push_back(c);
						backtrack(nx,ny,s);
						s.pop_back();
					}
				}
				maze[x][y] = 1;
			}
		};

		if(maze[0][0] == 1 && maze[n-1][n-1] == 1) {
			string path = "";
			backtrack(0,0,path);
		}

		return result;
	}
};

int main() {
	Solution soln;

	vector<vector<int>> maze = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 0, 0},
		{0, 1, 1, 1}
	};

	vector<string> result = soln.ratInMaze(maze);

	if (result.empty()) {
		cout << -1 << endl;
	} else {
		for (const auto& p : result) {
			cout << p << " ";
		}
		cout << endl;
	}

	return 0;
}
