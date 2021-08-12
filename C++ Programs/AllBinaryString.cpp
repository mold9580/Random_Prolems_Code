#include<bits/stdc++.h>
using namespace std;
string arr = "000000";
void BinaryString(int n)
{
	if (n==0)
		cout << arr << endl;
	else
	{
		arr[n - 1] = '0';
		BinaryString(n - 1);
		arr[n - 1] = '1';
		BinaryString(n - 1);
	}

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
		int n;
		cin >> n;
		BinaryString(n);
	}
}