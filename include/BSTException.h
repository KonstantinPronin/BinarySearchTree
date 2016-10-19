#include <iostream>
#include <exception>
#include <string>

template <typename T>
class BST_logic_error:public std::logic_error{
public:
    explicit BST_logic_error(const char* what_arg):std::logic_error(what_arg){}
    std::string what(){
        return std::logic_error::what();
    }
};