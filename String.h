class MyString {
private:
    char *str = nullptr;
    size_t sz = 0;
public:
    MyString() = default;

    MyString(const char c, const size_t sz): sz(sz), str(new char[sz]){
        memset(str, c, sz);
    };

    MyString(const MyString& s): MyString(0, s.sz) {
        memcpy(str, s.str, sz);
    }

    MyString(const std::initializer_list<char>& lst): sz(lst.size()), str(new char[lst.size()]) {
        std::copy(lst.begin(), lst.end(), str);
    }

    size_t size() const {
        return sz;
    }

    char operator[](size_t index) const {
        return str[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& s);

    MyString& operator=(const MyString& s) {
        MyString new_s = s;
        _swap(new_s);
        return *this;
    }

    void _swap(MyString& s) {
        std::swap(str, s.str);
        std::swap(sz, s.sz);
    }

    MyString& operator+=(const MyString& s) {
        MyString new_s = *this;
        str = new char[new_s.sz + s.sz];
        sz = new_s.sz + s.sz;
        memcpy(str, new_s.str, new_s.sz);
        memcpy(str + new_s.sz, s.str, s.sz);
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    for (size_t i = 0; i < s.sz; ++i) {
        os << s.str[i];
    }
    return os;
}

MyString operator+(const MyString& s1, const MyString& s2) {
    MyString new_s = s1;
    new_s += s2;
    return new_s;
}
