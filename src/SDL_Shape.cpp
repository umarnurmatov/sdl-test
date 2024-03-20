#include "SDL_Shape.h"

namespace SDL_Wrap
{

void SDL_Shape::loadImage(const char *path, SDL_Renderer *ren)
{
    tex = SDL_Wrap::loadImage(path, ren);
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    clip = {0, 0, w, h};
    aabb = {0, 0, w, h};
}

void SDL_Shape::setPos(Vec2f npos)
{
    pos = npos;
    aabb.x = pos.x; aabb.y = pos.y;
}

void SDL_Shape::updatePos(float dt)
{
    pos += vel * dt;
    aabb.x = pos.x; aabb.y = pos.y;
}

void SDL_Shape::setClip(SDL_Rect nclip)
{
    clip = nclip;
}

void SDL_Shape::setSize(Vec2i nsize)
{
    aabb.w = nsize.x * scale; aabb.h = nsize.y * scale;
}

void SDL_Shape::setScale(float nscale)
{
    scale = nscale;
    aabb = {aabb.x, aabb.y, (int)(aabb.w * scale), (int)(aabb.h * scale)};
}

SDL_Shape::~SDL_Shape()
{
    SDL_DestroyTexture(tex);
}

void RenderShape(SDL_Shape *shape, SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, shape->tex, &shape->clip, &shape->aabb);
}
};