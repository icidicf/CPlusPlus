#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int myint[]={3,4,1,2};

	sort(myint, myint+sizeof(myint)/sizeof(int));

	for (int i:myint)
		cout<<"after sort "<<i<<endl;
	do {
		for_each(myint,myint+sizeof(myint)/sizeof(int),
				[](int i ){cout<<i<<" ";});
		cout<<endl;
	} while (next_permutation(myint,myint+sizeof(myint)/sizeof(int)));
	

}
