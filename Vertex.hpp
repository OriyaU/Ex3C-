#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "Player.hpp"
#include <iostream>
class Player;

namespace ariel {
    class Vertex {
    private:
        int name;
        Player *owner;
        int residence;
        std::vector<Vertex*> neighbors;
         

    public:
        // Constructor
        Vertex(int name);

        // Getters
        int getName() const;
        Player* getOwner() const;
        int getResidence() const;
        


        // Setters
        void setName(int name);
        void setOwner(Player* owner);
        void setResidence(int residence);
        void setNeighbors(Vertex* neighbor); // Note: passing by pointer
        void printVertex();
        std::vector<Vertex*> getNeighbors();
        
       

    };
}

#endif // VERTEX_HPP
