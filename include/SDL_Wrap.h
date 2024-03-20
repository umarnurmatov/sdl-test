#pragma once
#include "SDL2/SDL.h"
#include "iostream"

namespace SDL_Wrap
{

    SDL_Window* init_SDL_and_window(int window_width, int window_height);

    SDL_Renderer* init_renderer(SDL_Window* window);

    std::string get_resource_path(const char* n);

    void RenderTextureClip(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip);

    void RenderTexture(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *ren);

    SDL_Texture* loadImage(std::string file, SDL_Renderer* ren);
}