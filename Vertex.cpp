#include "Vertex.hpp"

namespace ariel {
    // Constructor for Vertex class
    Vertex::Vertex(int name) : name(name), owner(nullptr), residence(0) {}

    // Getter for the name of the vertex
    int Vertex::getName() const {
        return name;
    }

    // Getter for the owner of the vertex (which is a pointer to a Player object)
    Player* Vertex::getOwner() const {
        return owner;
    }

    // Getter for the residence level of the vertex
    int Vertex::getResidence() const {
        return residence;
    }

    // Getter for the neighboring vertices of this vertex
    std::vector<Vertex *> Vertex::getNeighbors() {
        return neighbors;
    }

    // Setter for the name of the vertex
    void Vertex::setName(int name) {
        this->name = name;
    }

    // Setter for the owner of the vertex
    void Vertex::setOwner(Player* owner) {
        this->owner = owner;
    }

    // Setter for the residence level of the vertex
    void Vertex::setResidence(int residence) {
        this->residence = residence;
    }

    // Adds a neighboring vertex to the list of neighbors
    void Vertex::setNeighbors(Vertex* neighbor) {
        neighbors.push_back(neighbor);
    }

    // Print detailed information about the vertex
    void Vertex::printVertex() {
        std::cout << "Vertex Name: " << name << std::endl;
        
        // Print the owner's name if it exists, otherwise print "None"
        std::cout << "Owner: " << (owner ? owner->getName() : "None") << std::endl;

        // Print the residence level of the vertex
        std::cout << "Residence Level: " << residence << std::endl;

        // Print the names of the neighboring vertices
        std::cout << "Neighbors: ";
        for (const auto& neighbor : neighbors) {
            std::cout << neighbor->getName() << " ";
        }
        std::cout << std::endl;
    }
}
