#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Catan.hpp"
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("Creating a player")
{
    // Arrange
    std::string playerName = "TestPlayer";

    // Act
    ariel::Player player(playerName);

    // Assert
    REQUIRE(player.getName() == playerName);
}
TEST_CASE("placing settelments and rouds first round")
{

    ariel::Player p1("Amit");
    ariel::Player p2("Yossi");
    ariel::Player p3("Dana");
    ariel::Catan catan(p1, p2, p3);

    ariel::Board &board = catan.getBoard(); // get the board of the game.

    cout << catan.ChooseStartingPlayer() << endl;

    // they dond have any reasorces but stiil can build becouse it the start of the game
    CHECK(p1.placeSettelemnt(16, board) == 1);
    CHECK(p1.placeRoad(28, board) == 1);
}

TEST_CASE("placing settelments not in the first round without having threasorces")
{

    ariel::Player p1("Amit");
    ariel::Player p2("Yossi");
    ariel::Player p3("Dana");
    ariel::Catan catan(p1, p2, p3);

    ariel::Board &board = catan.getBoard(); // get the board of the game.

    cout << catan.ChooseStartingPlayer() << endl;

    p1.placeSettelemnt(16, board);
    p1.placeRoad(28, board);
    p1.placeSettelemnt(43, board);
    p1.placeRoad(54, board);
    p1.printPlayerData();

    catan.endTurn();

    p2.placeSettelemnt(12, board);
    p2.placeRoad(11, board);
    p2.placeSettelemnt(30, board);
    p2.placeRoad(41, board);
    p2.printPlayerData();

    catan.endTurn();

    p3.placeSettelemnt(9, board);
    p3.placeRoad(13, board);
    p3.placeSettelemnt(22, board);
    p3.placeRoad(45, board);
    p3.printPlayerData();

    catan.endTurn();
    // p2 try to rool not in his turn
    p2.rollDice(&board);
    p1.rollDice(5, &board);

    // p1 tring to build a sttelment
    CHECK(p1.placeSettelemnt(51, board) == 0);
}

TEST_CASE("placing settelments not in the first round without having threasorces")
{

    ariel::Player p1("Amit");
    ariel::Player p2("Yossi");
    ariel::Player p3("Dana");
    ariel::Catan catan(p1, p2, p3);

    ariel::Board &board = catan.getBoard(); // get the board of the game.

    cout << catan.ChooseStartingPlayer() << endl;

    p1.placeSettelemnt(16, board);
    p1.placeRoad(28, board);
    p1.placeSettelemnt(43, board);
    p1.placeRoad(54, board);
    p1.printPlayerData();

   //MAKE SUESCOUD SETTEKMENT HE GET THE REASORSES
    CHECK(p1.getResources()[Tile::Resource::WOOL] == 0);
    CHECK(p1.getResources()[Tile::Resource::BRICK] == 0);
    CHECK(p1.getResources()[Tile::Resource::IRON] == 1);
    CHECK(p1.getResources()[Tile::Resource::LUMBER] == 2);
    CHECK(p1.getResources()[Tile::Resource::WHEAT] == 0);


    catan.endTurn();

    p2.placeSettelemnt(12, board);
    p2.placeRoad(11, board);
    p2.placeSettelemnt(30, board);
    p2.placeRoad(41, board);
    p2.printPlayerData();

    catan.endTurn();

    p3.placeSettelemnt(9, board);
    p3.placeRoad(13, board);
    p3.placeSettelemnt(22, board);
    p3.placeRoad(45, board);
    p3.printPlayerData();

    catan.endTurn();
    // p2 try to rool not in his turn
    CHECK(p2.rollDice(&board) == 0);
    CHECK(p1.rollDice(5, &board) == 5);
}

