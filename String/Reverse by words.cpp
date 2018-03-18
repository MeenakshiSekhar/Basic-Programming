#include <iostream>
#include<stack>
using namespace std;

string reverse(string str)
{
    int i=0;
    stack<char> s;
    string rev;
    while(str[i] != '\0')
    {
        while(str[i] != '.' && str[i] != '\0')
        {
            s.push(str[i++]);
        }
        while(!s.empty())
        {
        	rev += s.top();
        	s.pop();
        }
        if(str[i]!='\0')
        {
        	rev+='.';
        	i++;
        }
    }
    rev+='\0';
    return rev;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout<<reverse(str)<<endl;
	}
	return 0;
}
