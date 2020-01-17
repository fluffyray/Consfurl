#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(int position_x, int position_y, int size_w, int size_h, Camera_shape camera_shape):pos_x(position_x),
                                                                                                  pos_y(position_y),
	                                                                                              size_w(size_w),
	                                                                                              size_h(size_h),
	                                                                                              camera_shape(camera_shape)
	                                                                                              
{
}

Camera::~Camera()
{
}

SDL_Surface* Camera::capture(Session* session)
{
	return nullptr;
}
