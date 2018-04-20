#include <fstream>
 
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int A[1025],B[1025],AUX[1025][1025]/*matricea de dinamica*/;
int i,j,n,m,rez,REZ[1025]/*sirul de reconstituire*/;
int main()
{
    fi>>n>>m;
    for(i=1;i<=n;i++)
        fi>>A[i];
    for(i=1;i<=m;i++)
        fi>>B[i];
    //cream dinamica
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(A[i] == B[j])
                AUX[i][j]=AUX[i-1][j-1]+1;
            else
                AUX[i][j]=max(AUX[i-1][j],AUX[i][j-1]);
        }
    //facem reconstituirea sirului
    i=n,j=m;
    while(i)
    {
        if(A[i]==B[j])
        {
            rez++;
            REZ[rez]=A[i];
            i--;
            j--;
        }
        else if (AUX[i-1][j] < AUX[i][j-1])
            j--;
        else
            i--;
    }
    fo<<rez<<"\n";
    for(i=rez;i>=1;i--)
        fo<<REZ[i]<<" ";
    fi.close();
    fo.close();
    return 0;
}