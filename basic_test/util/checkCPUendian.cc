#include<iostream>
#include<stdio.h>

using namespace std;

void checkCPUBytes()
{
	int i;
	char c;

	cout<<"CPU's byte is " << sizeof(i)/sizeof(c)<<endl;
	
}

void checkCPUendian()
{
	char o;
	union{
		unsigned int  i;
		unsigned char b[4];
	} c;

	c.i= 0x12345678;


	if(c.b[0]==0x12)
		cout<<"big endian"<<endl;
	else if (c.b[0]==0x78)
		cout<<"little endian "<<endl;
	else 
		cout<<"not support"<<endl;


	cout<<"0 "<<hex<<(int)c.b[0]<<endl;
	cout<<"1 "<<hex<<(int)c.b[1]<<endl;
	cout<<"2 "<<hex<<(int)c.b[2]<<endl;
	cout<<"3 "<<hex<<(int)c.b[3]<<endl;

//	cout<<"shift 24 for c.i" <<c.i <<endl;
	//if (c.i >> 24 )
}


int main(void)
{

	checkCPUBytes();
	checkCPUendian();
}
