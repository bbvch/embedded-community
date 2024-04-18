
#include <costlylib.h>

#include <iostream>

unsigned long long m1();
unsigned long long m2();
unsigned long long m3();
unsigned long long m4();
unsigned long long m5();

int main()
{
    std::cout << costlylib::header::foo() + m1() + m2() + m3() + m4() + m5() << std::endl;
    return 0;
}
