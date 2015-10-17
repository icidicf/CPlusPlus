#include <iostream>
using namespace std;
class A {};
class B 
{
    public:
           virtual void f(int) {std::cout << "B::f" << std::endl;}
};

class D : public B
{
    public:
           virtual void f(int) override {std::cout << "D::f" << std::endl;}
           virtual void g(int) {std::cout << "D::g" << std::endl;}
};


int main(void)
{
    cout<<"size of A is "<<sizeof(A)<<endl;
    cout<<"size of B is "<<sizeof(B)<<" size if D is "<<sizeof(D)<<endl;
}
