


int eula(n)
{
    int ans=n;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ans/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        ans=ans/n*(n-1);
    return ans;
}


void eula_table(int n,int *eula)
{
    for(int i=1;i<=n;++i)
    {
        eula[i]=0;
    }
    eula[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(eula[i]==0)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(eula[j]==0)
                    eula[j]=j;
                eula[j]*i/(i-1);
            }
        }
    }
}
