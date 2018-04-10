#include<iostream>
#include <queue>
#define DIM 250
using namespace std;
int A[DIM][DIM]/*matricea de 0 si 1*/,VIZ[DIM][DIM]/*matricea de distante*/;
int n;
int sl,sc/*linia si coloana de start*/, fl,fc/*linia si coloana de finish*/;
queue<pair<int,int> > Q;/*coada pt lee*/
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};/*vectori de deplasament*/;
bool ins(int l,int c)
{
	return 1<=l&&l<=n&&1<=c&&c<=n;
}
int main()
{
	cin>>n>>sl>>sc>>fl>>fc;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
	//prin 1 se poate trece prin 0 nu se poate
	Q.push(make_pair(sl,sc));
	VIZ[sl][sc]=1;//marcam pozitia de start ca vizitata
	while(!Q.empty())
	{
		pair<int,int> aux=Q.front();
		Q.pop();
		for(int d=0;d<4;d++)
		{
			int ln=aux.first+dl[d],cn=aux.second+dc[d];
			if(ins(ln,cn)&&VIZ[ln][cn]==0&&A[ln][cn]==1)
			{
				VIZ[ln][cn]=1+VIZ[aux.first][aux.second];
				Q.push(make_pair(ln,cn));
			}
		}
	}
	cout<<VIZ[fl][fc];
	return 0;
}