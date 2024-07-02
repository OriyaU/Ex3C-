Settlers of Catan Game

Contact: Oriya7914@gmail.com

This project is an implementation of the Settlers of Catan board game. It supports three players and includes the game board and logic methods following the rules of the game.
Game Rules

This implementation follows the rules of the popular board game Settlers of Catan. The game is designed for three players, and the objective is to be the first player to reach a certain number of victory points (10 in this implementation).

    Setup: The game board is initialized with a fixed configuration of 19 plots, each with a specific resource type (Mountains, Pasture, Forest, Agricultural, Hills, or Desert) and a number (2-12, except for the Desert plot). There are 54 vertices and 72 edges on the board.

    Initial Placement: Each player takes turns placing two settlements and two roads on the board. Settlements must be placed on unoccupied vertices that are not adjacent to any other settlements or cities. Roads must connect a player's settlement to another unoccupied vertex. Validations are performed to ensure that the initial placement follows the rules.

    Resource Collection: On each turn, two dice are rolled, and players with settlements or cities adjacent to plots with the corresponding number receive resources based on the plot's resource type. If a 7 is rolled, players with more than 7 cards must discard half of their resources (e.g., Player::discardResources).

    Development Cards: Players can draw Development Cards from a deck, which can provide various benefits, such as additional resources, roads, or victory points. The deck consists of 14 Knights, 5 Victory Points, 2 Road Building, 2 Year of Plenty, and 2 Monopoly cards. Validations are performed to ensure that players have the required resources to purchase a Development Card (e.g., Player::canBuyDevelopmentCard) and that they can properly use the card's effect (e.g., Player::getDevelopmentCard(board)).

    Building: Players can use their resources to build new settlements, cities, or roads on the board, following specific placement rules. Validations are performed to ensure that the placements follow the rules (e.g., Player::placeSettlement(int placeVertex, Board &board), Player::placeCity(int placeVertex, Board &board), Player::placeRoad(int placeEdge, Board &board)).

    Trading: Players can trade resources with other players. Validations are performed to ensure that both players have the required resources for the trade (e.g., Player::trade(Player& other, const std::string& give, const std::string& take, int gAmount, int tAmount)).

    Victory Condition: The first player to reach 10 victory points (determined by the number of settlements, cities, and Development Cards) wins the game.

Summary of Important Classes

    Catan: Manages the entire game, including setting up the board and creating three players to start the game.
    Board: Manages the game board, including plots, vertices, edges, and players. It handles resource distribution, development card drawing, and building placement rules.
    Tile: Represents a plot on the board with a specific resource type, number, and vertices.
    Vertex: Represents a vertex on the board, which can be occupied by a settlement or city.
    Edge: Represents an edge on the board, which can be occupied by a road.
    Player: Represents a player in the game, with resources, settlements, cities, roads, and development cards.
    DevelopmentCard: Represents a development card with a specific type (Knight, Victory Point, Road Building, Year of Plenty, or Monopoly).

Usage

To run the game:

    Compile the source files (Board.cpp, Tile.hpp, DevelopmentCard.cpp, Edge.cpp, Plot.cpp, Vertex.cpp, and Player.cpp) using the make command.
    Execute the game by running ./catan. This will start the game using the main function provided.

Additionally, to run tests:

    Use the command ./test to execute the test suite.