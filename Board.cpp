//oriya7914@gmail.com
//213525512
#include "Board.hpp"
#include "Vertex.hpp"
#include <vector>
#include "Edge.hpp"
#include <iostream>
#include "Tile.hpp"


using namespace ariel;

namespace ariel
{
    Board::Board(Player &p1, Player &p2, Player &p3)
    {
        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);

        largestArmi=false;

        // Initialize vertices
        vertices.reserve(54);
        for (int i = 0; i < 54; ++i)
        {
            vertices.emplace_back(Vertex(i)); // Assuming Vertex has a constructor with parameters
        }
          // Initialize vertices nighbors
        vertices[0].setNeighbors(&vertices[1]);
        vertices[0].setNeighbors(&vertices[13]);
        vertices[1].setNeighbors(&vertices[0]);
        vertices[1].setNeighbors(&vertices[2]);
        vertices[2].setNeighbors(&vertices[1]);
        vertices[2].setNeighbors(&vertices[3]);
        vertices[3].setNeighbors(&vertices[2]);
        vertices[3].setNeighbors(&vertices[4]);
        vertices[4].setNeighbors(&vertices[3]);
        vertices[4].setNeighbors(&vertices[5]);
        vertices[5].setNeighbors(&vertices[4]);
        vertices[5].setNeighbors(&vertices[6]);
        vertices[6].setNeighbors(&vertices[5]);
        vertices[6].setNeighbors(&vertices[7]);
        vertices[7].setNeighbors(&vertices[8]);
        vertices[7].setNeighbors(&vertices[24]);
        vertices[8].setNeighbors(&vertices[7]);
        vertices[8].setNeighbors(&vertices[9]);
        vertices[8].setNeighbors(&vertices[21]);
        vertices[9].setNeighbors(&vertices[8]);
        vertices[8].setNeighbors(&vertices[4]);
        vertices[9].setNeighbors(&vertices[10]);
        vertices[10].setNeighbors(&vertices[9]);
        vertices[10].setNeighbors(&vertices[19]);
        vertices[10].setNeighbors(&vertices[11]);
        vertices[11].setNeighbors(&vertices[10]);
        vertices[11].setNeighbors(&vertices[12]);
        vertices[11].setNeighbors(&vertices[2]);
        vertices[12].setNeighbors(&vertices[11]);
        vertices[12].setNeighbors(&vertices[17]);
        vertices[12].setNeighbors(&vertices[13]);
        vertices[13].setNeighbors(&vertices[12]);
        vertices[13].setNeighbors(&vertices[0]);
        vertices[13].setNeighbors(&vertices[14]);
        vertices[14].setNeighbors(&vertices[13]);
        vertices[14].setNeighbors(&vertices[15]);
        vertices[15].setNeighbors(&vertices[16]);
        vertices[15].setNeighbors(&vertices[37]);
        vertices[16].setNeighbors(&vertices[15]);
        vertices[16].setNeighbors(&vertices[17]);
        vertices[17].setNeighbors(&vertices[16]);
        vertices[17].setNeighbors(&vertices[12]);
        vertices[17].setNeighbors(&vertices[18]);
        vertices[18].setNeighbors(&vertices[17]);
        vertices[18].setNeighbors(&vertices[19]);
        vertices[18].setNeighbors(&vertices[32]);
        vertices[19].setNeighbors(&vertices[20]);
        vertices[19].setNeighbors(&vertices[18]);
        vertices[19].setNeighbors(&vertices[10]);
        vertices[20].setNeighbors(&vertices[19]);
        vertices[20].setNeighbors(&vertices[21]);
        vertices[20].setNeighbors(&vertices[30]);
        vertices[21].setNeighbors(&vertices[8]);
        vertices[21].setNeighbors(&vertices[20]);
        vertices[21].setNeighbors(&vertices[22]);
        vertices[22].setNeighbors(&vertices[21]);
        vertices[22].setNeighbors(&vertices[23]);
        vertices[22].setNeighbors(&vertices[28]);
        vertices[23].setNeighbors(&vertices[22]);
        vertices[23].setNeighbors(&vertices[24]);
        vertices[23].setNeighbors(&vertices[25]);
        vertices[24].setNeighbors(&vertices[7]);
        vertices[24].setNeighbors(&vertices[23]);
        vertices[25].setNeighbors(&vertices[23]);
        vertices[25].setNeighbors(&vertices[26]);
        vertices[26].setNeighbors(&vertices[25]);
        vertices[26].setNeighbors(&vertices[27]);
        vertices[27].setNeighbors(&vertices[26]);
        vertices[27].setNeighbors(&vertices[28]);
        vertices[27].setNeighbors(&vertices[46]);
        vertices[28].setNeighbors(&vertices[27]);
        vertices[28].setNeighbors(&vertices[22]);
        vertices[28].setNeighbors(&vertices[29]);
        vertices[29].setNeighbors(&vertices[28]);
        vertices[29].setNeighbors(&vertices[30]);
        vertices[29].setNeighbors(&vertices[44]);
        vertices[30].setNeighbors(&vertices[29]);
        vertices[30].setNeighbors(&vertices[20]);
        vertices[30].setNeighbors(&vertices[31]);
        vertices[31].setNeighbors(&vertices[30]);
        vertices[31].setNeighbors(&vertices[42]);
        vertices[31].setNeighbors(&vertices[32]);
        vertices[32].setNeighbors(&vertices[31]);
        vertices[32].setNeighbors(&vertices[18]);
        vertices[32].setNeighbors(&vertices[33]);
        vertices[33].setNeighbors(&vertices[32]);
        vertices[33].setNeighbors(&vertices[34]);
        vertices[33].setNeighbors(&vertices[40]);
        vertices[34].setNeighbors(&vertices[33]);
        vertices[34].setNeighbors(&vertices[35]);
        vertices[34].setNeighbors(&vertices[34]);
        vertices[34].setNeighbors(&vertices[33]);
        vertices[35].setNeighbors(&vertices[34]);
        vertices[35].setNeighbors(&vertices[36]);
        vertices[35].setNeighbors(&vertices[38]);
        vertices[36].setNeighbors(&vertices[37]);
        vertices[36].setNeighbors(&vertices[35]);
        vertices[37].setNeighbors(&vertices[36]);
        vertices[37].setNeighbors(&vertices[15]);
        vertices[38].setNeighbors(&vertices[35]);
        vertices[38].setNeighbors(&vertices[39]);
        vertices[39].setNeighbors(&vertices[38]);
        vertices[39].setNeighbors(&vertices[40]);
        vertices[39].setNeighbors(&vertices[53]);
        vertices[40].setNeighbors(&vertices[41]);
        vertices[40].setNeighbors(&vertices[39]);
        vertices[40].setNeighbors(&vertices[33]);
        vertices[41].setNeighbors(&vertices[40]);
        vertices[41].setNeighbors(&vertices[42]);
        vertices[41].setNeighbors(&vertices[51]);
        vertices[42].setNeighbors(&vertices[31]);
        vertices[42].setNeighbors(&vertices[41]);
        vertices[42].setNeighbors(&vertices[43]);
        vertices[43].setNeighbors(&vertices[42]);
        vertices[43].setNeighbors(&vertices[44]);
        vertices[43].setNeighbors(&vertices[49]);
        vertices[44].setNeighbors(&vertices[43]);
        vertices[44].setNeighbors(&vertices[45]);
        vertices[44].setNeighbors(&vertices[29]);
        vertices[45].setNeighbors(&vertices[44]);
        vertices[45].setNeighbors(&vertices[46]);
        vertices[45].setNeighbors(&vertices[47]);
        vertices[46].setNeighbors(&vertices[47]);
        vertices[46].setNeighbors(&vertices[45]);
        vertices[47].setNeighbors(&vertices[45]);
        vertices[47].setNeighbors(&vertices[48]);
        vertices[48].setNeighbors(&vertices[47]);
        vertices[48].setNeighbors(&vertices[49]);
        vertices[49].setNeighbors(&vertices[48]);
        vertices[49].setNeighbors(&vertices[43]);
        vertices[49].setNeighbors(&vertices[50]);
        vertices[50].setNeighbors(&vertices[49]);
        vertices[50].setNeighbors(&vertices[51]);
        vertices[51].setNeighbors(&vertices[41]);
        vertices[51].setNeighbors(&vertices[50]);
        vertices[51].setNeighbors(&vertices[52]);
        vertices[52].setNeighbors(&vertices[51]);
        vertices[52].setNeighbors(&vertices[53]);
        vertices[53].setNeighbors(&vertices[39]);
        vertices[53].setNeighbors(&vertices[52]);

