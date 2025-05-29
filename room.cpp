#include "room.h"
#include <iostream>

using namespace std;


Room::Room(int number,int günlük){
    roomnumber=number;
    günlükücret=günlük;
    misafiradı="";
    dolumu=false;
    extra=0;
}
void Room::checkin(const string& name){
    if(dolumu==false){
        misafiradı=name;
        dolumu=true;}
    else{
        //oda boş değil kiralama yapılmıyor
    }
}
void Room::checkout(int days){
    if(dolumu==true){
        int totalücret=(days*günlükücret+extra);
        misafiradı="";
        dolumu=false;
        extra=0;}
    else{
        //oda boş çıkış yapılamaz
    } }

void Room:: add(int ekstra){
    extra+=ekstra;
}

// Getter Fonksiyonları
int Room:: getRoomNumber() const{
    return roomnumber;
}

string Room:: getMisafirAdi() const{
    return misafiradı;
}

bool Room ::odadolumu(){
    return dolumu;
}
int Room::getgünlükücret() const {
    return günlükücret;
}
int Room::getExtra() const
{
    return extra;
}
