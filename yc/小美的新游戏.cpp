#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M, P, Q;
    cin >> N >> M >> P >> Q;

    string *game = new string[N];
    int c = -1, r = -1;
    for (int i = 0; i < N; ++i) {
        cin >> game[i];
        for (int j = 0; j < game[i].size(); ++j) {
            if (game[i][j] == 'S') {
                r = i;
                c = j;
            }
        }
    }

    string move;
    int score = 0;
    cin >> move;

    for (int i = 0; i < move.size(); ++i) {
        switch (move[i]) {
        case 'W':
            if (r == 0) {
                break;
            }
            else {
                if (game[r-1][c] == '#') {
                    break;
                }
                else {
                    r--;
                    if (game[r][c] == 'O') {
                        score += P;
                    }
                    if (game[r][c] == 'X') {
                        score -= Q;
                    }
                    game[r][c] = '+';
                }
            }
            break;

        case 'S':
            if (r == N - 1) {
                break;
            }
            else {
                if (game[r+1][c] == '#') {
                    break;
                }
                else {
                    r++;
                    if (game[r][c] == 'O') {
                        score += P;
                    }
                    if (game[r][c] == 'X') {
                        score -= Q;
                    }
                    game[r][c] = '+';
                }
            }
            break;

        case 'A':
            if (c == 0) {
                break;
            }
            else {
                if (game[r][c-1] == '#') {
                    break;
                }
                else {
                    c--;
                    if (game[r][c] == 'O') {
                        score += P;
                    }
                    if (game[r][c] == 'X') {
                        score -= Q;
                    }
                    game[r][c] = '+';
                }
            }
            break;

        case 'D':
            if (c == M + 1) {
                break;
            }
            else {
                if (game[r][c+1] == '#') {
                    break;
                }
                else {
                    c++;
                    if (game[r][c] == 'O') {
                        score += P;
                    }
                    if (game[r][c] == 'X') {
                        score -= Q;
                    }
                    game[r][c] = '+';
                }
            }
            break;
        }
    }

    cout << score;
    return 0;
}