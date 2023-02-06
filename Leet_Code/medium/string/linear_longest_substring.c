

#include <stdio.h>
#include<string.h>

#define NO_OF_CHARS 256

int max(int a,int b)
{
    return (a>b?a:b);
}

int longestUniqueSubsttr(char * str)
{
	int n = strlen(str);

	int res = 0; 


	int lastIndex[NO_OF_CHARS];
	memset(lastIndex,-1,sizeof(lastIndex));

	int i = 0;

	for (int j = 0; j < n; j++) {

	
		i = max(i, lastIndex[str[j]] + 1);

		res = max(res, j - i + 1);

		lastIndex[str[j]] = j;
	}
	return res;
}

int main()
{
	char *str = "abcda";
	
	printf("%d ",longestUniqueSubsttr(str));

	return 0;
}
