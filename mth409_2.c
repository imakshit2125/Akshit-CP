// Om Namah Shivay
// aaravaki2125
#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct char_rec {
    char ch;
    struct char_rec *back;
};

int main()
{
    struct char_rec *ptr,pat[MAX + 2];
    int i=1,j=1;
    printf("Pattern: ");
    
    pat[1].back=pat;
    ptr=pat;
    while((pat[i].ch=getchar())!='\n'){
        ptr[++i].back=++ptr;

        if(i>MAX)break;
        
    }

    while(j<=i)
    printf("%d ",pat[j++].back-pat);

}