TEST_CASE("implementing game")
{
    ariel::Player p1("Amit");
    ariel::Player p2("Yossi");
    ariel::Player p3("Dana");
    ariel::Catan catan(p1, p2, p3);

    ariel::Board &board = catan.getBoard(); // get the board of the game.

    catan.ChooseStartingPlayer();
    // checking if the sttelment truly update in the vertex
    p1.placeSettelemnt(16, board);
    p1.placeRoad(28, board);
    p1.placeSettelemnt(43, board);
    p1.placeRoad(54, board);
    p1.printPlayerData();
    CHECK(board.getVertexBoard(16).getOwner() == &p1);
    CHECK(board.getEdgeBoard(54).getOwner() == &p1);

    catan.endTurn();

    p2.placeSettelemnt(12, board);
    p2.placeRoad(11, board);
    p2.placeSettelemnt(30, board);
    p2.placeRoad(41, board);
    p2.printPlayerData();

     CHECK(p1.getResources()[Tile::Resource::WOOL] == 0);
    CHECK(p1.getResources()[Tile::Resource::BRICK] == 0);
    CHECK(p1.getResources()[Tile::Resource::IRON] == 1);
    CHECK(p1.getResources()[Tile::Resource::LUMBER] == 2);
    CHECK(p1.getResources()[Tile::Resource::WHEAT] == 0);


    catan.endTurn();

    p3.placeSettelemnt(9, board);
    p3.placeRoad(13, board);
    p3.placeSettelemnt(22, board);
    p3.placeRoad(45, board);
    p3.printPlayerData();

    catan.endTurn();

    p1.rollDice(5, &board);

    catan.endTurn();
    p2.rollDice(9, &board);
    p2.placeRoad(9, board);
    // p1 tries to build a settlement  but he can't since he dont have enoght reasorses
     CHECK(p3.getDevelopmentCard(board) == 0);

    catan.endTurn();

    p3.rollDice(6, &board);
    //check ifseccsed to buy dvelopment card
    CHECK(p3.getDevelopmentCard(board) == 1);
    p3.printPlayerData();

    //ALL rool dise updeted
     
    CHECK(p3.getResources()[Tile::Resource::BRICK] == 1);
    CHECK(p3.getResources()[Tile::Resource::LUMBER] == 1);
    CHECK(p3.getResources()[Tile::Resource::WOOL] == 1);
     CHECK(p3.getResources()[Tile::Resource::WHEAT] == 0);
    CHECK(p3.getResources()[Tile::Resource::IRON] == 1);
    p3.printPlayerData();


   
    //you cant trade when it not your turn
    CHECK(p2.trading(p2, "brick", "wheat", 1, 1)==0);
    //he cant trade with himself
    CHECK(p3.trading(p3, "brick", "wheat", 1, 1)==0);
    p3.trading(p2, "brick", "wheat", 1, 1);
    p3.printPlayerData();

    //checking that now she dond have brick bur she have wheat
    CHECK(p3.getResources()[Tile::Resource::WOOL] == 1);
    CHECK(p3.getResources()[Tile::Resource::BRICK] == 0);
    CHECK(p3.getResources()[Tile::Resource::WHEAT] == 1);
    CHECK(p3.getResources()[Tile::Resource::LUMBER] == 1);
    CHECK(p3.getResources()[Tile::Resource::IRON] == 1);
 // we can see that dana have wheat now
   
   
    p3.printPlayerData();
    catan.endTurn();
    p1.rollDice(8, &board);
    p1.trading(p3, "lumber", "brick", 1, 1);

    catan.endTurn();
    p2.rollDice(3, &board);
    p2.placeRoad(40, board);
    catan.endTurn();
    p3.rollDice(3, &board);

    cout << "what they have now" << endl;
    p1.printPlayerData();
    p3.printPlayerData();

    p3.trading(p1, "iron", "lumber", 1, 2);
    p3.trading(p2, "lumber", "brick", 1, 1);

    // tring to build a roud in unvalid place
    CHECK(p3.placeRoad(64, board)==0);

    p3.placeRoad(46, board);
    p3.placeSettelemnt(26, board);
    p3.placeSettelemnt(27, board);

    catan.endTurn();
    p1.rollDice(3, &board);
    p1.trading(p3, "brick", "wheat", 1, 1);
    p1.printPlayerData();

    //tring to bould a city not over settelment
    CHECK(p1.placeCity(42, board)==0);

    //tring to bould a city over settelment when he don't have enough resources to build a city.
    CHECK(p1.placeCity(16, board)==0);

    catan.endTurn();

    p2.rollDice(10, &board);

    catan.endTurn();
    p3.rollDice(2, &board);

    catan.endTurn();
    p1.rollDice(5, &board);
    cout << "printing player data" << endl;
    p1.printPlayerData();
    CHECK(p1.placeCity(16, board)==1);

    catan.endTurn();
    // print p1 before the rool
    p1.printPlayerData();
    p2.rollDice(10, &board);
    p1.printPlayerData();

    p1.setNumberOfnight(board);
    
    //has largest update
    CHECK(board.getIfHasLargestArmi()==1);
    p1.setPoints();

    // if we reach 10 we have a winner
    CHECK(catan.whoIsTheWinner()=="Amit");
}
