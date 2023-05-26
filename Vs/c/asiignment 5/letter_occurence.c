#include <stdio.h>
#include <string.h>
// J e n i o _ H e l l  o
// 0 1 2 3 4 6 7 8 9 10 11

void check(char *name)
{

    int len = strlen(name);
    char un[len];
    int counted = 0;
    int count[20];
    for (int i = 0; i < 20; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        // if (name[i] == '_')
        //     continue;

        int al_co = 0;
        for (int j = 0; j < counted; j++)
        {
            if (name[i] == un[j])
            {
                al_co = 1;
            }
        }

        if (al_co)
        {
            continue;
        }

        for (int j = 0; j < len; j++)
        {
            if (name[i] == name[j])
            {
                count[i]++;
            }
        }

        // printf("%c:%d,\n", name[i], count);

        un[counted] = name[i];
        counted++;
    }
    for (int i = 0; i < counted+1; i++)
    {
        printf("%c:%d,\n", un[i], count[i]);
    }
    
    
}

int main()
{

    char name[50];
    scanf("%s", name);

    check(name);

    return 0;
}