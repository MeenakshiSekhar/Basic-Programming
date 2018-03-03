  #include<iostream>

  using namespace std;

  int max(int a, int b)
  {
    return a > b ? a : b;
  }

  int knapsackdp(int* wt, int* val, int size, int knapsack)
  {
    int dp[size][knapsack+1];
    //insert values
    for(int i=0; i<size; i++)
    {
      for(int j=0; j<=knapsack; j++)
      {
        if(j==0)
        {
          dp[i][j] = 0;
        }
        else if(j >= wt[i])
        {
          if(i>0)
          {
            dp[i][j] = max((val[i]+dp[i-1][j-wt[i]]), dp[i-1][j]);
          }
          else
          {
            dp[i][j] = val[i];
          }
        }
        else if(j < wt[i])
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    
    //retrieve max items
    int flag = 1;
    int maxwt = dp[size-1][knapsack];
    int total = 0;
    for(int i=size-1, j=knapsack; i>=0, j>=0; )
    {
      if(dp[i][j-1] == dp[i-1][j])
      {
        total+=val[i-1];
        i--;
        j--;
        j=j-wt[i];
        i--;
      }
      else if(dp[i-1][j] < dp[i][j-1])
      {
        total+=val[i];
        j--;
        i--;
        j=j-wt[i];
      }
      else if(dp[i-1][j] > dp[i][j-1])
      {
        total+=val[i-1];
        i--;
        j=j-wt[i];
        i--;
      }
      if(dp[i][j] == 0 || i<0 || j<0)
      {
        break;
      }
    }
    return total;

  }

  int main()
  {
    int wt[4] = { 1,2,5,7};
    int val[4] = { 3,2,7,5};
    int knapsack = 7;
    int size = sizeof(wt)/sizeof(int);
    cout<<knapsackdp(wt, val, size, knapsack);
    return 0;
  }
