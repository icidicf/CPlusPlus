#include<iostream>

int main(void)
{

	int a1[] = {1, 2 , 3,4,5,6,7,8,9};
	int len=sizeof(a1)/(sizeof(*a1));
	std::cout<<"a1 len is "<<len<<std::endl;
}
