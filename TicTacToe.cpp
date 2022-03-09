#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;
//initializing All Variables
char player1 = 'X', player2 = 'O';
char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
char currentMove = '0';
char currentPlayer = player1;
bool moveValidator = false;
bool COLLISION;





void Draw(char array[3][3], int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

bool validatePLayerMove(char cMove){

     while(moveValidator == false){
        if(cMove != '1' && 
            cMove != '2' && 
            cMove != '3' && 
            cMove != '4' && 
            cMove != '5' && 
            cMove != '6' && 
            cMove != '7' && 
            cMove != '8' && 
            cMove != '9'){
                moveValidator = false;
                cout << "Invalid Operator\n Try again" << endl;
                break;
        }
        else{
            moveValidator = true;
        }
    }
    return moveValidator;
   
}


char playerInput(char player, char cMove){
    cout << "\n";
    cout << "Tic Tac Toe Game \n";

    if(player == player1){
        cout << "Player 1: \n";
        cout << "Which Position Do you want to move in?: \n";
    }
    else if (player == player2){
        cout << "Player 2: \n";
        cout << "Which Position Do you want to move in?: \n";
    }
    else{
        cout << "ERROR" << endl;
    }
    
    cin >> cMove;
  return cMove;
}

bool updateBoard(char array[3][3], char cMove, char player, int size){
    for(int rows = 0; rows < size; rows++){
       for(int cols = 0; cols < size; cols++){
           if (array[rows][cols] == cMove){
               array[rows][cols] = player;
                COLLISION = false;
               
           }
           else if(array[rows][cols] == 'X' || array[rows][cols] == 'O'){
               COLLISION = true;
               
           }
       }
   }
   return COLLISION;
}

bool is_Player1Winner(char array[3][3]){
    bool winner = false;
    //Checking Rows for Player 1
    if(array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X'){
        winner = true;
    }
    else if(array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X'){
        winner = true;
    }
    else if(array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X'){
        winner = true;
    }
    
    //Checking columns for Player 1
     if(array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X'){
        winner = true;
    }
    else if(array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X'){
        winner = true;
    }
    else if(array[0][2] == 'X' && array[1][2] == 'X' && array[2][2] == 'X'){
        winner = true;
    }
    

    //Checking diagonals for Player 1
    if(array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X'){
        winner = true;
    }
    else if(array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X'){
        winner = true;
    }


    return winner;

}

bool is_Player2Winner(char array[3][3]){
    bool winner = false;
    //Checking Rows for Player 2
    if(array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O'){
        winner = true;
    }
    else if(array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O'){
        winner = true;
    }
    else if(array[2][0] == 'O' && array[2][1] == 'O' && array[2][2] == 'O'){
        winner = true;
    }

    //Checking columns for Player 2
    if(array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O'){
        winner = true;
    }
    else if(array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O'){
        winner = true;
    }
    else if(array[0][2] == 'O' && array[1][2] == 'O' && array[2][2] == 'O'){
        winner = true;
    }

    //Checking diagonals for Player 2
    if(array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O'){
        winner = true;
    }
    else if(array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O'){
        winner = true;
    }

    return winner;

}


int main(){
    bool validMove;
    bool validPosition;
    char playerMove;
    Draw(board, 3);   
   

    for(int move = 0; move < 9; move++){
        moveValidator = false;
        validPosition = true;
        do{
            validMove = validatePLayerMove(
            playerMove = playerInput(currentPlayer, currentMove));
            validPosition = updateBoard(board, playerMove, currentPlayer, 3);
            Draw(board, 3);
        }while(validMove == false || validPosition == true);
        system("clear");
        Draw(board, 3);
        if(is_Player1Winner(board) == true){
            system("clear");
            cout << "Player 1 Wins!" << endl;
            Draw(board, 3);
            return 3;
        }
        if(is_Player2Winner(board) == true){
            system("clear");
            cout << "Player 2 Wins!"<< endl;
            Draw(board, 3);
            return 3;
        }
        if(currentPlayer == player1){
            currentPlayer = player2;
        }
        else{
            currentPlayer = player1;
        }

    }
    if(is_Player1Winner(board) != true && is_Player2Winner(board) != true){
        cout << "It's a Draw!" << endl;
    } 
    else{
        cout << "Game Error" << endl;
    }

}

