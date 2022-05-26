std::ostream& operator<< (std::ostream& out, const MyString& str) {
    for (size_t i=0, N=str.s.size(); i<N; ++i) {
        out << str.s[i];
    }
    return out;
}
std::istream& operator>> (std::istream& in, MyString& str) {
    std::string str_lit; // definitely cheating
    in >> str_lit;

    str = MyString(str_lit.c_str());
    return in;
}

MyString operator+ (const MyString& lhs, const char*     rhs) { return lhs + MyString(rhs); }
MyString operator+ (const MyString& lhs,       char      rhs) { return lhs + MyString(rhs); }
MyString operator+ (const char*     lhs, const MyString& rhs) { return MyString(lhs) + rhs; }
MyString operator+ (      char      lhs, const MyString& rhs) { return MyString(lhs) + rhs; }

MyString operator+ (const MyString& lhs, const MyString& rhs) {
    const size_t M = lhs.s.size();
    const size_t N = rhs.s.size();

    MyString conc; conc.s.reserve(M+N);

    for (size_t i=0; i<M; ++i) { conc.s.push_back(lhs.s[i]); }
    for (size_t j=0; j<N; ++j) { conc.s.push_back(rhs.s[j]); }

    return conc;
}

MyString& MyString::operator+= (const MyString& str) {
    const size_t M =     s.size();
    const size_t N = str.s.size();

    s.reserve(M+N);
    for (size_t j=0; j<N; ++j) { s.push_back(str.s[j]); }

    return *this;
}
