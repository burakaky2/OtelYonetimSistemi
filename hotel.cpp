#include "hotel.h"
using namespace std;
Hotel::Hotel() {
    rooms.emplace_back(101,200);
    rooms.emplace_back(102,250);
    rooms.emplace_back(103,250);
    rooms.emplace_back(201,250);
    rooms.emplace_back(202,450);//suite room

}
Hotel* Hotel::instance = nullptr;

Hotel* Hotel::getinstance(){
    if(instance==nullptr){
        instance= new Hotel();
    }
    return instance;
}
Room* Hotel::findroom(int roomnumber) {
    for (auto& room : rooms) {
        if (room. getRoomNumber() == roomnumber) {
            return &room;  // room nesnesinin adresini dönüyoruz
        }
    }
    return nullptr;  // bulunamazsa nullptr döner
}
Hotel::~Hotel(){
    delete instance;
}
