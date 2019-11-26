#include "window_mgr.h"

Window_mgr::Window_mgr():Window_mgr("No_name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED)
{

}

Window_mgr::Window_mgr(const char* window_name):Window_mgr(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED)
{
}

Window_mgr::Window_mgr(const char* window_name, int x, int y):p_window(SDL_CreateWindow(window_name,x,y,
	                                                                   WINDOW_WIDE,WINDOW_HIGH,0)),
	                                                          window_name(window_name),
	                                                          x(x),
	                                                          y(y),
	                                                          p_screen_renderer(SDL_CreateRenderer(this->p_window,-1,
																                                   SDL_RENDERER_ACCELERATED)),
	                                                          p_screen_texture(SDL_CreateTexture(this->p_screen_renderer,
																                                 SDL_PIXELFORMAT_RGBA8888,
															                                     SDL_TEXTUREACCESS_TARGET,
																		                         WINDOW_WIDE,
																                                 WINDOW_HIGH)),
	                                                          window_active(true),
	                                                          screen_rend_T(Screen_rending,this,1)//Initialize all members
{
	if ((this->p_window == NULL) || (this->p_screen_renderer == NULL) || (this->p_screen_texture == NULL))
	{
		//If any member failed to initialize constructor will throw runtime_error
		throw std::runtime_error("at Consfurl.Window_mgr.Window_mgr():\n  Member(s) of Window_mgr failed to initialize");
	}
	else
	{
		//Initialize all members successully 
		std::cout << "Successfully create Consfurl.Window_mgr instance" << std::endl;
	}
}
Window_mgr::~Window_mgr()
{
	SDL_DestroyTexture(this->p_screen_texture);
	SDL_DestroyRenderer(this->p_screen_renderer);
	SDL_DestroyWindow(this->p_window);
}
void Window_mgr::Transmit_to_screen_texture(SDL_Surface* surface)
{
	this->p_screen_texture = SDL_CreateTextureFromSurface(this->p_screen_renderer, surface);//Create texture from the surface
	SDL_FreeSurface(surface);//Free the memory space of the surface
	if (this->p_screen_texture == NULL)
	{
		//If flied to initialize texture from suface(p_screen_texture == NULL) a runtime_error will be thrown
		throw std::runtime_error("at Consfurl.Window_mgr.Transmit_to_screen_texture():\n  Can't create texture form the surface");
	}
}

void Window_mgr::Screen_rending(Window_mgr* window_mgr,int starttime)
{
	while (window_mgr->window_active)
	{
		SDL_RenderClear(window_mgr->p_screen_renderer);
		SDL_RenderCopy(window_mgr->p_screen_renderer, window_mgr->p_screen_texture, NULL, NULL);
		int endtime = SDL_GetTicks();
		//Miantian FPS in setting fps
		if (endtime - starttime < (1000 / FPS)) {
			SDL_Delay(static_cast<int>(1000 / FPS) - (endtime - starttime));
		}
	}
}
