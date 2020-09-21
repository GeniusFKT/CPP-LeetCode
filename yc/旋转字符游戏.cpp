#include <iostream>
using namespace std;

char update(char c) {
    if (c == 'Z') {
        return 'A';
    }

    return c + 1;
}

int main() {
    int M, N;
    cin >> M >> N;

    char **mat = new char *[M];
    for (int i = 0; i < M; ++i) {
        mat[i] = new char [N];

        for (int j = 0; j < N; ++j) {
            mat[i][j] = '0';
        }
    }

    // r:0, d:1, l:2, u:3
    int direc = 0;
    int r = 0, c = 0;
    char curr = 'A';
    int flag = 0;
    mat[r][c] = curr;
    while (true) {
        switch (direc)
        {
        case 0:
            if (c == N - 1 || mat[r][c+1] != '0') {
                direc = 1;
                flag++;
            }
            else {
                c++;
                curr = update(curr);
                mat[r][c] = curr;
                flag = 0;
            }
            break;

        case 1:
            if (r == M - 1 || mat[r+1][c] != '0') {
                direc = 2;
                flag++;
            }
            else {
                r++;
                curr = update(curr);
                mat[r][c] = curr;
                flag = 0;
            }
            break;

        case 2:
            if (c == 0 || mat[r][c-1] != '0') {
                direc = 3;
                flag++;
            }
            else {
                c--;
                curr = update(curr);
                mat[r][c] = curr;
                flag = 0;
            }
            break;

        case 3:
            if (r == 0 || mat[r-1][c] != '0') {
                direc = 0;
                flag++;
            }
            else {
                r--;
                curr = update(curr);
                mat[r][c] = curr;
                flag = 0;
            }
            break;
        
        default:
            break;
        }

        if (flag == 4) {
            break;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}