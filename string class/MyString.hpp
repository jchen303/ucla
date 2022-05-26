#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

class MyString
{
public:
    
    /**
     - constructs an empty char vector
     */
    MyString()       : s(0)   {}
    
    /**
     @param c : the char you'd like to initialize the myString with
     - constructs a char vector containing the param c
     */
    MyString(char c) : s(1,c) {}
    
    /**
     @param n : the number of chars you'd like to initialize the myString with
     @param c : the char you'd like to initialize the myString with
     - constructs a char vector with n number of the param 'c's in it
     */
    MyString(size_t n, char c) : s(n, c) {}

    /**
     @param pos : the index you'd like to start your substring at
     @param len : the length of the substring you want to retrieve
     - if length of the myString < len, the substring goes up until
     the end of the string
     - if pos == size of the myString, "" is returned
     - if pos > length of the myString, out of range exception is thrown
     @return a myString of the specified length beginning at the specified index
     
     */
    MyString substr(size_t pos, size_t len = -1) const;

    /**
     @param c : a reference to the char you are searching for
     @param pos : the index at which you'd like to start searching
     for the desired myString
     - moves through the myString from left to right in search of
     the desired myString
     - starts at index 0 if none is specified
     @return the index at which the desired myString is located,
     returns the size_t of -1 if it is not found
     */
    size_t  find(char c, size_t pos =  0) const;
    
    /**
     @param c : a reference to the char you are searching for
     @param pos : the index at which you'd like to start searching
     for the desired myString
     - moves through the myString from right to left in search of
     the desired myString
     - starts at the end of the index if none is specified
     @return the index at which the desired myString is located,
     returns the size_t of -1 if it is not found
     */
    size_t rfind(char c, size_t pos = -1) const;

    /**
     @param str : a reference to the myString you are searching for
     @param pos : the index at which you'd like to start searching
     for the desired myString
     - moves through the myString from left to right in search of
     the desired myString
     - starts at index 0 if none is specified
     @return the index at which the desired myString is located,
     returns the size_t of -1 if it is not found
     */
    size_t  find(const MyString& str, size_t pos =  0) const;
    
    /**
     @param str : a reference to the myString you are searching for
     @param pos : the index at which you'd like to start searching
     for the desired myString
     - moves through the myString from right to left in search of
     the desired myString
     - starts at the end of the index if none is specified
     @return the index at which the desired myString is located,
     returns the size_t of -1 if it is not found
     */
    size_t rfind(const MyString& str, size_t pos = -1) const;

    /**
     @return the size of the myString
     */
    size_t size() const    {return s.size();}
    
    /**
     @return the size of the myString
     */
    size_t length() const  {return s.size();}
    
    /**
     @return true if the myString is and empty string, false otherwise
     */
    bool empty() const     {return (s.size() == 0);}
    
    /**
     @param c : the char you would like to add to the end of myString
     */
    void push_back(char c) {s.push_back(c);}
    
    /**
     - removes the last character in the myString
     */
    void pop_back()        {s.pop_back();}
    
    /**
     @param n : the new size to which you'd like to reformat the myString
     - if current size is larger then myString is downsized
     - if current size is smaller then '\0' is added to end of myString
     */
    void resize(size_t n)  {while (s.size() != n) {if (s.size() < n) {s.push_back('\0');}
                                                   if (s.size() > n) {s.pop_back();}}}
    /**
     @param n : the new size to which you'd like to reformat the myString
     @param c : the char you'd like to add at the end of myString if n > the size of s
     - if current size is larger then myString is downsized
     - if current size is smaller then 'c' is added to end of myString
     */
    void resize(size_t n, char c) {while (s.size() != n) {if (s.size() < n) {s.push_back(c);}
                                                          if (s.size() > n) {s.pop_back();}}}
    
private:
    std::vector<char> s;

#include "students-ignore1.h"
};

#include "students-ignore2.h"
#endif /* MyString_hpp */
