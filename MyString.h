#include <iostream>
#include <cstring>

class StringValue {
private:
    size_t refcount_;
    size_t size_;
    char * data_;
public:
    StringValue(char * s);
    StringValue& copy();
    ~StringValue();
};

class MyString {
private:
    StringValue * value_;
public:
    MyString();
    MyString(char const * value);
    MyString(MyString & the_other);
    MyString(MyString && the_other);

    MyString & operator=(char const * rhs);
    MyString & operator=(MyString & rhs);
    MyString & operator=(MyString && rhs);

    MyString operator+(MyString & rhs);
    MyString operator+(char const * rhs);

    MyString & operator+=(MyString & rhs);
    MyString & operator+=(char const * rhs);

    char const * operator[](size_t const idx) const;
    char& operator[](size_t const idx);

    ~MyString();
};

