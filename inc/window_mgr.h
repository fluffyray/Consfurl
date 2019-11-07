#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "allinc.h"

/**
 * @brief Manager window of the program
 */
class Window_mgr {
public:
	//!< Without name being defined, the window created by this fuction will be named as "No_Name"
	Window_mgr();
	
	//!< Without position defined, window will be shown at the central position of screen
	explicit Window_mgr(const char* window_name);
	
    /**
	 * @brief Constructor for class Window_mgr
	 * @param window_name The title which will be shown at the bar
	 * @param x The x positon of window
	 * @param y The y positon of window
	 */
	explicit Window_mgr(const char* window_name,int x,int y);
	
	/**
	 * @brief Transmit data from a certian surface to screen texture
	 * @param surface The surface form which data is transmited
	 * @exception Throw runtime_error when p_screen_texture = NULL
	 * @return void
	 */
	inline void Transmit_to_screen_texture(SDL_Surface* surface)
	{
		this->p_screen_texture = SDL_CreateTextureFromSurface(this->p_screen_renderer,surface);
		if (this->p_screen_texture == NULL)
		{
			throw std::runtime_error("at Consfurl.window_mgr.Transmit_to_screen_texture():\n\
				                      Can't create texture form the surface");
		}
	}
private:
	const char* window_name;//!< 
	int x;
	int y;
	SDL_Window*   p_window;
	SDL_Renderer* p_screen_renderer;
	SDL_Texture*  p_screen_texture;
	 
};

#endif // !WINDOW_MGR_H

