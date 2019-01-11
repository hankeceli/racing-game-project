//Racing Game Starts With This main
//Reminder for me: g++ -o main main.cpp Car.h Car.cpp road.h road.cpp
#include <iostream>
#include "rlutil.h"
#include "Car.h"
#include "Road.h"
#include <ctime>


using namespace std;
using namespace rlutil;
#define waitkey rlutil::anykey("Press any key to continue...\n")

double speed=0;
//Youwin Function
void youWin() {

    int i,j;
    for(i=0;i<81;i++){
        for(j=0;j<24;j++){
            locate(i,j+1);
            setBackgroundColor(7);
            cout<<" ";

        }
    }
    setColor(0);
    locate(37,10);
    cout << "Y0U W1N"<< endl<<endl<<endl<<endl<<endl<<endl;
    waitkey;
}
void youLose(){
    int i,j;
    for(i=0;i<81;i++){
        for(j=0;j<24;j++){
            locate(i,j+1);
            setBackgroundColor(4);
            cout<<" ";

        }
    }
    setColor(0);
    locate(37,10);
    cout << "Y0U L0SE"<< endl<<endl<<endl<<endl<<endl<<endl;
    waitkey;
}
//Add Road Function
int addRoad();
int addRoad(){
	cls;
	system("CLS");
	Road p;
	p.grass();
	p.showRoad();
	p.roadBorder();
	p.topMenu();
	p.roadStopper();
}
//Add Road Function Ends
//Start Game Function
int startGame();

int startGame(){
	int i=3;
    int x2=38;

    speed=0;
	Car b;
	Road p;
	int x = 38;
    int y;
    y = 23 - b.getcarLen();
	while (true) {
        int z;
        z = 1 + std::rand()/((RAND_MAX + 1u)/3);
        if(z==1){
            x2=38;
        }
        else if(z==2){
            x2=32;
        }
        else if(z==3){
            x2=44;
        }
		b.gameCar(x, y); // Output car
		p.enemyCar(b,x2,i);
		char k = getch(); // Get character
		b.gameCarremove(x, y);//Remove car
		p.enemyCarremove(b,x2,i);
		if (k == 'a') {
			x=x-6;
			if (x < 31)
				x=x+6;
		} else if (k == 'd') {
			x=x+6;
			if (x > 49)
				x=x-6;
		} else if (k == 'w') {
		    if(speed>=100){
		        i++;
		    }
			speed=speed+2;
			if(speed>280){
				speed=281;
			}
			if(speed<0){
				speed = 0;
			}
		} else if (k == 's') {
		    i--;
		    if(i==2){
		    	i++;
		    }
			speed=speed-3;
			if(speed<0){
				speed=0;
			}
		} else if (k == ' ') {
			break;
		} else if (k== KEY_ESCAPE){
			return 0;
		}
		locate(1,1);
		setColor(0);
        if(speed<100 && speed>50){
            i--;
            if(i==2){
            	i++;
            }
        }
		p.topMenu();
        if(i==y-4&& x==x2){
            youWin();
            break;//you win
        }
        if(i<2 && x!=44 || i==y && x!=x2) {
            if (speed > 50 && speed < 100) {
                i = 3;
            } else if (speed>100){
                youLose();
                break;//you lose
            }
        }
		if(i>y-4){
			youLose();
			break;
		}

		locate(1,1);
		speed--;
		if(speed<0){
			speed=0;
		}
		cout<<"speed:"<<speed;
		setBackgroundColor(4);
	}
	return 0;
}


//Start Game Function Ends


