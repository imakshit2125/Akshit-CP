#include <stdio.h>
int main() {
   
   	int n;
	scanf("%d",&n);
	
   int m1=n,m2=-2147483648,m3=-2147483648;

	

	while(1)
	{
		scanf("%d", &n);

		if(n==-1)
		break;

		if (n>m1)
        {
			
            m3=m2;
            m2 = m1;
            m1  = n;
        }
 
        
        else if (n>m2 && n<m1)
        {
            m3 = m2;
            m2 = n;
        }
 
        
        else if (n>m3 && n<m2)
            m3 = n;

	}

	if(m3==-2147483648)
	printf("-1\n");
	else
	printf("%d",m3);
	

   

   return 0;
}