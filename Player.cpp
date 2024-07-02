#include "Player.hpp"
#include "Board.hpp"
#include "Tile.hpp" // Ensure this is included
#include <vector>
#include <iostream>
#include <map>
#include <stdexcept> // Include for std::runtime_error
#include <string>
using namespace std;

namespace ariel
{
    using Resource = Tile::Resource;

    // Constructor to initialize player with a name and default values
    Player::Player(std::string name)
        : name(name), turn(false), points(0), resources({{Tile::Resource::BRICK, 0},
                                                         {Tile::Resource::LUMBER, 0},
                                                         {Tile::Resource::WOOL, 0},
                                                         {Tile::Resource::IRON, 0},
                                                         {Tile::Resource::WHEAT, 0}}),
          developmentCards({{"Knight", 0},
                            {"Victory Point", 0},
                            {"Road 2 Building", 0},
                            {"Year of Plenty", 0},
                            {"Monopoly", 0}}),
          numOfKnight(0), firstRoundSettelment(0), firstRoundRodes(0), card2rouds(0) {}

    // Getter for player's name
    std::string Player::getName() const
    {
        return name;
    }

    // Getter for player's turn status
    bool Player::getTurn() const
    {
        return turn;
    }

    // Setter for player's turn status
    void Player::setTurn(bool t)
    {
        this->turn = t;
    }

    // Getter for player's points
    int Player::getPoints() const
    {
        return points;
    }

    // Method to place a settlement on the board
    int Player::placeSettelemnt(int placeVertex, Board &board)
    {
        if (!turn)
        {
            std::cerr << "Wait for your turn" << std::endl;
            return 0;
        }
        
        // Check if the position is valid (0 - 53)
        if (placeVertex < 0 || placeVertex > 53)
        {
            std::cerr << "Invalid city location." << std::endl;
            return 0;
        }

        Vertex &ver = board.getVertexBoard(placeVertex);
        std::vector<Vertex *> neighbors = ver.getNeighbors();

        // Check if neighboring vertices are owned by other players
        for (Vertex *vertex : neighbors)
        {
            if (vertex->getOwner() != nullptr && vertex->getOwner() != this)
            {
                std::cerr << "You cannot build a residence here because it's too close to another residence" << std::endl;
                return 0;
            }
        }

        // Resources required to build a settlement
        std::map<Tile::Resource, int> settlementResources = {
            {Tile::Resource::BRICK, 1},
            {Tile::Resource::LUMBER, 1},
            {Tile::Resource::WOOL, 1},
            {Tile::Resource::WHEAT, 1}};

        // Check if the player has the required resources
        if (firstRoundSettelment >= 2)
        {
            for (const auto &[resource, amount] : settlementResources)
            {
                if (this->resources[resource] < amount)
                {
                    std::cerr << "You don't have enough resources to place a settlement." << std::endl;
                    return 0;
                }
            }

            // Deduct the resources from the player
            for (const auto &[resource, amount] : settlementResources)
            {
                this->resources[resource] -= amount;
            }
            points++;
        }

        // Set the owner and residence type if the vertex is not owned
        if (ver.getOwner() == nullptr)
        {
            ver.setOwner(this);
            ver.setResidence(1); // Assuming 1 represents a settlement
            points++;
            std::cout << "Settelment built successfully at position: " << placeVertex << "." << std::endl;
        }
        else
        {
            // If the vertex is owned, check if it's by the same player
            if (ver.getOwner() != this)
            {
                std::cerr << "This place already belongs to another player" << std::endl;
                return 0;
            }

            // Check if the player already has a settlement here
            if (ver.getResidence() == 1)
            {
                std::cerr << "You already have a settlement here" << std::endl;
                return 0;
            }

            // Check if the player already has a city here
            if (ver.getResidence() == 2)
            {
                std::cerr << "You cannot build a settlement over your city" << std::endl;
                return 0;
            }
        }

        // If this is the second settlement, get the resources
        if (firstRoundSettelment == 1)
        {
            std::cout << "resources for player: " << ver.getOwner()->getName() << std::endl;
            std::vector<Tile *> neighborTiles;
            for (int i = 0; i < 19; i++)
            {
                Tile *t = &board.getTiles(i);

                if (t->containsVertex(&ver))
                {
                    neighborTiles.push_back(t);
                }
            }

            for (const Tile *tile : neighborTiles)
            {
                Resource resource = tile->getResource(); // Now this works
                if (resource != Tile::Resource::DESERT)
                { // Exclude desert tiles
                    this->resources[resource]++;
                }
            }
        }

        firstRoundSettelment++;
        return 1;
    }