        vertices[53].printVertex();
          // Initialize edjes
        int num = 0;
        edges.push_back(Edge(&vertices[0], &vertices[13], num++));
        edges.push_back(Edge(&vertices[0], &vertices[1], num++));
        edges.push_back(Edge(&vertices[1], &vertices[2], num++));
        edges.push_back(Edge(&vertices[2], &vertices[3], num++));
        edges.push_back(Edge(&vertices[3], &vertices[4], num++));
        edges.push_back(Edge(&vertices[4], &vertices[5], num++));

        edges.push_back(Edge(&vertices[5], &vertices[6], num++));
        edges.push_back(Edge(&vertices[6], &vertices[7], num++));
        edges.push_back(Edge(&vertices[4], &vertices[9], num++));
        edges.push_back(Edge(&vertices[2], &vertices[11], num++));

        edges.push_back(Edge(&vertices[13], &vertices[12], num++));
        edges.push_back(Edge(&vertices[12], &vertices[11], num++));
        edges.push_back(Edge(&vertices[11], &vertices[10], num++));
        edges.push_back(Edge(&vertices[10], &vertices[9], num++));
        edges.push_back(Edge(&vertices[9], &vertices[8], num++));
        edges.push_back(Edge(&vertices[8], &vertices[7], num++));
        edges.push_back(Edge(&vertices[7], &vertices[24], num++));
        edges.push_back(Edge(&vertices[24], &vertices[23], num++));

