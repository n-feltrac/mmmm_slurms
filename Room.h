#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include "Tile.h"
#include <vector>
#include <fstream>

using namespace sf;
using namespace std;

class Room : GameObject {
    public:
        Room(string room, string tileset, vector<int> enemies); // is tileset just a vector with all positions of all tile sprites?
        void update(RenderWindow &window);
        void parseRoom(string room, string tileset); // takes a rm file for layout, tileset string for texture
    protected:
        vector<Tile> tiles; // the actual 16x14 level layout? loaded from a file???? coolll...
};

#endif