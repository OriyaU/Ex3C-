#include "Tile.hpp"
#include <iostream>

namespace ariel {

    // Constructor for Tile class
    Tile::Tile(int name, int token, LandType type, Resource typeR, std::vector<Vertex*> vertices)
        : name(name), token(token), type(type), typeR(typeR), vertices(vertices) {}

    // Getter for the type of land the tile represents
    Tile::LandType Tile::getType() const {
        return type;
    }

    // Getter for the name of the tile
    int Tile::getName() const {
        return name;
    }

    // Getter for the type of resource the tile produces
    Tile::Resource Tile::getResource() const {
        return typeR;
    }

    // Getter for the vertices associated with the tile
    std::vector<Vertex *> Tile::getVertices() const {
        return vertices;
    }

    // Getter for the token number on the tile
    int Tile::getToken() {
        return token;
    }

    // Setter for the type of land the tile represents
    void Tile::setType(LandType type) {
        this->type = type;
    }

    // Setter for the name of the tile
    void Tile::setName(int name) {
        this->name = name;
    }

    // Setter for the vertices associated with the tile
    void Tile::setVertices(std::vector<Vertex *> vertices) {
        this->vertices = vertices;
    }

    // Check if the tile contains a given vertex
    bool Tile::containsVertex(Vertex* v) {
        // Iterate through the vertices to see if the given vertex is present
        for (const auto& vertex : vertices) {
            if (vertex == v) {
                return true;
            }
        }
        return false;
    }

    // Print detailed information about the tile
    void Tile::printTile() {
        std::string landTypeStr;
        // Convert the LandType enum to a readable string
        switch (type) {
            case LandType::FOREST: landTypeStr = "Forest"; break;
            case LandType::HILLS: landTypeStr = "Hills"; break;
            case LandType::PASTURE: landTypeStr = "Pasture"; break;
            case LandType::AGRICULTURAL: landTypeStr = "Agricultural"; break;
            case LandType::MOUNTAINS: landTypeStr = "Mountains"; break;
            case LandType::DESERT: landTypeStr = "Desert"; break;
        }

        std::string resourceTypeStr;
        // Convert the Resource enum to a readable string
        switch (typeR) {
            case Resource::BRICK: resourceTypeStr = "Brick"; break;
            case Resource::LUMBER: resourceTypeStr = "Lumber"; break;
            case Resource::WOOL: resourceTypeStr = "Wool"; break;
            case Resource::WHEAT: resourceTypeStr = "Wheat"; break;
            case Resource::IRON: resourceTypeStr = "Ore"; break;
            case Resource::DESERT: resourceTypeStr = "Desert"; break;
            case Resource::INVALID: resourceTypeStr = "Invalid"; break; // Handle INVALID case
        }

        // Print tile information to the console
        std::cout << "Tile Name: " << name << "\n";
        std::cout << "Tile Token: " << token << "\n";
        std::cout << "Land Type: " << landTypeStr << "\n";
        std::cout << "Resource Type: " << resourceTypeStr << "\n";
    }

    // Convert a string representation of a resource to the corresponding Resource enum
    Tile::Resource Tile::stringToResource(const std::string& resourceStr) {
        if (resourceStr == "BRICK") return Tile::Resource::BRICK;
        if (resourceStr == "LUMBER") return Tile::Resource::LUMBER;
        if (resourceStr == "WOOL") return Tile::Resource::WOOL;
        if (resourceStr == "WHEAT") return Tile::Resource::WHEAT;
        if (resourceStr == "IRON") return Tile::Resource::IRON;
        if (resourceStr == "DESERT") return Tile::Resource::DESERT;
        return Tile::Resource::INVALID;
    }
}
