#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string line;

    while(getline(cin, line))
        cout <<"input is " <<line <<endl;
    return 0;
}
