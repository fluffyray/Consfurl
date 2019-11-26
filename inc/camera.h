#ifndef  CAMERA_H
#define  CAMERA_H
#include "allinc.h"
#include "session.h"
class Camera
{
public:
	Camera();
	~Camera();

private:
	SDL_Surface* p_captured_surface;
	SDL_Surface* capture(Session* session);
};

#endif // ! CAMERA_H

