#pragma once
#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <string>

namespace ariel
{
    // Forward declarations
    class Vertex;

    // Class declaration
    class Tile
    {
    public:
        // Enums declaration
        enum class LandType
        {
            FOREST,       // yields wood
            HILLS,        // yields bricks
            PASTURE,      // yields wool
            AGRICULTURAL, // yields oats
            MOUNTAINS,    // yields iron
            DESERT        // yields nothing
        };

        enum class Resource
        {
            BRICK,
            LUMBER,
            WOOL,
            WHEAT,
            IRON,
            DESERT,
            INVALID
        };

        // Constructor
        Tile(int name, int token, LandType type, Resource typeR, std::vector<Vertex *> vertices);

        // Getters
        LandType getType() const;
        int getName() const;
        Resource getResource() const;
        std::vector<Vertex *> getVertices() const;
        int getToken();

        // Setters
        void setType(LandType type);
        void setName(int name);
        void setVertices(std::vector<Vertex *> vertices);

        bool containsVertex(Vertex *v);
        void printTile();
        Resource stringToResource(const std::string& resourceStr);


    private:
        int name;
        int token;
        LandType type;
        Resource typeR;
        std::vector<Vertex *> vertices; // List of vertices associated with this tile
    };
}

#endif // TILE_HPP
