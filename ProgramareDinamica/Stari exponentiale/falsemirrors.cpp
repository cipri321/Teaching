#include <iostream>
#include <cstring>
using namespace std;
int M[21],D[1<<21],A[1<<21];
int n;

int magie(int cod)
{
    if(A[cod]==-1)
    {
        for(int i=0;i<n;i++)
        {
            bool ok=false;
            for(int j=0;j<3;j++)
                if((cod&(1<<((i+j)%n)))==0)
                    ok=true;
            if(!ok)
                continue;
            int cod1=cod;
            for(int j=0;j<3;j++)
                cod1|=(1<<((i+j)%n));
            int x=magie(cod1)+D[cod1];
            if(A[cod]==-1 || x<A[cod])
                A[cod]=x;
        }
        if(A[cod]==-1)
            A[cod]=0;
    }
    return A[cod];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>M[i];
    for(int i=0;i<=1<<n;i++)
        for(int j=0;j<n;j++)
            if((i&(1<<j))==0)
                D[i]+=M[j];
    memset(A,-1,sizeof(A));
    cout<<magie(0);
    return 0;
}