        edges.push_back(Edge(&vertices[23], &vertices[25], num++));
        edges.push_back(Edge(&vertices[22], &vertices[23], num++));
        edges.push_back(Edge(&vertices[21], &vertices[22], num++));
        edges.push_back(Edge(&vertices[8], &vertices[21], num++));
        edges.push_back(Edge(&vertices[20], &vertices[21], num++));
        edges.push_back(Edge(&vertices[19], &vertices[20], num++));

        edges.push_back(Edge(&vertices[10], &vertices[19], num++));
        edges.push_back(Edge(&vertices[18], &vertices[19], num++));

        edges.push_back(Edge(&vertices[17], &vertices[18], num++));
        edges.push_back(Edge(&vertices[12], &vertices[17], num++));
        edges.push_back(Edge(&vertices[16], &vertices[17], num++));
        edges.push_back(Edge(&vertices[15], &vertices[16], num++));
        edges.push_back(Edge(&vertices[14], &vertices[15], num++));
        edges.push_back(Edge(&vertices[14], &vertices[13], num++));
        edges.push_back(Edge(&vertices[37], &vertices[15], num++));
        edges.push_back(Edge(&vertices[37], &vertices[36], num++));
        edges.push_back(Edge(&vertices[36], &vertices[35], num++));
        edges.push_back(Edge(&vertices[35], &vertices[34], num++));

        edges.push_back(Edge(&vertices[16], &vertices[34], num++));
        edges.push_back(Edge(&vertices[34], &vertices[33], num++));
        edges.push_back(Edge(&vertices[33], &vertices[32], num++));
        edges.push_back(Edge(&vertices[18], &vertices[32], num++));
        edges.push_back(Edge(&vertices[32], &vertices[31], num++));
        edges.push_back(Edge(&vertices[31], &vertices[30], num++));
        edges.push_back(Edge(&vertices[20], &vertices[30], num++));
        edges.push_back(Edge(&vertices[30], &vertices[29], num++));
        edges.push_back(Edge(&vertices[29], &vertices[28], num++));
        edges.push_back(Edge(&vertices[22], &vertices[28], num++));

