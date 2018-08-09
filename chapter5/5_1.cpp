#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        stringstream ss(line);
        int x;
        int sum=0;
        while(ss>>x)
        {
            sum+=x;
        }
        cout<<sum<<endl;
    }
    return 0;
}
