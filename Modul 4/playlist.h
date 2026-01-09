#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

class Song {
public:
    std::string title;
    std::string artist;
    float duration;
    Song* next;

    Song(std::string t, std::string a, float d);
};

class Playlist {
private:
    Song* head;
    int count;

public:
    Playlist();
    ~Playlist();

    // Operasi dasar
    void addFirst(std::string title, std::string artist, float duration);
    void addLast(std::string title, std::string artist, float duration);
    void addAfterThird(std::string title, std::string artist, float duration);
    bool removeByTitle(std::string title);
    void displayAll();
    int getCount();
    bool isEmpty();
};

#endif