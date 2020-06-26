#include <stdio.h>
int Sum_of_Squares(int n)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		//printf("%d",n);
		return n*n+Sum_of_Squares(n-1);
	}
}
int main()
{
	int num=0;
	scanf("%d",&num);
	printf("%d\n",Sum_of_Squares(num));
}
