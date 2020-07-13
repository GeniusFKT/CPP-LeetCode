#include <vector>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, l;
        bool dict[9] = {false};

        for (i = 0; i < 9; ++i)
        {
            this->clearArray(dict);
            for (j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                    if (dict[int(board[i][j])-49])
                        return false;
                    else
                        dict[int(board[i][j])-49] = true;
            }
        }

        for (j = 0; j < 9; ++j)
        {
            this->clearArray(dict);
            for (i = 0; i < 9; ++i)
            {
                if (board[i][j] != '.')
                    if (dict[int(board[i][j])-49])
                        return false;
                    else
                        dict[int(board[i][j])-49] = true;
            }
        }

        for (i = 0; i < 3; ++i)
            for (j = 0; j < 3; ++j)
            {
                this->clearArray(dict);
                for (k = 0; k < 3; ++k)
                    for (l = 0; l < 3; ++l)
                    {
                        if (board[3*i+k][3*j+l] != '.')
                            if (dict[int(board[3*i+k][3*j+l])-49])
                                return false;
                            else
                                dict[int(board[3*i+k][3*j+l])-49] = true;
                    }
            }

        return true;
    }

    void clearArray(bool *array) {
        int i;
        for (i = 0; i < 9; ++i)
            array[i] = false;
    }
};