    // Method to place a city on the board
    int Player::placeCity(int placeVertex, Board &board)
    {
        if (!turn)
        {
            std::cerr << "Wait for your turn" << std::endl;
            return 0;
        }

        // Check if the position is valid (0 - 53)
        if (placeVertex < 0 || placeVertex > 53)
        {
            std::cerr << "Invalid city location." << std::endl;
            return 0;
        }

        // Check if it's the first two rounds
        if (firstRoundSettelment < 2)
        {
            std::cerr << "You cannot build a city in your first two rounds" << std::endl;
            return 0;
        }

        Vertex &ver = board.getVertexBoard(placeVertex);

        // Ensure the vertex has a settlement
        if (ver.getOwner() == nullptr)
        {
            std::cerr << "First, you have to build a settlement" << std::endl;
            return 0;
        }

        // Ensure the vertex belongs to the player
        if (ver.getOwner() != this)
        {
            std::cerr << "This place already belongs to another player" << std::endl;
            return 0;
        }

        // Ensure the player doesn't already have a city here
        if (ver.getResidence() == 2)
        {
            std::cerr << "You already have a city here" << std::endl;
            return 0;
        }

        // Resources required to build a city
        std::map<Tile::Resource, int> cityResources = {
            {Tile::Resource::BRICK, 0},
            {Tile::Resource::LUMBER, 0},
            {Tile::Resource::WOOL, 0},
            {Tile::Resource::IRON, 3},
            {Tile::Resource::WHEAT, 2}};

        // Check if the player has the required resources
        for (const auto &[resource, amount] : cityResources)
        {
            if (this->resources[resource] < amount)
            {
                std::cerr << "You don't have enough resources to build a city." << std::endl;
                return 0;
            }
        }

        // Deduct the resources from the player
        for (const auto &[resource, amount] : cityResources)
        {
            this->resources[resource] -= amount;
        }

        // Upgrade the settlement to a city
        if (ver.getResidence() == 1)
        {
            std::cerr << "You built a city over your settlement at position " << placeVertex << "." << std::endl;
            ver.setResidence(2);
            points++;
            return 1;
        }
        
        return 0;
    }
    //method to place a new road
    int Player::placeRoad(int placeEdge, Board &board)
    {
        if (!turn)
        {
            std::cerr << "Wait for your turn" << std::endl;
            return 0;
        }

        // Check if it's a valid position 0 - 73
        if (placeEdge < 0 || placeEdge > 73)
        {
            std::cerr << "Invalid road location." << std::endl;
            return 0;
        }

        Edge &edgeToBuild = board.getEdgeBoard(placeEdge);
        if (edgeToBuild.getOwner() != nullptr)
        {
            std::cerr << "This road is already owned." << std::endl;
            return 0;
        }

        Vertex *a = edgeToBuild.getVertex1();
        Vertex *b = edgeToBuild.getVertex2();
        bool hasResidenceOwner = (a->getOwner() == this || b->getOwner() == this);
        bool haveEdgeNeighbors = false;

        for (int i = 0; i < 72; i++)
        {
            Edge neighborsEdge = board.getEdgeBoard(i);
            if (neighborsEdge.containVertex(a) || neighborsEdge.containVertex(b))
            {
                if (neighborsEdge.getOwner() == this)
                {
                    haveEdgeNeighbors = true;
                    break;
                }
            }
        }

        if (!haveEdgeNeighbors && !hasResidenceOwner)
        {
            std::cerr << "You can build only next to one of your roads or residences." << std::endl;
            return 0;
        }

        if (this->firstRoundRodes >= 2 && card2rouds > 0)
        {
            // The resources required to build a road
            std::map<Tile::Resource, int> RoadResources = {
                {Tile::Resource::BRICK, 1},
                {Tile::Resource::LUMBER, 1},
                {Tile::Resource::WOOL, 0},
                {Tile::Resource::WHEAT, 0}};

            // Check if the player has the required cards
            for (const auto &[resource, amount] : RoadResources)
            {
                if (this->resources[resource] < amount)
                {
                    std::cerr << "You don't have enough resources to build a road." << std::endl;
                    return 0;
                }
            }

            // Deduct the resources from the player
            for (const auto &[resource, amount] : RoadResources)
            {
                this->resources[resource] -= amount;
            }
        }

        edgeToBuild.setOwner(this);
        firstRoundRodes++;
        card2rouds--;

        std::cout << "Road built successfully at position " << placeEdge << "." << std::endl;
        return 1;
    }

