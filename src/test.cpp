#include <SDL2/SDL.h>
#include <iostream>

using namespace std;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
       cout << "SDL could not initialize! Error: " << SDL_GetError() << endl;
        return 1;
    }

    else{
        window = SDL_CreateWindow("Game" , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL){
            cout << "Window Could not Lodded" << SDL_GetError() << endl;
        }

        else{
            // Get Window Surface 

            screenSurface = SDL_GetWindowSurface(window);


            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(window);

            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }


        }

    }

              //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
   
}

