//oriya7914@gmail.com
//213525512

#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Player.hpp"
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"


namespace ariel {

    class Board {
    private:
        std::vector<Tile> tiles;
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<ariel::Player*> players;
        bool largestArmi;
         std::map<std::string, int>pile_developmentCards = {
        {"Knight", 3},
        {"Victory Point", 4},
        {"Road Building", 2},
        {"Year of Plenty", 2},
        {"Monopoly", 2}
    };
    public:
        // Constructor
        Board(Player& p1, Player& p2, Player& p3);

        // Member functions
        Vertex& getVertexBoard(int placeVertex);
        // Other functions as needed

        Edge& getEdgeBoard(int placeEdge);

       
         Tile& getTiles(int index); // Method to get a Tile reference
          int updateCards(int num);
           int updatecardsSecoundRound(Vertex* );
        int check7Cards();
        std::string getRandomDevCard(); // Generate a random development card from the pile
        bool getLargestArmi();
       std::vector<ariel::Player*> getAllPlayers();
       void setLargestArmi(bool l);
       int getIfHasLargestArmi();
       
        
    };
}

#endif // BOARD_HPP
