#ifndef  CAMERA_H
#define  CAMERA_H
#include "allinc.h"
#include "session.h"

/**
 * @brief Decide how the shape is like of that camera captured
 */
typedef enum class Camera_shape
{
	SQUARE_CM,
	CIRCLE_CM
};

class Camera
{
public:
	Camera();
	Camera(int position_x,int position_y,int size_w = WINDOW_WIDE,int size_h = WINDOW_HIGH,Camera_shape camera_shape = Camera_shape::SQUARE_CM);
	~Camera();

private:
	SDL_Surface* p_captured_surface;
	Camera_shape camera_shape;
	int pos_x;
	int pos_y;
	int size_w;
	int size_h;

	SDL_Surface* capture(Session* session);
};

#endif // ! CAMERA_H