        edges.push_back(Edge(&vertices[28], &vertices[27], num++));
        edges.push_back(Edge(&vertices[27], &vertices[26], num++));
        edges.push_back(Edge(&vertices[25], &vertices[26], num++));
        edges.push_back(Edge(&vertices[27], &vertices[46], num++));
        edges.push_back(Edge(&vertices[45], &vertices[46], num++));
        edges.push_back(Edge(&vertices[44], &vertices[45], num++));
        edges.push_back(Edge(&vertices[29], &vertices[44], num++));
        edges.push_back(Edge(&vertices[43], &vertices[44], num++));
        edges.push_back(Edge(&vertices[42], &vertices[43], num++));

        edges.push_back(Edge(&vertices[31], &vertices[42], num++));
        edges.push_back(Edge(&vertices[41], &vertices[42], num++));
        edges.push_back(Edge(&vertices[40], &vertices[41], num++));
        edges.push_back(Edge(&vertices[33], &vertices[40], num++));
        edges.push_back(Edge(&vertices[39], &vertices[40], num++));
        edges.push_back(Edge(&vertices[38], &vertices[39], num++));
        edges.push_back(Edge(&vertices[35], &vertices[38], num++));
        edges.push_back(Edge(&vertices[39], &vertices[53], num++));

        edges.push_back(Edge(&vertices[53], &vertices[52], num++));
        edges.push_back(Edge(&vertices[52], &vertices[51], num++));
        edges.push_back(Edge(&vertices[41], &vertices[51], num++));
        edges.push_back(Edge(&vertices[51], &vertices[50], num++));
        edges.push_back(Edge(&vertices[50], &vertices[49], num++));
        edges.push_back(Edge(&vertices[49], &vertices[48], num++));
        edges.push_back(Edge(&vertices[48], &vertices[47], num++));
        edges.push_back(Edge(&vertices[45], &vertices[47], num++));

        // Initialize tiles
        std::vector<Vertex *> tile0Vertices = {&vertices[0], &vertices[1], &vertices[2], &vertices[11], &vertices[12], &vertices[13]};
        Tile tile0(0, 2, Tile::LandType::AGRICULTURAL, Tile::Resource::WHEAT, tile0Vertices);
        tiles.push_back(tile0);

        // Initialize tiles
        std::vector<Vertex *> tile1Vertices = {&vertices[2], &vertices[3], &vertices[4], &vertices[9], &vertices[10], &vertices[11]};
        Tile tile1(1, 4, Tile::LandType::PASTURE, Tile::Resource::WOOL, tile1Vertices);
        tiles.push_back(tile1);

        std::vector<Vertex *> tile2Vertices = {&vertices[4], &vertices[5], &vertices[6], &vertices[8], &vertices[9], &vertices[7]};
        Tile tile2(2, 6, Tile::LandType::AGRICULTURAL, Tile::Resource::WHEAT, tile2Vertices);
        tiles.push_back(tile2);

        std::vector<Vertex *> tile3Vertices = {&vertices[17], &vertices[16], &vertices[12], &vertices[13], &vertices[14], &vertices[15]};
        Tile tile3(3, 5, Tile::LandType::AGRICULTURAL, Tile::Resource::WHEAT, tile3Vertices);
        tiles.push_back(tile3);

        std::vector<Vertex *> tile4Vertices = {&vertices[12], &vertices[11], &vertices[10], &vertices[18], &vertices[19], &vertices[17]};
        Tile tile4(4, 6, Tile::LandType::HILLS, Tile::Resource::BRICK, tile4Vertices);
        tiles.push_back(tile4);

        std::vector<Vertex *> tile5Vertices = {&vertices[10], &vertices[9], &vertices[8], &vertices[21], &vertices[20], &vertices[19]};
        Tile tile5(5, 9, Tile::LandType::FOREST, Tile::Resource::LUMBER, tile5Vertices);
        tiles.push_back(tile5);

