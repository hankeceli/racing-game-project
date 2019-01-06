//Racing Game Starts With This main
//Reminder for me: g++ -o main main.cpp Car.h Car.cpp road.h road.cpp
#include <iostream>
#include "rlutil.h"
#include "Car.h"
#include "Road.h"

using namespace std;
using namespace rlutil;
#define waitkey rlutil::anykey("Press any key to continue...\n")
double speed=0;
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
int startGame();
int startGame(){
	speed=0;
	Car b;

	int x = 38;
    int y;
    y = 23 - b.getcarLen();
	while (true) {
		b.gameCar(x, y); // Output car
		char k = getch(); // Get character
		b.gameCarremove(x, y);//Remove car
		if (k == 'a') {
			x=x-6;
			if (x < 31)
				x=x+6;
		} else if (k == 'd') {
			x=x+6;
			if (x > 49)
				x=x-6;
		} else if (k == 'w') {
			speed=speed+1;
			if(speed>280){
				speed=280;
			}
		} else if (k == 's') {
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
		Road p;
		p.topMenu();
		locate(1,1);
		cout<<"speed:"<<speed;
		setBackgroundColor(4);
	}
	return 0;
}

//main menu
int main(void) {

	while (1) {
		hidecursor();
		waitkey;

		int x = 7,
				y = 7;
		setColor(8);

		{
			int x = 1;
			int y = 10;
			unsigned int cnt = 0;
			speed = 0;
			while (1) {
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
				cout << endl << endl << endl << "---------------- MAIN MENU ----------------" << endl;
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
					if (y == 10) {//CALL START GAME
						addRoad();
						startGame();

						//STARTGAME ENDS
					} else if (y == 11) {//CALL CHANGE CAR
						rlutil::cls();
						system("CLS");
						locate(2, 8);
						setColor(15);
						cout << "Choose Car Style... " << endl;
						locate(2, 10);
						cout << "1-Porsche GT" << endl;
						locate(2, 11);
						cout << "2-BMW M3 GTR" << endl;
						locate(2, 12);
						cout << "3-Customize Car";
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
								if (y1 > 12)
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
                        cout << "instructions:" << endl;
                        setColor(9);
                        cout << "      W -> Gas" << endl;
                        cout << "      S -> Brake" << endl;
                        cout << "      A -> Left" << endl;
                        cout << "      D -> Right" << endl;
                        cout << "  SPACE -> End Game" << endl;
                        setColor(10);
                        waitkey;
                    }else if (y == 14) {//EXIT
						return 0;
					} else
						cout << "error! (main menu corrupted)";
				}

				cnt++;
				cout.flush();


			}
		}

	}
}
