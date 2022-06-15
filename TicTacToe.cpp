#include <iostream>

std::string board[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};

bool tie = false;
bool playerWon = false;
bool gameOver = false;

int slot;

std::string player1;
std::string player2;

const std::string marker1 = "X";
const std::string marker2 = "O";

std::string turn = marker1;

void drawBoard() {

    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[0][0] << " |" << " " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[1][0] << " |" << " " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[2][0] << " |" << " " << board[2][1] << " | " << board[2][2] << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void changeTurn() {
    if (turn == marker1) {
        turn = marker2;
    }
    else {
        turn = marker1;
    }
}

void input() {
    
    std::cout << "Enter number ranging from 1 - 9: " << std::endl;
    std::cin >> slot;

    while (slot < 1 or slot > 9) {
        std::cout << "Invalid Input" << std::endl;
        std::cout << "Enter numbers ranging from 1 to 9: ";
        std::cin >> slot;
    }
}

void placeMarker(int slot, std::string marker) {

    if (slot <= 3 && board[0][slot - 1] != "X" && board[0][slot - 1] != "O") {
        board[0][slot - 1] = marker;
    }
    else if (slot > 3 && slot < 7 && board[1][slot - 4] != "X" && board[1][slot - 1] != "O") {
        board[1][slot - 4] = marker;
    }
    else if (slot > 6 and slot < 10 && board[2][slot - 7] != "X" && board[2][slot - 7] != "O") {
        board[2][slot - 7] = marker;
    }
    else {
        std::cout << "The number you've entered is already full" << std::endl;
        input();
        placeMarker(slot, marker);
    }
}

bool winCheck(std::string marker1) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == marker1 || board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == marker1) {
            gameOver = true;
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        gameOver = true;
        return true;
    }
    else {
        return false;
    }
}

bool tieCheck() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != "X" && board[i][j] != "O") {
                return true;
            }
        }
    }

    return false;
}

void getPlayerNames() {

    std::cout << "Enter players'1 name: ";
    std::cin >> player1;

    std::cout << "Enter players'2 name: ";
    std::cin >> player2;

    std::cout << player1 << " goes first" << std::endl;
}

int main() {

    getPlayerNames();
    
    while (!gameOver) {
        drawBoard();
        input();

        placeMarker(slot, turn);
        changeTurn();

        if (winCheck(marker1)) {
            drawBoard();
            std::cout << player1 << " has won the game" << std::endl; 
        }
        else if (winCheck(marker2)) {
            drawBoard();
            std::cout << player2 << " has won the game" << std::endl;
        }
        else if (tieCheck()) {
            drawBoard();
            std::cout << "GAME's a TIE!!" << std::endl;
        }
    }

    return 0;
}
