#include <iostream>
using namespace std;

class TicTacToe {
private:
    int board[3][3];

public:
    TicTacToe() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                board[i][j] = 0;
    }

    void displayBoard() {
        cout << "\nBoard:\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char c = (board[i][j]==0)?' ': (board[i][j]==1)?'X':'O';
                cout << c;
                if(j<2) cout << " | ";
            }
            cout << "\n";
            if(i<2) cout << "--+---+--\n";
        }
    }

    bool makeMove(int player, int row, int col) {
        if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=0){
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = player;
        return true;
    }

    int checkWin() {
        // rows columns
        for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=0)
                return board[i][0];
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=0)
                return board[0][i];
        }
        // diagonal
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=0)
            return board[0][0];
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=0)
            return board[0][2];
        // checking draw or not
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==0) return 0; // game continues
        return -1; // draw
    }
};

int main() {
    TicTacToe game;
    int player = 1, row, col, status = 0;

    cout << "Tic-Tac-Toe Game\nPlayer 1 = X, Player 2 = O\n";

    while(status==0){
        game.displayBoard();
        cout << "Player " << player << ", enter row and column (0-2): ";
        cin >> row >> col;
        if(game.makeMove(player,row,col)){
            status = game.checkWin();
            if(status==0)
                player = (player==1)?2:1;
        }
    }

    game.displayBoard();
    if(status==1) cout << "Player 1 wins.\n";
    else if(status==2) cout << "Player 2 wins.\n";
    else cout << "It's a draw.\n";

    return 0;
}
