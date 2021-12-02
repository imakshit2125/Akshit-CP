//Om Namah Shivay
//aaravaki2125
#include <stdio.h>

#include <string.h>

int main()

{

 char s1[ 25 ] = "Very Easy ";

 char s2[] = " MTH 409 Exam ";

 char s3[ 50 ] = " ";

 

 printf( "s1 = %s\ns2 = %s\n", s1, s2 ); 

 printf( "%s\n", strcat( s1, s2 ) );

 printf( "%s\n", strncat( s3, s1, 5 ) );

 printf( "\n", strcat( s3, s1 ) );

 

return 0;

}