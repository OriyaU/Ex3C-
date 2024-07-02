//oriya7914@gmail.com
//213525512
#pragma once
#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include <string>
#include "Player.hpp"
#include "Board.hpp"

namespace ariel {

    class Catan {
    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board board;
        int currentPlayer;

    public:
        // Constructor
        Catan(Player& p1, Player& p2, Player& p3);

        // Member functions
        std::string ChooseStartingPlayer();
        Board& getBoard();
        void endTurn();
           int getCurrentPlayer();
          std::string whoIsTheWinner();

           
    };
}

#endif // CATAN_HPP
