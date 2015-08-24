#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

bool mypredict(int i, int j)
{
	return i==j;
}
int main()
{

	vector<int> myvector;
	for(int i=1; i< 6; i++) myvector.push_back(i*10);
	cout<<"myvector"<<endl;
	for_each(myvector.begin(), myvector.end(),
			[](int i){cout<<" "<<i<<endl;});



	int myint[]={10,20,80,320,1024};
	cout<<"myint"<<endl;
	for_each(myint, myint+sizeof(myint)/sizeof(int),
			[](int i){cout<<" "<<i<<endl;});



	pair<vector<int>::iterator, int*> mypair;
	mypair = mismatch(myvector.begin(), myvector.end(), myint);
	cout<<"First mismatch elem" << *mypair.first;
	cout<<" and "<<*mypair.second<<endl;


	mypair.first++;
	mypair.second++;

	mypair = mismatch (mypair.first, myvector.end(),mypair.second, mypredict);
	cout<<"Second mismatch elem" << *mypair.first;
	cout<<" and "<<*mypair.second<<endl;



}
