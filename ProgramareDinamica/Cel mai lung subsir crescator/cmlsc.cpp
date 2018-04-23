#include <iostream>
using namespace std;
int A[100],D[100];
int n;
int rez;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int i=1;i<=n;i++)
	{
		D[i]=1;
		for(int j=1;j<i;j++)
			if(A[i]>A[j])
				D[i]=max(D[i],D[j]+1);
		rez=max(rez,D[i]);
	}
	cout<<rez;
	return 0;
}