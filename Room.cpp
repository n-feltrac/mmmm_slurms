#include "Room.h"

Room::Room(string room, string tileset, vector<int> enemies) {
    parseRoom(room, tileset);
}

void Room::update(RenderWindow &window) {
    for(Tile t : tiles) {
        t.update(window);
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
            // tiles.push_back(Tile(tileset, stoi(current), i*16, 0));
            cout << "comma!" << endl;
            i++;
        } else {
            current += st[i];
            cout << current << endl;

        }
    }
    // CURSED DO NOT USE!!!!!!!!!!!!!!
}
