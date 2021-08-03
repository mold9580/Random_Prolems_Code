#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int dp[100][100];
int BUWines(int k,int *arr)
{
	for(int i=0;i<k;++i)
		dp[i][i]=k*arr[i];
	int n=k-1;
	for(int i=1;i<k;++i)
	{
		int r=0,c=i;
		while(c<k)
		{
			int a=(dp[r][c-1]+n*arr[c]);
			int b=(dp[r+1][c]+n*arr[r]);
			dp[r][c]=max(a,b);
			r++;
			c++;
		}
		n--;
	}
	// for(int i=0;i<k;++i)
	// {
	// 	for(int j=0;j<k;++j)
	// 	{
	// 		cout<<dp[i][j]<<"\t";
	// 	}
	// 	cout<<endl;

	// }
	return dp[0][k-1];
}
int TDWines(int i, int j,int arr[],int n,int **dpTD)
{
	cnt++;
	if(i>j)
		return 0;
	if(dpTD[i][j]!=0)
		return dpTD[i][j];

	int a1=n*arr[i]+TDWines(i+1,j,arr,n+1,dpTD);
	int a2=n*arr[j]+TDWines(i,j-1,arr,n+1,dpTD);
	return dpTD[i][j]=max(a1,a2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\Applications\\VS_CODE\\Input.txt", "r", stdin);
	freopen("D:\\Applications\\VS_CODE\\Output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	long long int test = 1;
	cin >> test;
	while (test--)
	{
		memset(dp,0,sizeof(dp));
		int k;
		cin>>k;
		int **dpTD;
		dpTD=new int *[k];
		for(int i=0;i<k;++i)
		{
			dpTD[i]=new int[k];
		}
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<k;++j)
				dpTD[i][j]=0;
		}
		int arr[k];
		for(int i=0;i<k;++i)
			cin>>arr[i];
		 cout<<TDWines(0,k-1,arr,1,dpTD)<<endl;
		 cout<<BUWines(k,arr)<<endl;
		 cout<<cnt;
	}
}         