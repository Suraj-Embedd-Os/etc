
#include <iostream>
#include<algorithm>

using namespace std;

void sort(int a[],char b[],int n)
{
    pair<int,char> pa[n];
    
    for(int i=0;i<n;i++){
    pa[i].first=a[i];
    pa[i].second=b[i];
    
    }
    
    sort(pa,pa+n);
    
    for(int i=0;i<n;i++)
    cout<<pa[i].second<<" ";
}

int main()
{
     int a[]={3,1,2};
     char b[]={'G','E','K'};
     
    sort(a,b,3);

    return 0;
}