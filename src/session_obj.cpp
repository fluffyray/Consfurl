#include "..\inc\session_obj.h"

Session_obj::Session_obj(std::string obj_ID):index_in_Session(-1),
                                             obj_ID(obj_ID)
{

}

bool Session_obj::operator==(Session_obj session_obj)
{
	return this == &session_obj;
}

int& Session_obj::get_Index_in_Session()
{
	return this->index_in_Session;
}

void Session_obj::disable_Index_in_Session()
{
	this->index_in_Session = -1;
}

std::string Session_obj::get_Obj_ID()
{
	return this->obj_ID;
}
