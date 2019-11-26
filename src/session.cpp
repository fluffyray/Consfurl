#include "session.h"

Session_obj& Session::add_Session_obj(Session_obj& session_obj)
{
	if (!this->available_index_RSO.empty()) {
		try
		{
			this->registered_session_obj.at(this->available_index_RSO.front()) = &session_obj;
		}
		catch (std::out_of_range& out_of_range_e)
		{
			std::cout << out_of_range_e.what() << std::endl;
		}
		this->available_index_RSO.pop();
	}
	else
	{
		this->registered_session_obj.push_back(&session_obj);
	}
	return session_obj;
}

Session_obj& Session::remove_Session_obj(Session_obj& session_obj)
{
	if (session_obj.get_Index_in_Session() < 0) {
		std::cout << "Warning: " <<session_obj.get_Obj_ID << "is not a obj in the session" << std::endl;
	}
	else {
		this->registered_session_obj.at(session_obj.get_Index_in_Session) = NULL;
		this->available_index_RSO.push(session_obj.get_Index_in_Session);
		session_obj.disable_Index_in_Session();
	}
	return session_obj;
}
