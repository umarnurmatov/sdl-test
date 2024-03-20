#include "SDL.h"
#include <string>
#include <iostream>
#include "mymath.h"
#include "SDL_Wrap.h"
#include "SDL_Shape.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main(int argc, char *argv[])
{

    SDL_Window* window = SDL_Wrap::init_SDL_and_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = SDL_Wrap::init_renderer(window);

    ///////////////////////////////////////////////////
    int iW = 17, iH = 19;
    
    int player_x = SCREEN_WIDTH / 2 - iW / 2;
    int player_y = SCREEN_HEIGHT / 2 - iH / 2;
    //части 
    SDL_Rect clips[2][3];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; ++j)
        {
            clips[i][j].x = j * iW;
            clips[i][j].y = i * iH;
            clips[i][j].w = iW;
            clips[i][j].h = iH;
        }
    }
    

    int useClipA = 0, useClipB = 0;
    Vec2f pos, vel, accel;
    int da = 1;

    auto* backgound = SDL_Wrap::loadImage(SDL_Wrap::get_resource_path("grass.bmp").c_str(), renderer);

    SDL_Wrap::SDL_Shape player, wall;

    player.loadImage(SDL_Wrap::get_resource_path("mario.bmp").c_str(), renderer);
    wall.loadImage(SDL_Wrap::get_resource_path("wall.bmp").c_str(), renderer);
    wall.setSize({50, 50});
    wall.setPos({50, 50});
    //player.setScale(1);

    ///////////////////////////////////////////////////
    

    SDL_Event event;
    bool quit = false;
    while(!quit)
    {
        
        while(SDL_PollEvent(&event))
        {
        switch(event.type)
        {
            case SDL_QUIT:
            quit = true;
            break;

            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            { 
                case SDLK_d:
                vel.x = da;
                useClipA = 0;
                //useClipB = useClipB != 0 ? (useClipB + 1) % 3 : 1;
                break;
                case SDLK_a:
                vel.x = -da;
                useClipA = 1;
                //useClipB = useClipB != 0 ? (useClipB + 1) % 3 : 1;
                break;
                case SDLK_w:
                vel.y = -da;
                useClipB = 0;
                break;
                case SDLK_s:
                vel.y = da;
                useClipB = 0;
                break;
                default:
                break;
            }
            useClipB = useClipB != 0 ? (useClipB + 1) % 3 : 1;
            break;

            case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_d:
                if(vel.x > 0)
                {
                    useClipB = 0;
                    vel.x = 0;
                }
                break;
                case SDLK_a:
                if(vel.x < 0)
                {
                    useClipB = 0;
                    vel.x = 0;
                }
                break;
                case SDLK_w:
                if(vel.y < 0)
                {
                    vel.y = 0;
                }
                break;
                case SDLK_s:
                if(vel.y > 0)
                {
                    vel.y = 0;
                }
                break;
            }
            break;
        }
        
        }    
        pos += vel;
        player.setClip(clips[useClipA][useClipB]);

        SDL_RenderClear(renderer);
        SDL_Wrap::RenderTexture(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backgound, renderer);
        SDL_Wrap::RenderShape(&player, renderer);
        SDL_Wrap::RenderShape(&wall,   renderer);
        SDL_RenderPresent(renderer);
    }

    //SDL_Delay(10000);

    SDL_DestroyTexture(backgound);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}