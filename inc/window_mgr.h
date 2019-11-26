#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "allinc.h"

/**
 * @brief Manager window of the program
 */
class Window_mgr {
public:
	//!< Without name defined, title of the window created by this fuction will be "No_Name"
	Window_mgr();
	~Window_mgr();
	//!< Without position defined, window will be shown at the central position of screen
	explicit Window_mgr(const char* window_name);
	
    /**
	 * @brief Constructor for class Window_mgr
	 * @param window_name The title which will be shown at the bar
	 * @param x The x positon of window
	 * @param y The y positon of window
	 * @exception Throws runtime_error when any member failed to initialize
	 */
	explicit Window_mgr(const char* window_name,int x,int y);
	
	/**
	 * @brief Transmit data from a certian surface to screen texture
	 * @param surface The surface form which data is transmited
	 * @exception Throws runtime_error when p_screen_texture = NULL
	 * @return void
	 */
	void Transmit_to_screen_texture(SDL_Surface* surface);

private:
	const char* window_name;//!< Window title
	int x; //!< Window x position
	int y; //!< window y position
	bool window_active; //!<Whether window is active.If not, it means window is going to be destroyed
	SDL_Window*   p_window; //!< Pointer to SDL_Window instance 
	SDL_Renderer* p_screen_renderer; //!< Pointer to SDL_Renderer instance 
	SDL_Texture*  p_screen_texture;//!< Pointer to SDL_Texture instance of screen_renderer
	std::thread screen_rend_T;//!< Rendering thread instance.See Screen_rending fuction for details
	
	/**
	 * @brief In this function renderer will rend window_texture per frame
	 * @param window_mgr The Window_mgr handle in which screen gets rendered
	 * @param starttime Exteral startime which records the time whole render process gets started
	 */
	static void Screen_rending(Window_mgr* window_mgr,int starttime);
};

#endif // !WINDOW_MGR_H

