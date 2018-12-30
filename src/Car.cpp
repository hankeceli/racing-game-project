//
// Created by burak on 12/28/18.
//

#include "Car.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#define waitkey rlutil::anykey(" ")

int choosenColor;
int choosenLength;
int choosenWidth;
int controller=0;

Car::Car() {
    carLen = 5;
    carWid = 5;
    carColor=4;

}

int Car::carType(int carType) {

    if (carType==0){
        carLen = 5;
        carWid = 5;
        choosenLength=5;
        choosenWidth=5;
        carColor=getcarColor();
    }
    else if (carType==1){
        carLen=7;
        carWid=2;
        choosenLength=7;
        choosenWidth=2;
        carColor=getcarColor();
    }
    else if (carType==2){
        carLen = getcarLen();
        choosenLength=getcarLen();
        carWid = getcarWidth();
        choosenWidth=getcarWidth();
        carColor=getcarColor();
        choosenColor=getcarColor();
    }
    else{
        cout << "carType error"<<endl;
    }






    return 0;
}

int Car::getcarLen() {
    return carLen;
}

void Car::setcarLen(int Length) {
    this->carLen=Length;
}

int Car::getcarWidth() {
    return carWid;
}

void Car::setcarWidth(int Width) {
    this->carWid=Width;
}

int Car::getcarColor() {
    return carColor;
}

void Car::setcarColor(int Color) {
    this->carColor=Color;
    choosenColor=Color;
    controller=1;
}

void Car::carShowup(int x,int y) {
    waitkey;
    int i,j;
    setColor(carColor);
    setBackgroundColor(carColor);
    for(i=0;i<carLen;i++){
        for(j=0;j<carWid;j++){
            locate(x+j,y+i);
            cout << " ";
        }
        cout << endl;
    }
    setBackgroundColor(0);

    setColor(15);
    waitkey;
}

void Car::gameCar(int x, int y) {

    setBackgroundColor(choosenColor);
    locate(x,y);
    int i,j;
    for(i=0;i<choosenLength;i++){
        for(j=0;j<choosenWidth;j++){
            locate(x+j,y+i);
            cout << " ";
        }
        cout << endl;
    }
    setBackgroundColor(0);

    setColor(15);

}

void Car::gameCarremove(int x, int y) {
    if(controller==0){
        choosenWidth=carWid;
        choosenColor=carColor;
        choosenLength=carLen;
    }
    setBackgroundColor(0);
    locate(x,y);
    int i,j;
    for(i=0;i<choosenLength;i++){
        for(j=0;j<choosenWidth;j++){
            locate(x+j,y+i);
            cout << " ";
        }
        cout << endl;
    }
    setBackgroundColor(0);

    setColor(15);

}





