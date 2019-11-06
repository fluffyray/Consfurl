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
	                                                          y(y)
{
}
