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
	Session(std::string session_ID,int size_W,int size_H);

	~Session();

	Session_obj*& operator [] (std::size_t n);

	/**
	 * @brief Add Session_obj to this->regitered_session_obj vector
	 * @param session_obj The Session_obj which will be added to this->registered_session_obj vector
	 * @return quote of added Session_obj
	 * @exception Throws std::out_of_range when index in this->available_index_RSO is out of range of this->available_index_RSO
	 * @note Function takes priority to add Session_obj under the index in this->available_index_RSO queue. If queue is\
	 * empty, Session_obj will be added to the back of this->registered_session_obj vector
	 */
	Session_obj& add_Session_obj(Session_obj& session_obj);

	/**
	 * @brief Remove Session_obj from this->registered_session_obj vector
	 * @param session_obj The Session_obj which will be removed from this->registered_session_obj vector
	 * @return quote of removed Session_obj
	 * @note Session_obj won't be erased from momory but its pionter in this->registered_session_obj vector, and the corresponding\ 
	 * index in this->registered_session_obj of this Session_obj will be added to this->available_index_RSO automatically
	 */
	Session_obj& remove_Session_obj(Session_obj& session_obj);

private:
	const int size_W;
	const int size_H;
	const std::string session_ID;

	/**
	 * Record all the pointers to registered Session_obj, which are regarded as components of the session. 
	 */
	std::vector<Session_obj*> registered_session_obj; 

	/**
	 * The queue records all the index which used to correspo
	 */
	std::queue<int> available_index_RSO;
};
#endif // ! SESSION_H

