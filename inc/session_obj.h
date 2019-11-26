#ifndef SESSION_OBJ_H
#define SESSION_OBJ_H
#include <string>
class Session_obj
{
public:
	Session_obj(std::string obj_ID);
	~Session_obj();
	bool operator == (Session_obj session_obj);
	int& get_Index_in_Session();
	void disable_Index_in_Session();
	std::string get_Obj_ID();
private:
	int index_in_Session;
	const std::string obj_ID;
};
#endif // !SESSION_OBJ_H

