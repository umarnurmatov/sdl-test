#pragma once
#include "mymath.h"
#include "sdl_wrap.h"

struct Sprite
{
    SDL_Texture* tex;
    Vec2f vel;
    SDL_Rect rect;
    Sprite(const char *path, SDL_Renderer *renderer)
    {
        tex = SDL_Wrap::loadImage(path, renderer);
        int w, h;
        SDL_QueryTexture(tex, NULL, NULL, &w, &h);
        rect = {0, 0, w, h};
    }

    ~Sprite()
    {
        SDL_DestroyTexture(tex);
    }
};

struct AnimatedSprite
{
    SDL_Texture* spr;
    Vec2f vel;
    SDL_Rect** clips;
    SDL_Rect clip;

    AnimatedSprite(const char *path, int iW, int iH, int sx, int sy, SDL_Renderer *renderer)
    {
        spr = SDL_Wrap::loadImage(path, renderer);
        clips = new SDL_Rect*[sy];
        for (int i = 0; i < sy; i++)
        {
            clips[i] = new SDL_Rect[sx];
            for (int j = 0; j < sx; ++j)
            {
                clips[i][j].x = j * iW;
                clips[i][j].y = i * iH;
                clips[i][j].w = iW;
                clips[i][j].h = iH;
            }
        }
        clip = clips[0][0];
    }

    void swFrame(int sx, int sy)
    {
        clip = clips[sy][sx];
    }

    ~AnimatedSprite()
    {
        SDL_DestroyTexture(spr);
    }
};

struct Player
{
    AnimatedSprite as;

    Player(const char * path)

    {

    }
};