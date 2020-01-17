#ifndef  CAMERA_H
#define  CAMERA_H
#include "allinc.h"
#include "session.h"
class Camera
{
public:
	Camera();
	Camera(int position_x,int position_y,int size_w,int size_h,Camera_shape camera_shape);
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

/**
 * @brief Decide how the shape is like of that camera captured
 */
typedef enum
{
	SQUARE_CM,
	CIRCLE_CM
}Camera_shape;
#endif // ! CAMERA_H

