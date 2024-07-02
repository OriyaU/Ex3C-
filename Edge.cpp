//oriya7914@gmail.com
//213525512
#include "Edge.hpp"

namespace ariel {
    // Constructor
    Edge::Edge(Vertex* vertex1, Vertex* vertex2, int name)
        : vertex1(vertex1), vertex2(vertex2), name(name), owner(nullptr) {};

    // Getters
    Vertex* Edge::getVertex1() const {
        return vertex1; // Return the first vertex of the edge
    }

    Vertex* Edge::getVertex2() const {
        return vertex2; // Return the second vertex of the edge
    }

    Player* Edge::getOwner() const {
        return owner; // Return the owner of the edge (nullptr if no owner)
    }

    // Method to check if the edge contains a specific vertex
    bool Edge::containVertex(Vertex* ver) {
        // Check if the edge's vertices include the given vertex
        if (this->vertex1 == ver || this->vertex2 == ver) {
            return true; // Return true if the edge contains the vertex
        }
        return false; // Return false if the edge does not contain the vertex
    }

    // Setter to assign an owner to the edge
    void Edge::setOwner(Player* owner) {
        this->owner = owner; // Set the owner of the edge
    }

    // Print function to display details of the edge
    void Edge::printEdge() const {
        std::cout << "Edge Name: " << name << std::endl; // Print the name of the edge
        std::cout << "Vertex 1: " << vertex1->getName() << std::endl; // Print the name of the first vertex
        std::cout << "Vertex 2: " << vertex2->getName() << std::endl; // Print the name of the second vertex
        std::cout << "Owner: " << (owner ? owner->getName() : "None") << std::endl; // Print the owner's name or "None" if no owner
    }
}
