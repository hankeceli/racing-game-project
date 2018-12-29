//Racing Game Starts With This main
#include <iostream>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#define waitkey rlutil::anykey("Press any key to continue...\n")
//main menu
int main(void){
	int onoff=1;
while(onoff=1){
	hidecursor();
	waitkey;
	
    int x=7,
    y=7;

    setColor(8);

    {	int x = 1; int y = 10; unsigned int cnt = 0;
        while (onoff=1) {
			hidecursor();
            cls;
            //main menu
            setColor(15);
            locate(2,8);
            cout << "Use 'W' and 'S' buttons to change and Use 'SPACE' button to choose" << endl;
            locate(2,10);
            cout << "1-Start Race" << endl;
            locate(2,11);
            cout << "2-Change Car" << endl;
            locate(2,12);
            cout << "3-Options" << endl;
            locate(2,13);
            cout << "4-Instructions" << endl;
            setColor(12);
            locate(2,14);
            cout << "Exit";
            setColor(8);
            locate(2,15);
			cout << endl <<endl <<endl << "---------------- MAIN MENU ----------------" << endl;
			setColor(10);
            rlutil::locate(x,y); std::cout << '>'; // Output player
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << " ";
            if (k == 'a'){ 
				--x;
				if(x<1)
					++x;
				}
            else if (k == 'd'){
				++x;
				if(x>1)
					--x;
				}
            else if (k == 'w'){ 
				--y;
				if(y<10)
					++y;
				}
            else if (k == 's'){ 
				++y;
				if(y>14)
					--y;
				}
            else if (k == ' '){
                rlutil::cls();
                system ("CLS");
				if(y==10){
					locate(5,5);
					cout<< "gamestart";}//call start game
				else if(y==11){
                    locate(5,5);
                    cout<< "changecar";}//call change car
				else if(y==12){
                    locate(5,5);
                    cout<< "options";}//call options
				else if(y==13){
                    locate(5,5);
                    cout<< "instructions";}//call instructions
				else if(y==14){
					onoff=0;
					cls;
					return 0;
					}
				else
					cout << "error! (main menu corrupted)";
				}

            cnt++;
            cout.flush();
            
			
        }
    }

	showcursor;
    setColor(8);
    cout << endl <<endl <<endl << "---------------- MAIN MENU ----------------" << endl;
   } 
    return  0;
    
}
