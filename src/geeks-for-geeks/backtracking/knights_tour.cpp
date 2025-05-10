#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

class Solution {
private:
	vector<vector<vector<int>>> result;
	int dirs[8][2] = {
		{1,2},{-1,2},
		{2,1},{2,-1},
		{-1,-2},{1,-2},
		{-2,1},{-2,-1}
	};

	string serialize(int n, vector<vector<int>> &board) {
		string s = "[";
		for(auto &row : board) {
			s += '[';
			for(int val : row) s += to_string(val);
			s += "]\n";
		}
		s += "]\n";
		return s;
	}

	bool isValid(int x, int y, int n, vector<vector<int>> &board) {
		return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1;
	}

	void knightTourHelper(pair<int,int> coord, int step, int n, vector<vector<int>> &board) {
		if(step == n*n) {
			res_set.insert(serialize(n, board));
			result.push_back(board);
			return;
		}

		for(auto &[dx, dy] : dirs) {
			int x = coord.first + dx;
			int y = coord.second + dy;
			if(isValid(x,y,n,board)) {
				board[x][y] = step;
				pair<int,int> new_coord = {x,y};
				knightTourHelper(new_coord, step+1, n, board);
				board[x][y] = -1;
			}
		}
	}
public:
	set<string> res_set;
	vector<vector<vector<int>>> knightTour(int n) {
		vector<vector<int>> board(n, vector<int>(n, -1));
		board[0][0] = 0;
		pair<int,int> start = {0, 0};
		knightTourHelper(start,1,n,board);
		return result;
	}
	
};

int main() {
	int n = 5;

	Solution soln;

	vector<vector<vector<int>>> res = soln.knightTour(n);
	for(auto &board : res) {
		for (auto &row : board) {
			for (int val : row) {
				cout << val << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << "Result Set Size: " << soln.res_set.size() << endl;
	cout << "Result Vector Size: " << res.size() << endl;

	return 0;
}
