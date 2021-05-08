//
// Created by helianhaodong on 2021/4/28.
//

#include "String.h"

String::String(const char* str)
{
    init(str);
    std::cout << "默认构造函数(" << *this << ")" << std::endl;
}

String::String(const String& another)
{
    // 在类的成员函数中可以访问同类型实例的私有变量
    init(another.m_buffer);
    std::cout << "拷贝构造函数(" << *this << ")" << std::endl;
}

String::String(String&& another) noexcept
{
    // 把another对象掏空用来填充this
    m_buffer = nullptr;
    m_buffer = another.m_buffer;
    m_len    = another.m_len;
    another.m_buffer = nullptr;
    another.m_len = 0;
    std::cout << "移动构造函数(" << *this << ")" << std::endl;
}

String::~String()
{
    delete[] m_buffer;
    std::cout << "析构函数(" << *this << ")" << std::endl;
}

/*
 * 拷贝构造函数使用传入对象的值生成一个"新的对象"的实例
 * 赋值运算符是将对象的值复制给一个"已经存在"的实例
 */
String& String::operator=(const String &another)
{
    if (this != &another)
    {
        delete m_buffer;
        init(another.m_buffer);
    }

    std::cout << "拷贝赋值操作(" << *this << ")" << std::endl;
    return *this;
}

/*
 * 移动赋值操作即把参数传进来的"对象的所有权"转移到"this指向的对象"
 * 掏空another对象的所有
 */
String& String::operator=(String &&another) noexcept
{
    if (this != &another)
    {
        m_buffer = nullptr;
        m_buffer = another.m_buffer;
        m_len = another.m_len;
        another.m_buffer = nullptr;
        another.m_len = 0;
    }

    std::cout << "移动赋值操作(" << *this << ")" << std::endl;
    return *this;
}

char& String::operator[](size_t idx)
{
    if (idx >= m_len)
    {
        throw std::out_of_range("Index out of range");
    }
    else
    {
        return m_buffer[idx];
    }
}

bool String::operator==(const String &another)
{
    if (m_len != another.m_len) return false;
    else
    {
        return 0 == std::strcmp(m_buffer, another.m_buffer);
    }
}

/*
 * 关于是"返回对象本身"还是"返回对象引用"
 * 如果函数返回在函数中创建的临时对象，则不要使用引用
 * 如果函数返回的是通过引用或指针传递给它的对象，则应当按引用返回对象
 * 如果先创建一个对象，然后返回改对象的副本，则可以使用返回对象
 */

String String::operator+(const String& another)
{
    String curStr;
    if (nullptr == m_buffer)
    {
        curStr = another;
    }
    else if (nullptr == another.m_buffer)
    {
        curStr = *this;
    }
    else
    {
        curStr.m_buffer = new char[m_len + another.m_len + 1];
        std::strcpy(curStr.m_buffer, m_buffer);
        std::strcat(curStr.m_buffer, another.m_buffer);
        curStr.m_len = std::strlen(curStr.m_buffer);
    }

    return curStr;
}

std::istream& operator>>(std::istream& input, String& str)
{
    char tmp[String::CINLIM];
    input.get(tmp, String::CINLIM);
    if (input) str = tmp;

    while (input && input.get() != '\n')
    {
        continue;
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const String& str)
{
    if (nullptr == str.m_buffer)
    {
        output << "";
    }
    else
    {
        output << str.m_buffer;
    }

    return output;
}

void String::init(const char *str)
{
    if (nullptr == str)
    {
        m_len = 0;
        m_buffer = nullptr;
    }
    else
    {
        m_len = std::strlen(str);
        m_buffer = new char[m_len + 1];
        std::strcpy(m_buffer, str);
    }
}

const char* String::data()
{
    return m_buffer;
}

size_t String::length()
{
    if (0 == m_len)
    {
        m_len = std::strlen(m_buffer);
    }

    return m_len;
}