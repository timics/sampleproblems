#include<fstream>
using namespace std;
string c;
int N,M,a[120][120],b[120][120],ql[12000],qc[12000],jl,jc,rl,rc,ret1,ret2,ret3;
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int main()
{
    ifstream fin("rj.in");
    ofstream fout("rj.out");
    fin>>N>>M;
    c=fin.get();
    for(int i=1;i<=N;++i)
    {
        getline(fin,c);
        for(int j=0;j<=M-1;++j)
        {
            if(c[j]=='X')
            {
                a[i][j+1]=-1;
                b[i][j+1]=-1;
            }
            if(c[j]=='J')
            {
                jl=i;
                jc=j+1;
            }
            if(c[j]=='R')
            {
                rl=i;
                rc=j+1;
            }
        }
    }
    int first=0;
    int last=0;
    a[jl][jc]=1;
    ql[0]=jl;
    qc[0]=jc;
 
    while(first<=last)
    {
        for(int k=0;k<=7;++k)
            if(ql[first]+dx[k]>=1 && ql[first]+dx[k]<=N && qc[first]+dy[k]>=1 && qc[first]+dy[k]<=M)
                if(a[ql[first]+dx[k]][qc[first]+dy[k]]==0)
                {
                    a[ql[first]+dx[k]][qc[first]+dy[k]]=a[ql[first]][qc[first]]+1;
                    ++last;
                    ql[last]=ql[first]+dx[k];
                    qc[last]=qc[first]+dy[k];
                }
        ++first;
    }
    first=0;
    last=0;
    b[rl][rc]=1;
    ql[0]=rl;
    qc[0]=rc;
 
    while(first<=last)
    {
        for(int k=0;k<=7;++k)
            if(ql[first]+dx[k]>=1 && ql[first]+dx[k]<=N && qc[first]+dy[k]>=1 && qc[first]+dy[k]<=M)
                if(b[ql[first]+dx[k]][qc[first]+dy[k]]==0)
                {
                    b[ql[first]+dx[k]][qc[first]+dy[k]]=b[ql[first]][qc[first]]+1;
                    ++last;
                    ql[last]=ql[first]+dx[k];
                    qc[last]=qc[first]+dy[k];
                }
        ++first;
    }
    int mi=M*N+1;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            if(a[i][j]==b[i][j] && a[i][j]<mi && a[i][j]>0)
            {
                mi=a[i][j];
                ret1=mi;
                ret2=i;
                ret3=j;
            }
    fout<<ret1<<" "<<ret2<<" "<<ret3;
    return 0;
}
