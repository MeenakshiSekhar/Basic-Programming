#include<iostream>
#include<string.h>

using namespace std;

int min(int a, int b, int c)
{
	return min(min(a, b), c);
}

int editDistance(string str1, string str2, int m, int n)
{
	int ed[m+1][n+1];
	if(m == 0)
		return n;
	if(n == 0)
		return m;
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i ==0 )
				ed[i][j] = j;
			else if(j == 0)
				ed[i][j] = i;
			else if(str1[i-1] == str2[j-1])
				ed[i][j] = ed[i-1][j-1];
			else
				ed[i][j] = 1 + min(ed[i-1][j], ed[i][j-1], ed[i-1][j-1]);
		}
	}
	return ed[m][n];
}

int main()
{
	string str1 = "meena";
	string str2 = "kiran";
	cout<<editDistance(str1, str2, str1.length(), str2.length());
}
