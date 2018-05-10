#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int A[101][101],dist[101][101];
pair<int,int> P[101][101];
queue<pair<int,int> > Q;
int sl,sc,fl,fc;
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
bool ins(int l,int c)
{return 1<=l&&l<=n&&1<=c&&c<=m;}
void reconst(int l,int c)
{
	if(P[l][c]!=make_pair(-1,-1))
		reconst(P[l][c].first,P[l][c].second);
	cout<<l<<" "<<c<<"\n";
}
int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	cin>>n>>m>>sl>>sc>>fl>>fc;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>A[i][j];
	Q.push(make_pair(sl,sc));
	dist[sl][sc]=1;
	P[sl][sc]=make_pair(-1,-1);
	while(!Q.empty())
	{
		pair<int,int> aux=Q.front();
		Q.pop();
		int l=aux.first,c=aux.second;
		for(int d=0;d<4;d++)
		{
			int ln=l+dl[d],cn=c+dc[d];
			if(ins(ln,cn)&&dist[ln][cn]==0&&A[ln][cn]==0)
			{
				Q.push(make_pair(ln,cn));
				dist[ln][cn]=dist[l][c]+1;
				P[ln][cn]=make_pair(l,c);
			}
		}
	}
	cout<<dist[fl][fc]<<"\n";
	reconst(fl,fc);
	return 0;
}