// #include <stdio.h>

// #define UNIX 1.0

// int main()
// {
// //    #ifdef UNIX
// //           printf("UNIX specific function calls go here.\n");
// //          // code specific for UNIX system
// //     #else
// //           // code specific for INTEL  system

// //    #endif

// //    // common code is here

//    return 0;
// }


#include <stdio.h>
int main()
{
    // char footballer[40];
    // puts("Enter name:");
    // gets(footballer);    // now deprecated 
    // puts("Congratess...");
    // puts(footballer);
    
    // FILE *p;
    // p=fopen("01.txt","w");

    // fputs("Testiing /// ",p);
    // fclose(p);
    char str [80];
  float f;
  FILE * pFile=NULL;

  pFile = fopen ("myfile.txt","w+");
  fprintf (pFile, "%f %s", 3.1416, "PI");
  rewind (pFile);
  fscanf (pFile, "%f", &f);
  fscanf (pFile, "%s", str);
  fclose (pFile);
  printf ("I have read: %f and %s \n",f,str);

    return 0;
}
