#include "p28class.h"

p16class::p16class()
{
}
p16class::~p16class()
{
}

unsigned int p16class::loadtexture(const char* filename) //Function that will load the texture;
{
    SDL_Surface* image = SDL_LoadBMP(filename); //Load the bmp image
    unsigned int id; //variable to take the id of generated texture buffer;
    glGenTextures(1, &id); //generate a texture buffer;
    glBindTexture(GL_TEXTURE_2D, id); //bind the texture buffer;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w,image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels); //describe the texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//set parameter 1
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //set parameter 2
    SDL_FreeSurface(image); //delete the surface image.
    return id; //return the id of the texture;
}

SDL_Window* p16class::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window;
    window=SDL_CreateWindow("Project28", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context;
    context=SDL_GL_CreateContext(window);
    glewInit();
    if(glewInit()!=GLEW_OK)
    {
        cerr << "Error initializing the glew!" << endl;
    }
    else
    {
        cout << "Glew has been successfully initialized!" << endl;
    }
    return window;
}

void p16class::draw(SDL_Window* window)
{
    unsigned int texture;
    bool closeWindow=false;
    SDL_Event a;
    GLfloat cube []
    {
        300,300, 0,
        300,500, 0,
        500,500, 0,
        500,300, 0,

        300,300,0,
        300,500,0,
        300,300,200,
        300,500,200,

        500,300,0,
        500,300,200,
        500,500,0,
        500,500,200,

        300,300,0,
        300,300,200,
        500,300,0,
        500,300,200,

        300,500,0,
        300,500,200,
        500,500,0,
        500,500,200,

        300,300, 200,
        300,500, 200,
        500,500, 200,
        500,300, 200
    };
    //translating the coordinates.
    glViewport(0,0,640,480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,640,0,480,-500,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //done translating the coordinates

    glEnable(GL_DEPTH_TEST); //enable the depth buffer/
    glEnable(GL_TEXTURE_2D); //enable the texture 2d
    texture=loadtexture("1.bmp"); //get the texture into this function,
    glBindTexture(GL_TEXTURE_2D, texture); //bind the texture into this function.

   while(1)
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glTranslatef(0.2,0.0,2.0); //move the rotating image around
        glRotatef(1,1.0,1.0,0.0); //rotate the image.

        glBegin(GL_QUADS);
       // glColor3f(1.0,0.0,0.0);
        glTexCoord2f(0.0,1.0); //set texture corner coordinate
        glVertex3f(200,200, 0);
        glTexCoord2f(0.0,0.0), //set the texture corner coordinate
        glVertex3f(200,400, 0);
        glTexCoord2f(1.0,0.0); //set the texture corner coordinate
        glVertex3f(400,400, 0);
        glTexCoord2f(1.0,1.0); //set the texture corner coordinate
        glVertex3f(400,200, 0);
        glEnd();

        SDL_Delay(50);
        SDL_GL_SwapWindow(window);
        while(SDL_PollEvent(&a))
        {
            switch(a.type)
            {
                case SDL_QUIT:
                {
                   closeWindow=true;
                    break;
                }
            }
        }
        if(closeWindow==true)
        {
            break;
        }
    }
    SDL_DestroyWindow(window);
    cout << "Program closed!" << endl;
}
