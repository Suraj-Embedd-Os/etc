
#include <iostream>

using namespace std;

int main()
{
	int num=3;
    for(int i=0;i<=num;i++)
    {
            for(int j=0;j<=i;j++)
                cout<<"#"; 
             cout<<endl;

       
    }
    
       for(int i=num-1;i>=0;i--)
    {
         
            for(int j=i;j>=0;j--)
                cout<<"#"; 
             cout<<endl;

       
    }
    return 0;
}
// o/p 
*
**
***
**
*

void checksum()
{
    char digit;
    int checksum=0;
    cout << "Enter a six-digit number: ";
    for(int i=1;i<=6;i++)
    {
     cin>>digit;
     checksum +=digit-'0';
    }
    
    cout<<"\n checksum = "<<checksum<<endl;
    
}


#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;


bool my_isalpha(char ch)
{
	
	if(ch>=65 && ch <=90)
		return true;
	else if(ch>=97 && ch <=122)
		return true;
	else
		return false;
}
bool my_isalnum(char ch)
{
	if(ch>=48 && ch<=57)
		return true;
	else 
		return false;
	
}

int my_atoi(char *ch)
{
    int num=0,i=0;
    int temp;
    while(ch[i]!='\0')
    {
        if(my_isalpha(ch[i]))
        return num;
        
        if(ch[i]==' ')
        {
            if(num!=0);
            break;
            continue;
        }
        else if(my_isalnum(ch[i])) 
        num=num*10+ch[i]-'0';
        i++;
        
    }
    return num;
}


int main()
{
  cout<<my_atoi("123 14");
    return 0;
}



