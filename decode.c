#include <stdio.h>
#include <stdlib.h>


int main()
{
   char readdata[1024] = "";
   int keyshift = 0;
   FILE *fptr;
   char ch;
   int passkey = 0;

   if ((fptr = fopen("83ad4bc8d5a98dce39571abda50f67ac.jpg", "r+")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

    printf("Key shift: ");
    scanf("%d", &keyshift);

    printf("Pass key: ");
    scanf("%d", &passkey);

    int counter = 0;

    FILE* file = fopen("83ad4bc8d5a98dce39571abda50f67ac.jpg", "rb");
    fseek(file, 0, SEEK_END);
    unsigned long fileLen=ftell(file);
    char* file_data;
    rewind(file);
    file_data=malloc((fileLen)*sizeof(char));
    if (file_data == NULL){
        printf("Memory error"); exit (2);
    }
    int num_read=0;
    char s;
    int passcounter = 0;

    while ((num_read = fread(&s, 1, 1, file))) {
        if (passcounter == passkey)
        {
            if (s == ' ')
            {
                counter++;
            }
            else if (s == '\n')
            {
                printf("%c", (counter / keyshift));
                counter = 0;
            }

        }
        else
        {
            passcounter++;
        }
    }


   fclose(fptr); 
  
   return 0;
}
