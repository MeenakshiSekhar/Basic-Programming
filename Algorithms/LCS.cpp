#include<algorithm>
#include<string>
#include<iostream>
using std::string;
using namespace std;

string lcs(string text, int textSize, string pattern, int patternSize)
{
  int dp[patternSize+1][textSize+1];
  for(int i=0; i<=patternSize; i++)
  {
    for(int j=0; j<=textSize; j++)
    {
      if(i==0 || j==0)
      {
        dp[i][j]=0;
      }
      else if(pattern[i-1]==text[j-1])
      {
        dp[i][j]=max(1+dp[i][j-1], dp[i-1][j]);
      }
      else if(dp[i-1][j]> dp[i][j-1])
      {
        dp[i][j]=dp[i-1][j];
      }
      else
      {
        dp[i][j]=dp[i][j-1];
      }
     }
  }
  string commonsequence;
  for(int i=patternSize, j=textSize; i>=0 && j>=0; )
  {
    if(i==0 && j==0)
    {
    	break;
    }
    if(dp[i-1][j]==dp[i][j-1])
    {
      if(dp[i][j]>dp[i-1][j] || dp[i][j]>dp[i-1][j-1])
      {
	commonsequence+=pattern[i-1];
      }
      i--;
      j--;
    }
    else if(dp[i][j-1]>dp[i-1][j])
    {
  	j--;
    }
    else if(dp[i][j-1]<dp[i-1][j])
    {
      i--;
    }
  }
  reverse(commonsequence.begin(), commonsequence.end());
  return commonsequence;
}

int main()
{
  string text = "todayisfriday";
  string pattern = "iloverock";
  string commonsequence = lcs(text, text.length(), pattern, pattern.length());
  cout<<commonsequence<<endl;
  return 0;
}
