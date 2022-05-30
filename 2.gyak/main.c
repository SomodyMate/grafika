#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>


typedef struct line{
	int xs,xe;
	int ys,ye;
	int r,g,b;
} Line;


int main(int argc, char* argv[])
{
	Line vonal;
	vonal.xs=0;
	vonal.ys=0;
	vonal.xe=400;
	vonal.ye=400;
	vonal.r=255;
	vonal.g=0;
	vonal.b=0;
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_Renderer* renderer;
  int i;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Hello SDL!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  
   
   SDL_SetRenderDrawColor(renderer, vonal.g, vonal.r, vonal.b, SDL_ALPHA_OPAQUE);
   for(int i=0;i<30;i++){
	   SDL_RenderDrawLine(renderer, 0, i, 30, i);
		SDL_RenderPresent(renderer);
   }
   
	SDL_SetRenderDrawColor(renderer, vonal.r, vonal.g, vonal.b, SDL_ALPHA_OPAQUE);
	int counter=0;
  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_QUIT:
        need_run = false;
        break;
	 case SDL_MOUSEBUTTONDOWN:
	 if (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)) {
		 if(event.motion.x<=30 && event.motion.y<=30){
			 SDL_SetRenderDrawColor(renderer, vonal.g, vonal.r, vonal.b, SDL_ALPHA_OPAQUE);
		 }else{
			 if(counter==0){
				 counter=1;
				 vonal.xs=event.motion.x;
				vonal.ys=event.motion.y;
			 }else{
				 counter=0;
				 vonal.xe=event.motion.x;
				vonal.ye=event.motion.y;
				SDL_RenderDrawLine(renderer, vonal.xs, vonal.ys, vonal.xe, vonal.ye);
				SDL_RenderPresent(renderer);
			 }
		 }
	}
                break;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}