#include <iostream>
#include "rlutil.h"
using namespace std;
#ifndef ROAD_H_
#define ROAD_H_


    class Road{

    public:
        Road();
        void showRoad();
        void grass();
        void roadBorder();
        void topMenu();
        void roadStopper();

    private:
        int totalWidth=80;
		int totalLength=24;
        


    };
    //RACING_PROJECT_ROAD_H

#endif