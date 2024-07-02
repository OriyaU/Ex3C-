//oriya7914@gmail.com
//213525512
#include "Catan.hpp"
#include "Board.hpp"

namespace ariel {
    // Constructor initializes players and board
    Catan::Catan(Player& p1, Player& p2, Player& p3)
        : player1(p1), player2(p2), player3(p3), board(Board(p1, p2, p3)) {
            currentPlayer = 1; // Initialize current player
        }

    // Method to choose the starting player
    std::string Catan::ChooseStartingPlayer() {
        player1.setTurn(true); // Set player 1's turn to true
        return player1.getName(); // Return player 1's name as the starting player
    }

    // Method to get the game board
    Board& Catan::getBoard() {
        return this->board; // Return a reference to the game board
    }

    // Method to end the current player's turn and switch to the next player
    void Catan::endTurn() {
        // Display message indicating end of turn for the current player
        std::cout << "Player " << currentPlayer << " has ended his turn." << std::endl;

        // Determine and switch to the next player
        if (player1.getTurn()) {
            player1.setTurn(false); // Set current player 1's turn to false
            player2.setTurn(true);  // Set player 2's turn to true
            currentPlayer = 2;      // Update current player to player 2
        } else if (player2.getTurn()) {
            player2.setTurn(false); // Set current player 2's turn to false
            player3.setTurn(true);  // Set player 3's turn to true
            currentPlayer = 3;      // Update current player to player 3
        } else if (player3.getTurn()) {
            player1.setTurn(true);  // Set player 1's turn to true (cycle back to player 1)
            player3.setTurn(false); // Set current player 3's turn to false
            currentPlayer = 1;      // Update current player to player 1
        }

        // Display message indicating whose turn it is now
        std::cout << "It's player " << currentPlayer << " turn now." << std::endl;
    }

    // Method to get the current player number
    int Catan::getCurrentPlayer() {
        return currentPlayer; // Return the current player number
    }

    // Method to determine the winner based on points
    std::string Catan::whoIsTheWinner() {
        // Check each player's points to determine the winner
        if (player1.getPoints() > 9) {
            return player1.getName(); // Return player 1's name if they have more than 9 points
        } else if (player2.getPoints() > 9) {
            return player2.getName(); // Return player 2's name if they have more than 9 points
        } else if (player3.getPoints() > 9) {
            return player3.getName(); // Return player 3's name if they have more than 9 points
        } else {
            return "none"; // Return "none" if no player has more than 9 points
        }
    }
} // namespace ariel