        std::vector<Vertex *> tile6Vertices = {&vertices[8], &vertices[7], &vertices[24], &vertices[23], &vertices[22], &vertices[21]};
        Tile tile6(6, 5, Tile::LandType::PASTURE, Tile::Resource::WOOL, tile6Vertices);
        tiles.push_back(tile6);

        std::vector<Vertex *> tile7Vertices = {&vertices[37], &vertices[15], &vertices[16], &vertices[34], &vertices[36], &vertices[35]};
        Tile tile7(7, 10, Tile::LandType::PASTURE, Tile::Resource::WOOL, tile7Vertices);
        tiles.push_back(tile7);

        std::vector<Vertex *> tile8Vertices = {&vertices[16], &vertices[17], &vertices[18], &vertices[32], &vertices[33], &vertices[34]};
        Tile tile8(8, 3, Tile::LandType::HILLS, Tile::Resource::BRICK, tile8Vertices);
        tiles.push_back(tile8);

        std::vector<Vertex *> tile9Vertices = {&vertices[18], &vertices[19], &vertices[20], &vertices[30], &vertices[31], &vertices[32]};
        Tile tile9(9, 0, Tile::LandType::DESERT, Tile::Resource::DESERT, tile9Vertices);
        tiles.push_back(tile9);

        std::vector<Vertex *> tile10Vertices = {&vertices[20], &vertices[21], &vertices[22], &vertices[28], &vertices[29], &vertices[30]};
        Tile tile10(10, 11, Tile::LandType::HILLS, Tile::Resource::BRICK, tile10Vertices);
        tiles.push_back(tile10);

        std::vector<Vertex *> tile11Vertices = {&vertices[22], &vertices[23], &vertices[25], &vertices[26], &vertices[27], &vertices[28]};
        Tile tile11(11, 9, Tile::LandType::MOUNTAINS, Tile::Resource::IRON, tile11Vertices);
        tiles.push_back(tile11);

        std::vector<Vertex *> tile12Vertices = {&vertices[35], &vertices[34], &vertices[33], &vertices[40], &vertices[39], &vertices[38]};
        Tile tile12(12, 11, Tile::LandType::FOREST, Tile::Resource::LUMBER, tile12Vertices);
        tiles.push_back(tile12);

        std::vector<Vertex *> tile13Vertices = {&vertices[33], &vertices[32], &vertices[31], &vertices[40], &vertices[41], &vertices[42]};
        Tile tile13(13, 12, Tile::LandType::AGRICULTURAL, Tile::Resource::WHEAT, tile13Vertices);
        tiles.push_back(tile13);

        std::vector<Vertex *> tile14Vertices = {&vertices[31], &vertices[30], &vertices[29], &vertices[44], &vertices[43], &vertices[42]};
        Tile tile14(14, 10, Tile::LandType::FOREST, Tile::Resource::LUMBER, tile14Vertices);
        tiles.push_back(tile14);

        std::vector<Vertex *> tile15Vertices = {&vertices[29], &vertices[28], &vertices[27], &vertices[46], &vertices[45], &vertices[44]};
        Tile tile15(15, 11, Tile::LandType::PASTURE, Tile::Resource::WOOL, tile15Vertices);
        tiles.push_back(tile15);

        std::vector<Vertex *> tile16Vertices = {&vertices[39], &vertices[40], &vertices[41], &vertices[51], &vertices[52], &vertices[53]};
        Tile tile16(16, 4, Tile::LandType::HILLS, Tile::Resource::BRICK, tile16Vertices);
        tiles.push_back(tile16);

        std::vector<Vertex *> tile17Vertices = {&vertices[41], &vertices[42], &vertices[43], &vertices[49], &vertices[50], &vertices[51]};
        Tile tile17(17, 3, Tile::LandType::MOUNTAINS, Tile::Resource::IRON, tile17Vertices);
        tiles.push_back(tile17);

