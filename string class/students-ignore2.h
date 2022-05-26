std::ostream& operator<< (std::ostream& out, const MyString& str);
std::istream& operator>> (std::istream& in ,       MyString& str);

MyString operator+ (const MyString& lhs, const MyString& rhs);
MyString operator+ (const MyString& lhs, const char*     rhs);
MyString operator+ (const MyString& lhs,       char      rhs);
MyString operator+ (const char*     lhs, const MyString& rhs);
MyString operator+ (      char      lhs, const MyString& rhs);
