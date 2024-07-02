#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "Tile.hpp"

namespace ariel {

    class Vertex;
    class Board;

    class Player {
    private:
        std::string name;
        bool turn;
        int points;
        std::map<Tile::Resource, int> resources;
        std::map<std::string, int> developmentCards;
        int numOfKnight;
        int firstRoundSettelment;
        int firstRoundRodes;
        int card2rouds;

    public:
        // Constructor
        Player(std::string name);

        // Member functions
        std::string getName() const;
        bool getTurn() const;
        void setTurn(bool t);
        int getPoints() const;
        int placeSettelemnt(int placeVertex, Board &board);
        int placeCity(int placeVertex, Board& board);
        int placeRoad(int placeEdge, Board& board);
        void printPlayerData() const;
        int rollDice(Board* board);
        int rollDice(int num, Board* board);
        std::map<Tile::Resource, int>& getResources();
        int trading(Player& other, const std::string& give, const std::string& take, int gAmount, int tAmount);
        Tile::Resource stringToResource(const std::string& resource);
        int getDevelopmentCard(Board &board);
        int usingDevelopmentCard(std::string card, Board &board);
        void setNumberOfnight( Board &board);
        void setPoints();
    
    };
}

#endif // PLAYER_HPP
