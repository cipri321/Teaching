#include <iostream>
#define DIM 250
using namespace std;
int A[DIM][DIM],Z[DIM][DIM],nrz;//matricea initiala, matricea in care marcam zonele, numarul de zone
int n;
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
int crt;
bool ins(int l,int c)
{
	return 1<=l&&l<=n&&1<=c&&c<=n;
}
void marcare(int l,int c)
{
	Z[i][j]=nrz;//marcam (l,c) ca apartine zonei curente
	crt++;//crestem dimensiunea zonei curente
	for(int d=0;d<4;d++)
	{
		int ln=l+dl[d],cn=c+dc[d];
		if(ins(ln,cn)&&Z[ln][cn]==0&&A[ln][cn]==1)
			marcare(ln,cn);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!Z[i][j]&&A[i][j]==1)
			{
				nrz++;
				crt=0;//crt va contine dimensiunea zonei din care face parte (i,j)
				marcare(i,j);
				rez=max(rez,crt);
			}
	cout<<rez;
	return 0;
}
