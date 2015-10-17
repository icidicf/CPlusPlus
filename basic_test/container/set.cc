#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    set<int> S;
   // set<int>::iterator i;
    S.insert(50);
    S.insert(20);
    S.insert(60);
    S.insert(30);
    S.insert(80);
//    for (i = S.begin(); i != S.end(); i ++)
    for (int i : S)
        cout<<"value is "<<i<<" ";

    cout<<*S.rbegin()<<" ----"<<endl;
    return 0;
}
