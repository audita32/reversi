//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void checkWin(GameState& game_state, int player);
void playMove(GameState& game_state) {
    if (game_state.get_gameOver()){
        return;
    }
    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == Empty){
        game_state.set_moveValid(true);
    }
    else{
        game_state.set_moveValid(false);
    }
    if (game_state.get_moveValid() == false){
        return;
    }
    if (game_state.get_turn() == true){
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        game_state.set_turn(false);
    } else{
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        game_state.set_turn(true);
    }
    checkWin(game_state, X);
    checkWin(game_state, O);
    // check if game is draw
    bool is_draw = true;
    for (int i = 0 ; i < boardSize ; i++){
        for (int j = 0 ; j < boardSize ; j++){
            if (game_state.get_gameBoard(i, j) == Empty){
                is_draw = false;
                break;
            }
        }
        if (is_draw == false){
            break;
        }
    }
    if (is_draw == true){
        game_state.set_winCode(Empty);
        game_state.set_gameOver(true);
    }
}

void checkWin(GameState& game_state, int player){
      int val;
    if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(0,1) == player && game_state.get_gameBoard(0,2) == player){
       
        game_state.set_gameOver(true);
        game_state.set_winCode(1l);
    } else if (game_state.get_gameBoard(1,0) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(1,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(2);
    } else if (game_state.get_gameBoard(2,0) == player && game_state.get_gameBoard(2,1) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(3);
    } else if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(1,0) == player && game_state.get_gameBoard(2,0) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(4);
    } else if (game_state.get_gameBoard(0,1) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,1) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(5);
    } else if (game_state.get_gameBoard(0,2) == player && game_state.get_gameBoard(1,2) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(6);
    } else if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(7);
    } else if (game_state.get_gameBoard(0,2) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,0) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(8);
    }
}

//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void checkWin(GameState& game_state, int player);
void playMove(GameState& game_state) {
    if (game_state.get_gameOver()){
        return;
    }
    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == Empty){
        game_state.set_moveValid(true);
    }
    else{
        game_state.set_moveValid(false);
    }
    if (game_state.get_moveValid() == false){
        return;
    }
    if (game_state.get_turn() == true){
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        game_state.set_turn(false);
    } else{
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        game_state.set_turn(true);
    }
    checkWin(game_state, X);
    checkWin(game_state, O);
    // check if game is draw
    bool is_draw = true;
    for (int i = 0 ; i < boardSize ; i++){
        for (int j = 0 ; j < boardSize ; j++){
            if (game_state.get_gameBoard(i, j) == Empty){
                is_draw = false;
                break;
            }
        }
        if (is_draw == false){
            break;
        }
    }
    if (is_draw == true){
        game_state.set_winCode(Empty);
        game_state.set_gameOver(true);
    }
}

void checkWin(GameState& game_state, int player){
      if (game_state.get_gameBoard(0,2) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,0) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(8);
    }
    else if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(7);
    }
    else if (game_state.get_gameBoard(0,2) == player && game_state.get_gameBoard(1,2) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(6);
    }
 else if (game_state.get_gameBoard(0,1) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(2,1) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(5);
    } 
    else if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(1,0) == player && game_state.get_gameBoard(2,0) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(4);
    } 
    else if (game_state.get_gameBoard(2,0) == player && game_state.get_gameBoard(2,1) == player && game_state.get_gameBoard(2,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(3);
    }
    else if (game_state.get_gameBoard(1,0) == player && game_state.get_gameBoard(1,1) == player && game_state.get_gameBoard(1,2) == player) {
        game_state.set_gameOver(true);
        game_state.set_winCode(2);
    }
    else if (game_state.get_gameBoard(0,0) == player && game_state.get_gameBoard(0,1) == player && game_state.get_gameBoard(0,2) == player){
       
        game_state.set_gameOver(true);
        game_state.set_winCode(1);
    }
}




