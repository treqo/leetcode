#include <iostream>
#include <vector>
#include <string>

/* --- N Queen Problem ---
*
* Task:
* find the solution to the n-queens problem, where n queens are placed on an nxn chessboard such that:
*	- No two queens can attack each other
*
* Input:
*	- Integer n (1 <= n <= 16)
* 
* Methods:
*	- allSolutions: Returns a vector<vector<string>> representing all valid configurations
*	- firstSolution: Returns a vector<string> of the first solution it finds to the N Queens problem
*	- numOfSolutions: Returns an int representing the number of unique board configurations of valid solutions
*/

using namespace std;

class Solution {
private:

	int n;
	int row;
	int col;
	int ne_diag;
	int se_diag;

	void reset(int n) {
		this->n = n;
		row = 0;
		col = 0;
		ne_diag = 0;
		se_diag = 0;
	}

	bool isValid(int i, int j) {
		return !(row & (1 << i) || col & (1 << j) 
			|| ne_diag & coord_to_ne_diag(i, j)
			|| se_diag & coord_to_se_diag(i, j));
	}

	void set(int i, int j, vector<string>& board) {
		board[i][j] = 'Q';
		row |= (1 << i);
		col |= (1 << j);
		ne_diag |= coord_to_ne_diag(i, j);
		se_diag |= coord_to_se_diag(i, j);
	}

	void unset(int i, int j, vector<string>& board) {
		board[i][j] = '.';
		row ^= (1 << i);
		col ^= (1 << j);
		ne_diag ^= coord_to_ne_diag(i, j);
		se_diag ^= coord_to_se_diag(i, j);
	}

	int coord_to_ne_diag(int i, int j) {
		return (1 << (i + j));
	}

	int coord_to_se_diag(int i, int j) {
		return (1 << (i - j + n - 1));
	}

public:
	vector<vector<string>> allSolutions(int n) {
		reset(n);

		vector<vector<string>> result;

		function<void(int,vector<string>&)> backtrack = [&] (int i, vector<string>& board) {
			if(i == n) {
				result.push_back(board);
			} else {
				for(int j = 0; j < n; j++) {
					if(isValid(i,j)) {
						set(i,j, board);
						backtrack(i+1, board);
						unset(i,j, board);
					}
				}
			}
		};

		string s(n,'.');
		vector<string> board(n, s);

		backtrack(0,board);

		return result;
	}

	vector<string> firstSolution(int n) {
		reset(n);

		vector<string> result;

		function<bool(int,vector<string>&)> backtrack = [&] (int i, vector<string>& board) {
			if(i == n) {
				result = board;
				return true;
			} else {
				for(int j = 0; j < n; j++) {
					if(isValid(i,j)) {
						set(i,j, board);
						if(backtrack(i+1, board)) {
							return true;
						}
						unset(i,j, board);
					}
				}
			}

			return false;
		};

		string s(n,'.');
		vector<string> board(n, s);

		backtrack(0,board);
		return result;
	}

	int numOfSolutions(int n) {
		reset(n);
		
		int result = 0;

		function<void(int,vector<string>&)> backtrack = [&] (int i, vector<string>& board) {
			if(i == n) {
				result++;
			} else {
				for(int j = 0; j < n; j++) {
					if(isValid(i,j)) {
						set(i,j, board);
						backtrack(i+1, board);
						unset(i,j, board);
					}
				}
			}
		};

		string s(n,'.');
		vector<string> board(n, s);

		backtrack(0,board);

		return result;
	}

};

int main() {
	Solution soln;

	for(auto& v : soln.allSolutions(5)) {
		for(auto& s : v) {
			cout << s << '\n';
		}
		cout << '\n';
	}

	cout << soln.numOfSolutions(5) << "\n\n";

	for(auto& s : soln.firstSolution(5)) {
		cout << s << '\n';
	}
	cout << '\n';

	return 0;
}