    void Player::printPlayerData() const
    {
        std::cout << "Player Name: " << name << std::endl;
        std::cout << "Turn: " << (turn ? "Active" : "Inactive") << std::endl;
        std::cout << "Points: " << points << std::endl;

        std::cout << "Resources:" << std::endl;
        for (const auto &[resource, amount] : resources)
        {
            std::cout << static_cast<int>(resource) << ": " << amount << std::endl;
        }

        std::cout << "Development Cards:" << std::endl;
        for (const auto &[card, count] : developmentCards)
        {
            std::cout << card << ": " << count << std::endl;
        }

        std::cout << "First Round Settlement: " << firstRoundSettelment << std::endl;
        std::cout << "First Sound Rodes: " << firstRoundRodes << std::endl;
    }
    // rool dice when dice roll is random
    int Player::rollDice(Board *board)
    {
      
        if (!turn)
        {
            std::cerr << "Wait for your turn" << std::endl;
            return 0;
        }
      
        // Seed the random number generator
        srand(static_cast<unsigned int>(time(nullptr)));

        // Generate random numbers for two dice rolls
        int diceRoll1 = rand() % 6 + 1;
        int diceRoll2 = rand() % 6 + 1;
        

        // Calculate and return the sum of the two dice rolls
        int sum = diceRoll1 + diceRoll2;
        std::cout << "the outcome of the rollDice is: " << sum << std::endl;

        if (sum == 7)
        {
            board->check7Cards();
        }
        else
        {
            board->updateCards(sum);
        }
        return sum;
    }
// rool dice when i choose the number
    int Player::rollDice(int num, Board *board)
    {

        if (!turn)
        {
            std::cerr << "Wait for your turn" << std::endl;
            return 0;
        }

        int sum = num;
        std::cout << "the outcome of the rollDice is: " << sum << std::endl;

        if (sum == 7)
        {
            board->check7Cards();
        }
        else
        {
            board->updateCards(sum);
        }
        return sum;
    }

    std::map<Tile::Resource, int> &Player::getResources()

    {
        return resources;
    }

