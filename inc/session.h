#ifndef SESSION_H
#define SESSION_H
#include "allinc.h"
#include <map>
#include <string>
#include <vector>
#include <queue>
#include "session_obj.h"
class Session
{
public:
	Session();
	~Session();
	Session_obj& add_Session_obj(Session_obj& session_obj);
	Session_obj& remove_Session_obj(Session_obj& session_obj);

private:
	std::vector<Session_obj*> registered_session_obj;    
	std::queue<int> available_index_RSO;
};
#endif // ! SESSION_H

