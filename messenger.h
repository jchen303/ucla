#ifndef messenger_h
#define messenger_h

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
// didn't use mutex/lock_guard because there are
// only two threads, both access diff fcns (set_msg
// and quitYet) so there won't be race conditions

class messenge
{
public:
    /**
     default constructor, invokes set_msg in a
     detached thread
     */
    messenge();
    
    /**
     reads from file "to_cpp.txt" character by
     character into a string and assigns the new
     value to msg
     prints the message if there was a new message
     sent, otherwise nothing is printed since there
     is no change
     then waits 1 second before checking again for
     an update in the message
     */
    void set_msg();
    
    /**
     returns value of msg
     
     @return std::string of msg
     */
    std::string get_msg() const;
    
    /**
     checks the buffer using std::cin.get() in order
     to see if the user has typed in "q enter/return,"
     in which case the program will terminate
     
     @return true once q+enter has been pressed
     */
    bool quitYet() const;
    
private:
    std::string msg;
};

#endif
