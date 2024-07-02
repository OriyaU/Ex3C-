//oriya7914@gmail.com
//213525512
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

using namespace std;
using namespace ariel;

int main()
{

  cout << "creating players..." << endl;
  ariel::Player p1("Amit");
  ariel::Player p2("Yossi");
  ariel::Player p3("Dana");
  ariel::Catan catan(p1, p2, p3);

  cout << "Getting the game board..." << endl;
  ariel::Board &board = catan.getBoard(); // get the board of the game.

  cout << "coosing starting player: " << catan.ChooseStartingPlayer() << endl; // should print the name of the starting player, assume it is Amit.

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
  // //it acctully update player cards
  // p1.printPlayerData();
  // p2.printPlayerData();
  // p3.printPlayerData();

  // p1 tring to build a sttelment
  p1.placeSettelemnt(51, board);

  catan.endTurn();
  p2.rollDice(9, &board);
  p2.placeRoad(9, board);

  catan.endTurn();

  p3.rollDice(6, &board);
  p3.getDevelopmentCard(board);

  // it acctully update player cards

  
  p3.printPlayerData();

  p2.trading(p2, "brick", "wheat", 1, 1);
  p3.trading(p3, "brick", "wheat", 1, 1);
  p3.trading(p2, "brick", "wheat", 1, 1);

  
  // we can see that dana have wheat now
  p3.printPlayerData();
  catan.endTurn();
  p1.rollDice(8,&board);
  p1.trading(p3, "lumber","brick" ,1,1);

  catan.endTurn();
  p2.rollDice(3,&board);
  p2.placeRoad(40, board);
  catan.endTurn();
  p3.rollDice(3,&board);

  cout<<"what they have now"<< endl;
  p1.printPlayerData();
  p3.printPlayerData();

  p3.trading(p1,"iron", "lumber", 1, 2);
  p3.trading(p2,"lumber","brick", 1, 1);

  //tring to build a roud in unvalid place
  p3.placeRoad(64, board);

  p3.placeRoad(46,board);
  p3.placeSettelemnt(26, board);
  p3.placeSettelemnt(27,board);

  catan.endTurn();
  p1.rollDice(3,&board);
  p1.trading(p3,"brick","wheat",1,1);
  p1.printPlayerData();
  p1.placeCity(42,board);
  p1.placeCity(16,board);

  catan.endTurn();

  p2.rollDice(10,&board);

  catan.endTurn();
  p3.rollDice(2,&board);

  catan.endTurn();
  p1.rollDice(5,&board);
  cout<<"printing player data"<<endl;
  p1.printPlayerData();
  p1.placeCity(16,board);

  catan.endTurn();
  //print p1 before the rool
  p1.printPlayerData();
  p2.rollDice(10,&board);
  p1.printPlayerData();
// it prin none because none of them have 10 points yet
  cout<<catan.whoIsTheWinner()<<endl;

}
