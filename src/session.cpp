#include "session.h"

Session::Session():Session("NONE_NAME", WINDOW_WIDE, WINDOW_HIGH)
{
}

Session::Session(std::string session_ID):Session(session_ID,WINDOW_WIDE,WINDOW_HIGH)
{
}

Session::Session(std::string session_ID, int size_W, int size_H):session_ID(session_ID),
                                                                 size_W(size_W),
	                                                             size_H(size_H)
{
}

Session::~Session()
{
}

Session_obj*& Session::operator[](std::size_t n)
{
	return this->registered_session_obj.at(n);
}

Session_obj& Session::add_Session_obj(Session_obj& session_obj)
{
	if (!this->available_index_RSO.empty()) {
		if((*this)[this->available_index_RSO.front()] != nullptr)
		{
			throw std::runtime_error("at Consfurl.Session.add_Session_obj()\n  Corresponding pointer should be nullptr");
		}
		else
		{
			(*this)[this->available_index_RSO.front()] = &session_obj;
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
		std::cout << "Warning: " <<session_obj.get_Obj_ID() << "is not a obj in the session" << std::endl;
	}
	else {
		this->registered_session_obj.at(session_obj.get_Index_in_Session()) = nullptr;
		this->available_index_RSO.push(session_obj.get_Index_in_Session());
		session_obj.disable_Index_in_Session();
	}
	return session_obj;
}
