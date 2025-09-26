#include<iostream>
using namespace std;

int main() {
    char board[3][3] = { {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'} };

    string n1, n2;
    cout << "Enter name of first player: ";
    cin >> n1;
    cout << "Enter name of second player: ";
    cin >> n2;

    cout << n1 << " is Player 1 (X)\n";
    cout << n2 << " is Player 2 (O)\n";

    int move, turns = 0;
    char mark = 'X';

    while (true) {

        cout << "\n";
        for (int i=0; i<3; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\n";


        cout << (mark=='X'?n1:n2) << " (" << mark << ") enter position (1-9): ";
        cin >> move;

        int r = (move-1)/3, c = (move-1)%3;
        if (board[r][c]=='X' || board[r][c]=='O') {
            cout << "Position already taken, try again!\n";
            continue;
        }

        board[r][c] = mark;
        turns++;

        if ((board[0][0]==mark && board[0][1]==mark && board[0][2]==mark) ||
            (board[1][0]==mark && board[1][1]==mark && board[1][2]==mark) ||
            (board[2][0]==mark && board[2][1]==mark && board[2][2]==mark) ||
            (board[0][0]==mark && board[1][0]==mark && board[2][0]==mark) ||
            (board[0][1]==mark && board[1][1]==mark && board[2][1]==mark) ||
            (board[0][2]==mark && board[1][2]==mark && board[2][2]==mark) ||
            (board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) ||
            (board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)) {
            cout << "\n" << (mark=='X'?n1:n2) << " wins the game! 🎉\n";
            break;
        }

        if (turns == 9) {
            cout << "\nGame Draw!\n";
            break;
        }
        mark = (mark=='X') ? 'O' : 'X';
    }

    return 0;
}
