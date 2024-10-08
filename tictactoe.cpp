
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state;

    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    while (!game_state.get_gameOver()) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
        // The coordinates are valid; set the selectedRow and selectedColumn
        // members of the game state to the read values
        game_state.set_selectedRow(row);
        game_state.set_selectedColumn(col);
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
            
        // ECE244 Student: add your code here
            
        // Call playMove
        playMove(game_state);
        // ECE244 Student: add your code here
            
        // Print the GameState object, as prescribed in the handout
        cout<<"Selected row "<<row<<" and column "<<col<<endl;
        cout<<"Game state after playMove:"<<endl;
        cout<<"Board:"<<endl;
        for (int i = 0 ; i < boardSize ; i ++){
            cout<<"   ";
            for (int j = 0 ; j < boardSize ; j++){
                char c;
                if (game_state.get_gameBoard(i, j) == X){
                    c = 'X';
                } 
                else if (game_state.get_gameBoard(i, j) == O){
                    c = 'O';
                } else{
                    c = 'B';
                }
                cout<<c<< " ";
            }
            cout<<endl;
        }
        std::cout << std::boolalpha;
        cout<<"moveValid: "<<game_state.get_moveValid()<<endl;
        cout<<"gameOver: " << game_state.get_gameOver()<<endl;
        cout<<"winCode: "<< game_state.get_winCode()<<endl;
        // ECE244 Student: add your code here
            
    }
    

    return 0;
} 

