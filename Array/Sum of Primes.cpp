#include <iostream>
#include<cstring>
using namespace std;


int checkprime(int *arr, int size, int digit)
{
    if(arr[digit] != -1)
    {
	return arr[digit];
    }
    for(int i=2; i<=digit/2; i++)
    {
        if(digit%i == 0)
        {
        	arr[digit] = 0;
            return 0;
        }
    }
    arr[digit] = digit;
    return digit;
}

int sumofprime(int *arr, int size, int n)
{
    int sum = 0;
    while(n > 0)
    {
        int digit = n%10;
        n/=10;
        sum+=checkprime(arr, size, digit);
    }
    return sum;
}

int main() {
    int t;
    cin>>t;
    int arr[10];
    memset(arr, -1, sizeof(arr));
    arr[1] = 0;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<sumofprime(arr, 10, n)<<endl;
    }
    return 0;
}
