#include <iostream>
#include <string>

using namespace std;



// ref http://www.boost.org/doc/libs/1_58_0/libs/bind/doc/html/bind.html
int f(int a, int b)
{


    cout<<"a is "<<a<<"b is "<<b<<endl;
    return a + b;
}

int g(int a, int b, int c)
{

    cout<<" a is "<<a<<" b is "<<b<<" c is "<<c<<endl;
        return a + b + c;
}

int main(void)
{
    int x =9;
    bind2nd(std::ptr_fun(f), 5)(x);
    return 0;
}
