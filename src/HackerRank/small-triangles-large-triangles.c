// https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void swap(triangle* a,triangle* b)
{
    triangle temp=*a;
    *a=*b;
    *b=temp;
}

int cmp(triangle tr)
{
    int a=tr.a;
    int b=tr.b;
    int c=tr.c;
    return (a+b+c)*(a-b+c)*(a+b-c)*(-a+b+c);
}

void sort_by_area(triangle* tr, int n) {
    for(int i=0;i<n;i++)
    {
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(cmp(tr[j])>cmp(tr[j+1]))
             swap(&tr[j],&tr[j+1]);
            swapped=1;
        }
        if(swapped==0)
            break;
    }
    return;
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}