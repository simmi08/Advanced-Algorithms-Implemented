#include<bits/stdc++.h>
using namespace std;
int s_matching(string a, string b)
{
	int n = a.length();
	int m = b.length();
	int s=0;
	for(;s<=n-m;s++)
	{
		if(a.substr(s,m)==b)
		return s;
	}
	return -1;
}
int main()
{
	string a,b;
	cin >> a >> b;
	int m = s_matching(a,b);//cout << m;
	if(m!=-1)
	cout << "Pattern occurs with shift " << m << endl;
	else
	cout << "Pattern not found " << endl;
}