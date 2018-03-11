#include<iostream>
#include<string.h>
using namespace std;

long int fibo_array(int n)
{
  long int fib[n+1];
  fib[0]=0;
  fib[1]=1;
  for(int i=2; i<=n; i++)
  {
    fib[i]=fib[i-1]+fib[i-2];
  }
  return fib[n];
}

long int fibo_var(int n)
{
  int a, b, c;
  b=1; c=0;
  for(int i=2; i<=n; i++)
  {
    a=b+c;
    c=b;
    b=a;
  }
  return b;
}

void multiply(long int m[2][2] , long int f[2][2])
{
    int a=(m[0][0]*f[0][0])+(m[0][1]*f[1][0]);
    int b=(m[0][0]*f[0][1])+(m[0][1]*f[1][1]);
    int c=(m[1][0]*f[0][0])+(m[1][1]*f[1][0]);
    int d=(m[1][0]*f[0][1])+(m[1][1]*f[1][1]);

    m[0][0]=a;
    m[0][1]=b;
    m[1][0]=c;
    m[1][1]=d;

}

long int fib_matrix(int n)
{
  long int f[2][2]={{1,1},
                    {1,0}};
  if(n==0)
  return 0;
  long int m[2][2]={{1,1},
                    {1,0}};
  for(int i=1; i<n; i++)
  {
    multiply(m,f);
  }
  return m[0][1];
}

void power(long int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  long int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

long int fib_optimat(int n)
{
  long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

int main()
{
  long int n=10;
  cout<<fibo_array(n)<<endl;
  cout<<fibo_var(n)<<endl;
  cout<<fib_matrix(n)<<endl;
  cout<<fib_optimat(n)<<endl;
  return 0;
}
