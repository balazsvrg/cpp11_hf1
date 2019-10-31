#include <iostream>
#include <cstring>
#include "MyString.h"

StringValue::StringValue(char const * s) : refcount_{1}, size_{strlen(s)}{
    data_ = static_cast<char*>(operator new(sizeof(char) * size_ + 1));
    for (int i = 0; i < size_; ++i)
        data_[i] = s[i];
    data_[size_] = '\0';
}

StringValue & StringValue::copy(){
    ++refcount_;
    return *this;
}

StringValue::~StringValue(){
    --refcount_;
    if (refcount_ == 0)
        operator delete(data_);   
}