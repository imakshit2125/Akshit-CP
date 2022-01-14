#include <stdio.h>

int main() {
   
   int k;
   scanf("%d", &k);

   char ch = ' ';

   while(ch!='?')
   {
       scanf("%c", &ch);

       if(ch>='A' && ch<='Z'){
           char p = ch+k;
           if(p>'Z')
           {
               int r= k-('Z'-ch);
               
               printf("%c",'A'+r-1);
           }
           else
           printf("%c",ch+k);

           k++;
       }

       else if(ch>='a' && ch<='z')
       {
           char p = ch+k;
           
           if(p>'z')
           {
               int r= k-('z'-ch);
               
               printf("%c",'a'+r-1);
           }
           else
           printf("%c",ch+k);

           k++;
       }

       else if(ch==' ')
       printf(" ");

   }
   return 0;
}