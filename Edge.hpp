//oriya7914@gmail.com
//213525512
#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"
#include "Player.hpp"

namespace ariel
{
    class Edge
    {
    private:
        Vertex *vertex1;
        Vertex *vertex2;
        int name;
        Player *owner;

    public:
        // Constructor
        Edge(Vertex *vertex1, Vertex *vertex2, int name);

        // Getters
        Vertex *getVertex1() const;
        Vertex *getVertex2() const;
        Player *getOwner() const;
        bool containVertex(Vertex *ver);
        void setOwner(Player *owner);
        void printEdge() const;
    };
}

#endif // EDGE_HPP
