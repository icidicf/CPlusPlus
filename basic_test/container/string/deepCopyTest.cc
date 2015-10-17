#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s = "myha";
    string dup = s;
    cout<<"s is "<<s<<" dup is  "<<dup<<endl;
    dup = "jjjj";
    cout<<"after change dup"<<endl;
    cout<<"s is "<<s<<" dup is  "<<dup<<endl;
    return 0;
}
