#ifndef CONSFRUL_HANDLE_H
#define CONSFRUL_HANDLE_H
#include "window_mgr.h"
#include "camera.h"

/**
 * @brief Handle Consfurl pragram with this class
 *
 */
class Consfurl_handle
{
public:
	Consfurl_handle();

private:
	Window_mgr window_mgr;
	Camera camera;
};

#endif // !CONSFRUL_HANDLE_H

