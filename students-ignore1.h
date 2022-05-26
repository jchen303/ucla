public:
    // copy constructor
    // MyString(const MyString& str) : s(str.s) {}

    /* commented out since this is
       taken care of by std::vector<char>;
       this also takes care of move semantics. */

    // constructor using a string literal
    MyString(const char* str_lit) : s(0) {
        for (; *str_lit != '\0'; ++str_lit) {
            s.push_back( *str_lit );
        }
    }

    size_t  find(const char* s, size_t pos =  0) const { return  find(MyString(s), pos); }
    size_t rfind(const char* s, size_t pos = -1) const { return rfind(MyString(s), pos); }

    // overloading the [] operator in a const correct way
//          char& operator[] (size_t pos)       { return s[pos]; }
//    const char& operator[] (size_t pos) const { return s[pos]; }

    // overloading "at" in a const correct way
//          char& at(size_t pos)       { return s.at(pos); }
//    const char& at(size_t pos) const { return s.at(pos); }

    MyString& operator+= (const MyString& str);
    MyString& operator+= (const char* str_lit) { return *this += MyString(str_lit); }
    MyString& operator+= (      char       ch) { s.push_back(ch);     return *this; }

private:
    friend std::ostream& operator<< (std::ostream& out, const MyString& str);
    friend std::istream& operator>> (std::istream& in ,       MyString& str);

    friend MyString operator+ (const MyString& lhs, const MyString& rhs);
