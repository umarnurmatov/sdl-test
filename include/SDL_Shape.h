#pragma once
#include "SDL_Wrap.h"
#include "mymath.h"

namespace SDL_Wrap
{
struct SDL_Shape
{
    SDL_Texture *tex = nullptr;
    Vec2f pos, vel;
    Vec2i dimension;
    SDL_Rect aabb, clip;
    float scale = 1.f;

    void loadImage(const char * path, SDL_Renderer* ren);

    void setPos(Vec2f npos);
    void updatePos(float dt);
    void setClip(SDL_Rect nclip);
    void setSize(Vec2i nsize);
    void setScale(float scale);

    ~SDL_Shape();
};

void RenderShape(SDL_Shape* shape, SDL_Renderer* ren);
};