        std::vector<Vertex *> tile18Vertices = {&vertices[43], &vertices[44], &vertices[45], &vertices[47], &vertices[48], &vertices[49]};
        Tile tile18(18, 8, Tile::LandType::FOREST, Tile::Resource::LUMBER, tile18Vertices);
        tiles.push_back(tile18);

        // // Printing tiles to check if they are initialized correctly
        // for (Tile &tile : tiles) {
        //     tile.printTile();
        // }
    }
    Vertex &Board::getVertexBoard(int num)
    {
        return vertices[num];
    }
    Edge &Board::getEdgeBoard(int placeEdge)
    {

        return edges[placeEdge];
    }

    Tile &Board::getTiles(int index)
    {
        return tiles[index]; // Assuming 'tiles' is a vector of Tile objects
    }

    int Board::updateCards(int num)
    {
        for (Tile tile : tiles)
        {
            
            if (tile.getToken() == num)//dont need to check if its  a desert because it token is 0 so it will never roll
            {
                std::vector<Vertex *> vertexesT = tile.getVertices();
                for (Vertex *ver : vertexesT)
                {
                    if (ver->getOwner() != nullptr)
                    {
                        Tile::Resource resource = tile.getResource();
                    int resourceAmount = (ver->getResidence() == 1) ? 1 : (ver->getResidence()== 2) ? 2 : 0;
                    ver->getOwner()->getResources()[resource] += resourceAmount;
                    }
                }
            }
        }
        return 1;
}
    }

 std::string Board::getRandomDevCard() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create a list of available cards
    std::vector<std::string> availableCards;
    for (const auto& [name, amount] : pile_developmentCards) {
        if (amount > 0) {
            availableCards.push_back(name);
        }
    }

    // Check if there are any available cards
    if (availableCards.empty()) {
        return "none";
    }

    // Randomly select a card from the available cards
    int randomIndex = rand() % availableCards.size();
    std::string selectedCard = availableCards[randomIndex];

   

    return selectedCard;
}
bool ariel::Board::getLargestArmi()
{
    return this->largestArmi;
}

std::vector<ariel::Player *> ariel::Board::getAllPlayers()
{
    return std::vector<ariel::Player *>();
}

void ariel::Board::setLargestArmi(bool l)
{
    this->largestArmi=l;
}

//making sure that if a player have 3 knights he wil get it first. and if somone else have the sam number after hime he wont get it
 int ariel::Board::getIfHasLargestArmi()
{
    if(this->largestArmi)
    {
        return 1;
    }
    else{
        return 0;
    }
}

    int Board::check7Cards() {
    for(Player* player : players) {
        std::map<Tile::Resource, int> playerResources = player->getResources();
     
        int totalResources = 0;
        for (const auto& entry : playerResources) {
            totalResources += entry.second;
        }

        if (totalResources > 7) {
            std::cout << "You need to return half of your cards.\n";
            std::string input;
            int i = 0;
            
            while (i < totalResources / 2) {
                std::cout << "Enter the kind of resource you want to remove: ";
                std::cin >> input;

                // Convert the input string to the Resource enum
                Tile::Resource resource;
                try {
                    resource = player->stringToResource(input);
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid resource name entered.\n";
                    continue;
                }

                // Check if the resource is valid and exists in the player's resources
                if (playerResources.count(resource) && playerResources[resource] > 0) {
                    playerResources[resource]--;
                    std::cout << "Reduced " << input << " by one. New count: " << playerResources[resource] << std::endl;
                    i++;
                } else {
                    std::cout << "No more " << input << " left to reduce or invalid resource.\n";
                }
            }
        }
    }
    return 0;
}


    //   Tile(int name, int token, LandType type, Resource typeR);

    //     enum class LandType
    // {
    //     FOREST,       // yields wood
    //     HILLS,        // yields bricks
    //     PASTURE,      // yields wool
    //     AGRICULTURAL, // yields wheat
    //     MOUNTAINS,    // yields iron
    //     DESERT        // yields nothing
    // };

    // Initialize tiles and edges if needed
    // tiles.reserve(...);
    // edges.reserve(...);
    // Initialize tiles and edges here similarly if needed.
    //   }
    //}



