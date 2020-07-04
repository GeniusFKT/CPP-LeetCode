class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,bool> rows[9];
        unordered_map<char,bool> cols[9];
        unordered_map<char,bool> grids[9];
        
        for (int i=0;i<9;++i)
        {
            for (int j=0;j<9;++j)
            {
                if (board[i][j]!='.')
                {
                    if (rows[i].find(board[i][j])!=rows[i].end()||
                        cols[j].find(board[i][j])!=cols[j].end()||
                        grids[(i/3)*3+j/3].find(board[i][j])!=grids[(i/3)*3+j/3].end())
                        return false;
                    rows[i][board[i][j]]=true;
                    cols[j][board[i][j]]=true;
                    grids[(i/3)*3+j/3][board[i][j]]=true;
                }
            }
        }
        return true;
    }
};