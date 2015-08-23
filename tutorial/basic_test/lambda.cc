#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{

	auto f = [] {return 42;};

	std::cout<<"test for f is "<<f()<<std::endl;

	vector<int> myvector;
	for(int i=0;i<5;i++)
		myvector.push_back(i*3);

	for_each(myvector.cbegin(),myvector.cend(),
			[](const int &i){cout<<i<<endl; });
}