//main menu
int main(void) {
	for(int i=0;i<81;i++) {
        for (int j = 0; j < 24; j++) {
            locate(i, j + 1);
            setBackgroundColor(0);
            cout << " ";

        }
    }
	while (1) {
		hidecursor();
		waitkey;

		int x = 7,y = 7;
		setColor(8);

		{
			int x = 1;
			int y = 10;
			unsigned int cnt = 0;
			speed = 0;
			while (1) {
                std::string title("Car Catching");
			    rlutil::setConsoleTitle(title);
				rlutil::cls();
				system("CLS");
				hidecursor();
				cls;
				setBackgroundColor(0);
				//main menu
				setColor(8);
				locate(2, 5);
				cout << "---------------- MAIN MENU ----------------";
				setColor(15);
				locate(2, 8);
				cout << "Use 'W' and 'S' buttons to change and Use 'SPACE' button to choose" << endl;
				locate(2, 10);
				cout << "Start Race" << endl;
				locate(2, 11);
				cout << "Change Car" << endl;
				locate(2, 12);
				cout << "Selected Car" << endl;
				locate(2, 13);
				cout << "Instructions" << endl;
				setColor(12);
				locate(2, 14);
				cout << "Exit";
				setColor(8);
				locate(2, 15);
				cout << endl << endl << endl << "---------------- MAIN MENU ----------------" << endl << "To Move in Menu Use <W-A-S-D> Keys" << endl <<"To Select in Menu use <Space> Key"<< endl << "First 2 games may be bugged please press <SPACE> and back main menu";
				setColor(10);
				rlutil::locate(x, y);
				std::cout << '>'; // Output player
				char k = getch(); // Get character
				rlutil::locate(x, y);
				std::cout << " ";
				if (k == 'a') {
					--x;
					if (x < 1)
						++x;
				} else if (k == 'd') {
					++x;
					if (x > 1)
						--x;
				} else if (k == 'w') {
					--y;
					if (y < 10)
						++y;
				} else if (k == 's') {
					++y;
					if (y > 14)
						--y;
				} else if (k == ' ') {
					rlutil::cls();
					system("CLS");
					if (y == 10) {//CALL START GAME FROM MAIN MENU
						addRoad();
						startGame();

						//STARTGAME ENDS
					} else if (y == 11) {//CALL CHANGE CAR FROM MAIN MENU
						rlutil::cls();
						system("CLS");
						locate(2, 8);
						setColor(15);
						cout << "Choose Car Style... " << endl;
						locate(2, 10);
						cout << "Porsche Carrera GT" << endl;
						locate(2, 11);
						cout << "BMW M3 GTR" << endl;
						locate(2, 12);
						cout << "Customize Car"<<endl;
						locate(2,13);
						cout<<"Back";
						int x1 = 1;
						int y1 = 10;
						unsigned int cnt1 = 0;
						while (true) {
							setColor(10);
							rlutil::locate(x1, y1);
							std::cout << '>'; // Output player
							char k = getch(); // Get character
							rlutil::locate(x1, y1);
							std::cout << " ";
							if (k == 'w') {
								--y1;
								if (y1 < 10)
									++y1;
							} else if (k == 's') {
								++y1;
								if (y1 > 13)
									--y1;
							} else if (k == ' ') {
								rlutil::cls();
								if (y1 == 10) { //PORSCHE
									rlutil::cls();
									system("CLS");
									int color;
									cls();
									Car porsche;
									std::cout << "\nCar Colors\n";
									for (int i = 0; i < 8; i++) {
										rlutil::setBackgroundColor(i);
										std::cout << i;
										rlutil::setBackgroundColor(0);
										std::cout << ' ';
									}
									rlutil::resetColor();
									cout << endl << "Please Enter Car Color Number:";
									showcursor();
									setColor(11);
									cin >> color;
									setColor(15);
									porsche.setcarColor(color);
									porsche.carType(0);
									hidecursor();
									porsche.carShowup(5, 5);
									cls;
								}
								if (y1 == 11) { //BMW
									rlutil::cls();
									system("CLS");
									int color;
									cls();
									Car bmw;
									std::cout << "\nCar Colors\n";
									for (int i = 0; i < 8; i++) {
										rlutil::setBackgroundColor(i);
										std::cout << i;
										rlutil::setBackgroundColor(0);
										std::cout << ' ';
									}
									rlutil::resetColor();
									cout << endl << "Please Enter Car Color Number:";
									showcursor();
									setColor(11);
									cin >> color;
									setColor(15);
									bmw.setcarColor(color);
									bmw.carType(1);
									hidecursor();
									bmw.carShowup(5, 5);
									cls;
								}
								if (y1 == 12) { //CUSTOMIZE
									rlutil::cls();
									system("CLS");
									int color;
									int Length;
									int Width;
									int excuse = 0, excuse1 = 0, excuse2 = 0;
									cls();
									Car customize;
									customize.carType(1);
									std::cout << "\nCar Colors\n";
									for (int i = 0; i < 8; i++) {
										rlutil::setBackgroundColor(i);
										std::cout << i;
										rlutil::setBackgroundColor(0);
										std::cout << ' ';
									}
									rlutil::resetColor();
									do {
										excuse++;
										if (excuse > 1) {
											setColor(4);
											cout << endl << "Please Type number in given interval" << endl;
											setColor(15);
										}
										cout << endl << "Please Enter Car Color Number:";
										showcursor();
										setColor(11);
										cin >> color;
										setColor(15);
									} while (color > 15 || color < 1);

									customize.setcarColor(color);
									do {
										excuse1++;
										if (excuse1 > 1) {
											setColor(4);
											cout << endl << "Please Type number in given interval" << endl;
											setColor(15);
										}
										cout << endl << "Please Set Car Length between 3-5:";
										setColor(11);
										cin >> Length;
										setColor(15);
									} while (Length > 10 || Length < 3);

									customize.setcarLen(Length);
									do {
										excuse2++;
										if (excuse2 > 1) {
											setColor(4);
											cout << endl << "Please Type number in given interval" << endl;
											setColor(15);
										}
										cout << endl << "Please Set Car Width between 3-6:";
										setColor(11);
										cin >> Width;
										setColor(15);
									} while (Width > 6 || Width < 3);
									customize.setcarWidth(Width);
									customize.carType(2);
									hidecursor();
									customize.carShowup(5, 10);
									rlutil::cls();
									system("CLS");
								}
								if(y1==13)
								    break;

								break;
							}
							cnt1++;
						}
					} else if (y == 12) {//CALL SELECTED CAR
						Car a;
						cout << "Your car Is here:" << endl;
						a.gameCar(5, 5);
						waitkey;

					} else if (y == 13) {//CALL INSTRUCTIONS
                        cls;
                        system("CLS");
                        setColor(14);
                        locate(2, 5);
                        cout << "				instructions:" << endl<<endl<<endl<<endl;
                        setColor(9);
                        cout << "		YOU NEED TO CRASH ENEMY CAR FROM BEHIND TO WIN"<<endl<<endl<<endl;
                        cout << "      				W -> Gas" << endl;
                        cout << "      				S -> Brake" << endl;
                        cout << "      				A -> Left" << endl;
                        cout << "      				D -> Right" << endl;
                        cout << "  				SPACE -> End Game" << endl<<endl<<endl<<endl<<endl<<endl<<endl;
                        setColor(10);
                        waitkey;
                    }else if (y == 14) {//EXIT
						return 0;
					} else
						cout << "error! (main menu corrupted)";
				}

				cnt++;
				cout.flush();


			}//END OF SECOND WHILE
		}//TO KEEP ALIGNED

	}//END OF FIRST WHILE
}// END OF MAIN FUNC
