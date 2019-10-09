// Write your code herre
#include<stdio.h>
 int main()
{
int l,n,w,h,i;
scanf("%d",&l);
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d %d",&w,&h);
if((w>l ||w==l)&&(h>l||h==l)&&(w==h))
{
printf("ACCEPTED\n");
}
else if((w>l || w==l) && (h>l ||h==l))
{
printf("CROP IT\n");
}
else{
printf("UPLOAD ANOTHER\n");
}
}
}
