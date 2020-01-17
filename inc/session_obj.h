#ifndef SESSION_OBJ_H
#define SESSION_OBJ_H
#include <string>

class Session_obj
{
public:
	Session_obj();
	Session_obj(std::string obj_ID);
	Session_obj(std::string obj_ID,int pos_x,int pos_y);
	~Session_obj();
	bool operator == (Session_obj session_obj);
	int pos_x;
	int pos_y;
	int get_Index_in_Session();
	void disable_Index_in_Session();
	std::string get_Obj_ID();
private:
	int index_in_Session;
	const std::string obj_ID;
};

class Character:Session_obj
{
public:
	Character();
	~Character();

private:

};

#endif // !SESSION_OBJ_H

