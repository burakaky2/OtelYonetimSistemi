#ifndef HOTEL_H
#define HOTEL_H
#include "room.h"
#include <vector>
using namespace std;

class Hotel
{
private:
    static Hotel*instance;
    vector<Room> rooms;
    Hotel(); //Private Constructor for singleton pattern

public:
    static Hotel* getinstance();
    Room*findroom(int roomnumber);
    ~Hotel();

};

#endif // HOTEL_H
