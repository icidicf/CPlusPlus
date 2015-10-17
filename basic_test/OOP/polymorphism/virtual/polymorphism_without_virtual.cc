#include<iostream>
#include<stdio.h>
using namespace std;
//http://blog.csdn.net/hackbuteer1/article/details/7883531
typedef void (*fVoid)();

class A
{
    public:
        static void test()
        {
            printf("hello A\n");
        }

        fVoid print;

        A()
        {
            print = A::test;
        }
};

class B : public A
{
    public:
        static void test()
        {
            printf("hello B\n");
        }

        B()
        {
            print = B::test;
        }
};


int main(void)
{
    A aa;
    aa.print();

    B b;
    A* a = &b;
    a->print();

    return 0;
}

