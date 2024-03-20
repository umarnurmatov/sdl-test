#include "SDL_Wrap.h"

using namespace SDL_Wrap;

SDL_Window* SDL_Wrap::init_SDL_and_window(int window_width, int window_height)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1)
    {
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        window_width, window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if(window == nullptr)
    {
        std::cout << "SDL_CreateWindow error " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return window;
}

SDL_Renderer* SDL_Wrap::init_renderer(SDL_Window* window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer error " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return renderer;
}

std::string SDL_Wrap::get_resource_path(const char* n)
{
  return std::string(RESOURSE_PATH) + std::string(n);
}

void SDL_Wrap::RenderTextureClip(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip)
{
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  if (clip != nullptr)
  {
    dst.w = clip->w;
    dst.h = clip->h;
  }

  SDL_RenderCopy(ren, tex, clip, &dst);
}

void SDL_Wrap::RenderTexture(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *ren)
{
  SDL_Rect rec {x, y, w, h};
  SDL_RenderCopy(ren, tex, NULL, &rec);
}

SDL_Texture* SDL_Wrap::loadImage(std::string file, SDL_Renderer* ren)
{
  SDL_Surface* loadedImage = nullptr;
  SDL_Texture* texture = nullptr;
  loadedImage = SDL_LoadBMP(file.c_str());

  if(loadedImage != nullptr)
  {
    texture = SDL_CreateTextureFromSurface(ren, loadedImage);
    SDL_FreeSurface(loadedImage);
  }
  else
    std::cout << SDL_GetError() << std::endl;

  return texture;
}
