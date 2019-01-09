#ifndef P16CLASS_H
#define P16CLASS_H
#include <SDL.h>
#include <glew.h>
#include <iostream>
#include <conio.h>

using namespace std;
class p16class
{
    public:
        p16class();
        virtual ~p16class();
        SDL_Window* init();
        void draw(SDL_Window* window);
        unsigned int loadtexture(const char* filename);

    protected:

    private:
};

#endif // P16CLASS_H
