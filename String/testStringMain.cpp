//
// Created by helianhaodong on 2021/4/28.
//

#include "String.h"

void fooh(String x)
{
}

void bar(const String& x)
{
}

String baz()
{
    String ret("world");
    return ret;
}

int mainStr()
{
//    String str1("China");
//    std::cout << str1.data()    << std::endl;
//    std::cout << str1.length()  << std::endl;
//    std::cout << "----------"   << std::endl;
//
//    String str2 = "Word";
//    std::cout << str2 << std::endl;
//    std::cout << "----------"   << std::endl;
//
//    String str3 = str1 + str2;
//    std::cout << str3.data()    << std::endl;
//    std::cout << str3.length()  << std::endl;
//    std::cout << "----------"   << std::endl;
//
//    String str4;
//    std::cin >> str4;
//    std::cout << str4.data()    << std::endl;
//    std::cout << str4.length()  << std::endl;
//    std::cout << "----------"   << std::endl;

    //----------chen shuo test case--------------

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    s2 = s1;
    fooh(s1);
    bar(s1);
    fooh("temporary");
    bar("temporary");
    String s4 = baz();
    std::vector<String> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(baz());
    svec.push_back("good job");

    return 0;
}