#include <iostream>
#include <exception>

template <typename T>
class BST_logic_error:public std::logic_error{
    T value_;
public:
    explicit BST_logic_error(const char* what_arg, const T& val):std::logic_error(what_arg), value_(val){}
    const char* what(){
        return std::logic_error::what();
    }
    const T& ReturnValue(){
        return value_;
    }
};
