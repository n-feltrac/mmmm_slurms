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
    rm >> st;
    // cout << st << endl;
    string current = "";
    for(int i = 0; i < st.length(); i++) {
        if(st[i] == ',') {
            Tile* t = new Tile(tileset, stoi(current), i * 16, 0);
            tiles.push_back(t);
            // cout << "comma!" << endl;
            current = "";
            // i++;
        } else {
            current += st[i];
            // cout << current << endl;
        }
    }
    // CURSED DO NOT USE!!!!!!!!!!!!!!
}
