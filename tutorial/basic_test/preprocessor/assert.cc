#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

void print_number(int* myInt) {
      assert (myInt!=NULL);
        printf ("%d\n",*myInt);
}
int main(void)
{
    int i = 7, j = 5;
    assert(7 > 5);
    assert(i>j);

    int a=10;
    int * b = NULL;
    int * c = NULL;

    b=&a;

    print_number (b);
    print_number (c);
    return 0;
}

/*
   assert can be used to check runtime error


*/
