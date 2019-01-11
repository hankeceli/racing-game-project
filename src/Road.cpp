//
// Created by burak on 12/28/18.
//
//Reminder for me: Total width=80,Total length=24;
//Reminder for me: Grass x 27+ Border x 4 + road x 18 + Border x 4 + Grass x 27 = 80
//Reminder for me: Objects are left-top aligned. Locate according to it.

#include "Road.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#define waitkey rlutil::anykey("")


Road::Road() = default;


void Road::grass() {
    rlutil::locate(1,1);
    int width;
    int length;
    width=totalWidth;
    length=totalLength;
    int i,j;
    for(i=0;i<width+1;i++){
        for(j=0;j<length;j++){
            locate(i,j+1);
            setBackgroundColor(2);
            cout<<" ";

        }
    }


}


void Road::roadBorder() {

    int i,j;
    setColor(6);
    setBackgroundColor(6);
    for(i=0;i<24;i++){
        for(j=0;j<4;j++){
            locate(27+j,i+1);
            cout << " ";
        }

    }

    setColor(6);
    setBackgroundColor(6);
    //Roadborder at the left
    for(i=0;i<24;i++){
        for(j=0;j<4;j++){
            locate(50+j,i+1);
            cout << " ";
        }


    }

    locate(27,0);
    cout<<"fuck";



}

void Road::showRoad() {
    locate(31,1);
    int width;
    int length;
    width=19;
    length=24;
    int i,j;
    for(i=0;i<length;i++){
        for(j=0;j<width;j++){
            locate(31+j,1+i);
            setBackgroundColor(7);
            cout<<" ";

        }
    }
}

void Road::roadStopper() {

}

void Road::topMenu() {
    setBackgroundColor(4);
    for(int i=0;i<81;i++){
        locate(i,1);
        cout<<" ";

    }

}

void Road::enemyCar(Car& a,int x, int y) {
    int len=a.carLen;
    int wid=a.carWid;
    int col=0;

    int i,j;
    setColor(col);
    setBackgroundColor(col);
    for(i=0;i<len;i++){
        for(j=0;j<wid;j++){
            locate(x+j,y+i);
            cout << " ";
        }
        cout << endl;
    }
    setBackgroundColor(0);

    setColor(15);
}

void Road::enemyCarremove(Car& b, int x, int y) {

    setBackgroundColor(7);
    locate(x,y);
    int i,j;
    for(i=0;i<b.carLen;i++){
        for(j=0;j<b.carWid;j++){
            locate(x+j,y+i);
            cout << " ";
        }
        cout << endl;
    }
    setBackgroundColor(7);

    setColor(15);


}



