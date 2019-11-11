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
	                                                          window_active(true)
{
}

void Window_mgr::Transmit_to_screen_texture(SDL_Surface* surface)
{
	this->p_screen_texture = SDL_CreateTextureFromSurface(this->p_screen_renderer, surface);
	SDL_FreeSurface(surface);
	if (this->p_screen_texture == NULL)
	{
		throw std::runtime_error("at Consfurl.window_mgr.Transmit_to_screen_texture():\n  Can't create texture form the surface");
	}
}

void Window_mgr::Sreen_rending(Window_mgr* window_mgr)
{	
	while (window_mgr->window_active)
	{
	int starttime = SDL_GetTicks();
	SDL_RenderClear(window_mgr->p_screen_renderer);
	SDL_RenderCopy(window_mgr->p_screen_renderer, window_mgr->p_screen_texture, NULL, NULL);
	int endtime = SDL_GetTicks();
	if(endtime - starttime < (1000/60)){
		SDL_Delay(static_cast<int>(1000/60) - (endtime - starttime));
	}
}

