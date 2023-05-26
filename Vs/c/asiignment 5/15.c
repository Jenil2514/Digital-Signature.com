#include<stdio.h>
#include<string.h>
// J e n i o _ H e l l  o
// 0 1 2 3 4 6 7 8 9 10 11
int main()
{

    char name[50];
    scanf("%s", name);
    int len = strlen(name);
    printf("%d\n", len);
    for (int i = 0 ; i<len; i++)
    {
        int count = 0;

        for (int j = 0; j <len; j++)
        {
            if (name[i] == name[j])
            {
                count++;
            }
        }
        printf("%c:%d\n",name[i],count);
    }

    return 0;
}