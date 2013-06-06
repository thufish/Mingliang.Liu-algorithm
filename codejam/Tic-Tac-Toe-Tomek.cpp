#include <iostream>
#include <string>
#include <vector>

using namespace std;

//calculate the winner 
char is_win(const string &str) {
    bool ok = true;
    char c = 0;
    for (int i = 0; i < 4; ++i) {
        if (str[i] == '.') {
            ok = false;
            break;
        } else if (str[i] == 'X' || str[i] == 'O') {
            if (!c)
                c = str[i];
            else if (c != str[i]) {
                ok = false;
                break;
            }
        }
    }

    if (ok)
        return c;
    else
        return 0;
}

int main() {
    int cases;
    cin >> cases;

    for (int c = 1; c < cases + 1; ++c) {
        vector<string> board;
        // read the board
        for (int row = 0; row < 4; ++row) {
            string str;
            cin >> str;
            board.push_back(str);
        }
        string tmp;
        getline(cin, tmp);

        char winner = 0;
        bool completed = true;
        string str(4, 0);

        // by row
        for (int row = 0; row < 4; ++row) {
            winner = is_win(board[row]);
            if (winner)
                goto DUMP;
        }

        // by col
        for (int col = 0; col < 4; ++col) {
            string str(4, 0);
            for (int row = 0; row < 4; ++row)
                str[row] = board[row][col];
            winner = is_win(str);
            if (winner)
                goto DUMP;
        }

        // by diagonal
        for (int i = 0; i < 4; ++i)
            str[i] = board[i][i];
        winner = is_win(str);
        if (winner)
            goto DUMP;

        // by versa-diaonal
        for (int i = 0; i < 4; ++i)
            str[i] = board[i][3 - i];
        winner = is_win(str);
        if (winner)
            goto DUMP;

        for (int row = 0; row < 4; ++row)
            for (int col = 0; col < 4; ++col)
                if (board[row][col] == '.') {
                    completed = false;
                    goto DUMP;
                }

DUMP:
        cout << "Case #" << c << ": ";
        if (winner)
            cout << winner << " won" << endl;
        else if (completed)
            cout << "Draw" << endl;
        else
            cout << "Game has not completed" << endl;
    }

    return 0;
}
