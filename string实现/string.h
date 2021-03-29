#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace zjp
{
class string
{
    

public:
    void swap(string& str)
    {
        char *temp =  str._str;
        str._str = _str;
        _str = temp;
        std::swap(_size, str._size);
        std::swap(_capacity, str._capacity);
    }
    string(const char *str = "")
    {
        int len = strlen(str);
        _str = new char[len + 1];
        _size = len;
        _capacity = len;
        strcpy(_str, str);
    }
    string(const string& str)
    {
        string temp(str._str);
        //swap(_str, str._str);
        //swap(_size, str._size);
        //swap(_capcity, str._capacity);
        swap(temp);
    }
    //string(const string& str)
    //{
    //    int len = strlen(str._str);
    //    _str = new char[len + 1];
    //    _size = len;
    //    _capacity = len;
    //    strcpy(_str, str._str);
    //}
    //拷贝构造的现代写法
    ~string()
    {
        delete[] _str;
        _size = _capacity = 0;
    }
    // s1 = s2
   // string& operator = (const string& str)
   // {
   //     if(_str != str._str)
   //     {
   //         delete[] _str;
   //         strcpy(_str, str._str);
   //         _size = str._size;
   //     }
   //     return *this;
   // }
   string operator = (string str)
   {
       swap(str);

       return str;
   }
        
    // s[i]
    char& operator [] (size_t i)
    {
        assert(i < _size);
        return _str[i];
    }

    void push_back(const char ch)
    {
        _str[_size++] = ch;

        _str[_size] = '\0';
    }

    void append(char* str)
    {
       _size += strlen(str);
       strcpy(str + _size, str);
       _str[_size] = '\0';
    }

    void operator += (const char ch)
    {
        push_back(ch);

    }

    void operator += (char* str)
    {
        append(str);
    }



private:
    char *_str;
    size_t _size;
    size_t _capacity;
};

}