    Tile::Resource Player::stringToResource(const std::string &resource)
    {
        if (resource == "brick")
            return Tile::Resource::BRICK;
        if (resource == "lumber")
            return Tile::Resource::LUMBER;
        if (resource == "wool")
            return Tile::Resource::WOOL;
        if (resource == "wheat")
            return Tile::Resource::WHEAT;
        if (resource == "iron")
            return Tile::Resource::IRON;
        throw std::invalid_argument("Unknown resource: " + resource);
    }
//buing development card 
    int Player::getDevelopmentCard(Board &board)
    {
        if (this->turn == false)
        {
            std::cerr << "It is not your turn." << std::endl;
            return 0;
        }
        // The resources required to buy development card
        std::map<Tile::Resource, int> developmentResources = {
            {Tile::Resource::BRICK, 0},
            {Tile::Resource::LUMBER, 0},
            {Tile::Resource::WOOL, 1},
            {Tile::Resource::IRON, 1},
            {Tile::Resource::WHEAT, 1}};
        for (const auto &[resource, amount] : developmentResources)
        {
            if (this->resources[resource] < amount)
            {
                std::cerr << "You don't have enough resources to buy development card." << std::endl;
                return 0;
            }
        }
        // get the resources from the player
        for (const auto &[resource, amount] : developmentResources)
        {
            this->resources[resource] -= amount;
        }
        std::string randomCard = board.getRandomDevCard();
        this->developmentCards[randomCard] = this->developmentCards[randomCard] + 1;
        std::cout << "Development card " << randomCard << " bought successfully." << std::endl;
        return 1;
    }
//function that player choose when to use the Development card
    int Player::usingDevelopmentCard(std::string card, Board &board)
    {
        if (this->turn == false)
        {
            std::cerr << "It is not your turn." << std::endl;
            return 0;
        }
        if (this->developmentCards[card] < 1)
        {
            std::cerr << "You don't didnt buy this development card so you can not use it" << std::endl;
            return 0;
        }
        if (card == "Knight" && !board.getLargestArmi())
        {
            points += 2;
            std::cout << getName() << " has the largest army." << std::endl;
            board.setLargestArmi(true);
        }
        if (card == "Victory Point")
        {
            this->points = this->points + 1;
            std::cerr << "add one to your points succsefully" << std::endl;
            return 1;
        }
        if (card == " 2 Road Building")
        {
            cout << "you can now build you rouds";
            card2rouds = 2;
        }
        if (card == "Monopoly")
        {
            // asuming he will want the the smallest type ofcards
            Tile::Resource small;
            int large = 10;
            for (const auto &[resource, amount] : resources)
            {
                if (large > amount)
                {
                    large = amount;
                    small = resource;
                }
            }
            int count = 0;
            std::vector<ariel::Player *> players = board.getAllPlayers();
            {
                for (Player *player : players)
                {
                    if (this == player)
                    {
                        continue;
                    }
                    count += player->getResources()[small];
                    player->getResources()[small] = 0;
                }
                resources[small] = count;
            }
            std::cerr << "uppdate tour cards monopoly" << std::endl;
            return 1;
        }
        // find the 2 card withthe min amount- and add them to the player's dev cards
        if (card == "Year of Plenty")
        {
            Tile::Resource small;
            Tile::Resource smallest;

            int large = 10;
            for (const auto &[resource, amount] : resources)
            {
                if (large > amount)
                {
                    large = amount;
                    small = smallest;
                    smallest = resource;
                }
            }
            this->getResources()[small] += 1;
            this->getResources()[smallest] += 1;

            std::cerr << "uppdate tour cards monopoly" << std::endl;
            return 1;
        }
        return 0;
    }

    void Player::setNumberOfnight( Board &board)
    {
        this->numOfKnight=3;
      
       board.setLargestArmi(true);
    
        

    }

    void Player::setPoints()
    {
        this->points=10;
    }
// punction of the trading between the players
int Player::trading(Player &other, const std::string &give, const std::string &take, int gAmount, int tAmount)
{

    if (this->turn == false)
    {
        std::cerr << "It is not your turn." << std::endl;
        return 0;
    }

    if (this == &other)
    {
        std::cerr << " you Can not trade with yourself." << std::endl;
        return 0;
    }

    std::cout << this->name << " wants to give " << gAmount << " " << give << ". In return he wants " << tAmount << " " << take << " from " << other.name << "." << std::endl;

    int input;
    
    try
    {
        cout << other.name << " , do you want to do the trading? (Y=1/n=0): " << endl;
        std::cin >> input;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"your answer is invalid" << '\n';
        return 0;
    }
    if(input!=0&&input!=1){
        std::cerr <<"your answer is invalid. please try again" << '\n';
        return 0;
    }
    
    

    if (input == 1)
    {
        Tile::Resource giveR = stringToResource(give);
        Tile::Resource takeR = stringToResource(take);

        if (this->resources[giveR] >= gAmount && other.resources[takeR] >= tAmount)
        {
            this->resources[giveR] -= gAmount;
            this->resources[takeR] += tAmount;
            other.resources[takeR] -= tAmount;
            other.resources[giveR] += gAmount;

            std::cout << "the trade is done" << std::endl;
            return 1;
        }
        else
        {
            std::cerr << "at list one of you dont have enough resources to complite  the trade" << std::endl;
        }
    }
    else
    {
        std::cout << other.name << " , do  not want to do the trade" << std::endl;
    }
    return 0;
}

}