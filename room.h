#ifndef ROOM_H
#define ROOM_H
#include<string>
using namespace std;
class Room
{
private:
    int roomnumber;
    string misafiradı;
    int günlükücret;
    bool dolumu;
    int extra;

public:
    Room(int number,int günlük);
    void checkin(const string& name);
    void checkout(int days);
    void add(int ekstra);
    // Getter Fonksiyonları
    int getRoomNumber() const;
    string getMisafirAdi() const;
    bool odadolumu();
    int getgünlükücret()const;
    int getExtra() const;
};

#endif // ROOM_H
