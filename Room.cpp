#include "Room.h"

Room::Room(string room, string tileset) {
    parseRoom(room, tileset);
}

void Room::update(RenderWindow &window) {
    for(Tile* t : tiles) {
        t->update(window);
    }
}

void Room::parseRoom(string room, string tileset) {
    ifstream rm(room, ios::in);
    string st;
    // rm >> st;
    // cout << st << endl;
    string current = "";
    int posX = 0;
    int posY = 0;
    while(std::getline(rm, st)) {
        for(int i = 0; i < st.length(); i++) {
            if(st[i] == ',') {
                // cout << current << endl;
                Tile* t = new Tile(tileset, stoi(current), posX * 16, posY * 16);
                tiles.push_back(t);
                // cout << posX << " and " << posY << endl;
                current = "";
                // i++;
                posX++;
                // if(posX >= 16) { // should replace with roomLength for longer rooms
                //     posX = 0;
                // }
            } else {
                current += st[i];
                // cout << current << endl;
            }
        }
        // cout << "end of line!" << endl;
        posX = 0;
        posY++;
    }
    

    // CURSED DO NOT USE!!!!!!!!!!!!!!
}
