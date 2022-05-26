#include "MyString.hpp"

size_t MyString::find(char c, size_t pos) const
{
    for (size_t ind = pos; ind < s.size(); ++ind)
    {
        if (s[ind] == c)
        {
            return ind;
        }
    }
    return -1;
}

size_t MyString::rfind(char c, size_t pos) const
{
    size_t end = std::min(pos, s.size());

    for (size_t ind = end; (ind != static_cast<size_t>(-1)); --ind)
    {
        if (ind < s.size())
        {
            if (s[ind] == c)
            {
                return ind;
            }
        }
    }
    return -1;
}

MyString MyString::substr(size_t pos, size_t len) const
{
    if (pos == s.size()) {return MyString("");}
    s.at(pos);
    
    size_t end = std::min(len, (s.size() - pos));
    MyString tmp;
    
    for (size_t ind = pos; ind < (pos + end); ++ind)
    {
        tmp += s[ind];
    }
    return MyString(tmp);
}


size_t MyString::find(const MyString& str, size_t pos) const
{
    size_t len = str.length();

    for (size_t ind = pos; ind < s.size(); ++ind)
    {
        if (substr(ind, len).s == str.s)
        {
            return ind;
        }
    }
    
    if (pos == s.size())
    {
        if (substr(pos, len).s == str.s)
        {
            return pos;
        }
    }
    return -1;
}

size_t MyString::rfind(const MyString& str, size_t pos) const
{
    size_t end = std::min(pos, s.size());
    size_t len = str.length();

    for (size_t ind = end; ind != static_cast<size_t>(-1); --ind)
    {
        if (substr(ind, len).s == str.s)
        {
            return ind;
        }
    }
    return -1;
}

#include "students-ignore3.h"
