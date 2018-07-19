  #include<iostream>
  #include<algorithm>

  using namespace std;

  int subsetsum(int *set, int n , int sum)
  {
    int dp[n+1][sum];
    for(int i=0; i<=n; i++)
    {
      for(int j=0; j<=sum; j++)
      {
          if(i==0 || j==0)
          {
            dp[i][j]=0;
          }
          else
          {
            if(set[i-1]<j)
              dp[i][j]=dp[i-1][j];
            else
            {
              if(set[i-1]==j)
                 dp[i][j]=1;
              else
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-set[i-1]]);
            }
          }
        }
      }
    return dp[n+1][sum];
  }

  int main()
  {
    int set[]={3,34,4,12,5,2};
    int sum=9;
    int n=sizeof(set)/sizeof(int);
    sort(set, set+n);
    for(int i=n-1; i>=0; i--)
    {
      if(set[i]>sum)
        n--;
      else
        break;
    }
    cout<<subsetsum(set, n, sum);
    return 0;
  }
