#include "p28class.h"

int main(int ars, char** argv)
{
    SDL_Window* aux;
    p16class object;
    aux=object.init();
    object.draw(aux);
    getch();
    return 0;
}
