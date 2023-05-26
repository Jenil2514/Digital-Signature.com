#include <stdio.h>

int main()
{
    char a[1000];
    gets(a);
    int i = 0, j = 0, count = 0;
    int b[10], c[10];

    for (i = 0; i < 10; i++)
    {
        b[i] = i;
    }
    for (j = 0; j < 10; j++)
    {

        while (a[i] != '\0')
        {
            if (a[i] == 0)
            {
                count++;
                
            }
            c[j] = count;
            i++;
        }
    }
    printf("%d", c[0]);
    return 0;
}