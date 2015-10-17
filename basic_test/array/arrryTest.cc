#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int len1 = 20;
    const int len2 = 20;

    len1 += 2;
    int arr[10] = {1, 4 ,7};
    int arr1[len1];
    int arr2[len2];

    for (auto i : arr)
        cout<<i<<" ";
    cout<<endl;


    return 0;


}
