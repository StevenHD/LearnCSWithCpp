//
// Created by helianhaodong on 2021/4/28.
//

#ifndef MODERNCPP_STRING_H
#define MODERNCPP_STRING_H

#include "../all.h"

class String
{
private:
    char* m_buffer;
    size_t m_len;

private:
    void init(const char* str);

public:
    //-----------------默认构造函数-----------------
    String(const char* str = nullptr);

    //-----------------拷贝构造函数-----------------
    String(const String& another);

    //-----------------移动构造函数-----------------
    String(String&& another) noexcept;

    //-----------------析构函数-----------------
    ~String();

public:
    //-----------------拷贝赋值运算符重载-----------------
    String& operator=(const String& another);

    //-----------------移动赋值运算符重载-----------------
    String& operator=(String&& another) noexcept;

public:
    char& operator[](size_t idx);
    String operator+(const String& another);
    bool operator==(const String& another);

public:
    friend std::istream& operator>>(std::istream& input, String& str);
    friend std::ostream& operator<<(std::ostream& output, const String& str);

public:
    size_t length();
    const char* data();

private:
    static const int CINLIM = 80;
};


#endif //MODERNCPP_STRING_H
