1. For the 1st Recursive Soln W/ a extra DS.
We Don't need to traverse to the right most side of the matrix.
i.e, no 'UP', 'DOWN', 'TOP-RIGHT', 'BOTTOM-RIGHT'.
```
class Solution {
public:
bool isSafe1(int row, int col, vector<string> board, int n) {
// check upper diagonal
int duprow = row;
int dupcol = col;
while(row >= 0 && col >= 0) {
if(board[row][col] == 'Q') return false;
row--;
col--;
}
// check within the row
col = dupcol;
row = duprow;
while(col>=0) {
if(board[row][col] == 'Q') return false;
col--;
}
//Check bottom diagonal
row = duprow;
col = dupcol;
while(row<n && col>=0) {
if(board[row][col] == 'Q') return false;
row++;
col--;
}
return true;
}
public:
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
if(col == n) {