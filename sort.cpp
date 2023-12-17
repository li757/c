#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n, temp, p;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //哈希排序
    for (int i = n / 2; i > 0; i /= 2)  //增量
    {
        for (int m = i; m < n; m++)
        {
            temp = arr[m];
            for (p = m; p >= i && arr[p - i] > temp; p -= i)
            {
                arr[p] = arr[p - i];
            }
            arr[p] = temp;
        }
    }
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];
    return 0;
}