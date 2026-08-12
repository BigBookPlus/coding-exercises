#include"Solution.h"
bool Solution::exist(vector<vector<char> > &board, string word) {
	int m = board.size();
	int n = 0;
	if (m > 0)
		n = board[0].size();
	else
		return false;
	if (n == 0)
		return false;

	int **tag = new int*[m];
	for (int i = 0; i <m; i++)
	{
		tag[i] = new int[n];
		fill(tag[i], tag[i] + n, 0);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == word[0]){
				tag[i][j] = 1;
				if (searchWord(board, i, j, m, n, 0, tag, word))
					return true;
				tag[i][j] = 0;
			}
		}
	}

	return false;

}

bool Solution::searchWord(vector<vector<char> > &board, int x, int y, int m, int n, int step, int **tag, string&word)
{


	int d[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
	for (int i = 0; i < 4; i++)
	{
		int xx = x + d[i][0];
		int yy = y + d[i][1];
		if (step + 1 < word.size() && xx >= 0 && xx < m
			&&yy >= 0 && yy < n &&tag[xx][yy] == 0
			&& board[xx][yy] == word[step + 1])
		{
			tag[xx][yy] = 1;
			if (searchWord(board, xx, yy, m, n, step + 1, tag, word))
				return true;
			tag[xx][yy] = 0;
		}
		else if (step + 1 == word.size())
			return true;
	}
	return false;
}

