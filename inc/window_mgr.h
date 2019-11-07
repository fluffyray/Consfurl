#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "allinc.h"

/**
 * @brief manager window of the program
 */
class Window_mgr {
public:
	Window_mgr();//!< Without name being defined, the window created by this fuction will be named as "No_Name"
	explicit Window_mgr(const char* window_name);//!< Without positin
	/**
	 * @brief Constructor for class Window_mgr
	 * @param window_name The title which will be shown at the bar
	 * @param x The x positon of window
	 * @param y The y positon of window
	 */
	explicit Window_mgr(const char* window_name,int x,int y);
private:
	const char* window_name;
	int x;
	int y;
	SDL_Window* p_window;
	SDL_Renderer* p_screen_renderer;
};

#endif // !WINDOW_MGR_H

