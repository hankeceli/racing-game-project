//
// Created by burak on 12/28/18.
//
#include <iostream>
#include "rlutil.h"
using namespace std;
#ifndef BASKET_H_
#define BASKET_H_


    class Car{

    public:
        Car();
        int carType(int);
        int getcarLen();
        void carShowup(int,int);
        void gameCar(int,int);
        void gameCarremove(int,int);
        void setcarLen(int);
        int getcarWidth();
        void setcarWidth(int);
        int getcarColor();
        void setcarColor(int);

    private:
        int carLen;
        int carWid;
        int carColor;


    };
    //RACING_PROJECT_CAR_H
#endif