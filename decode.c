#include <stdio.h>
#include <stdlib.h>

char image[1024] = "";


int stegimage()
{
   char readdata[1024] = "";
   int keyshift = 0;
   FILE *fptr;
   char ch;
   int passkey = 0;

   if ((fptr = fopen(image, "r+")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

    printf("Key shift: ");
    scanf("%d", &keyshift);

    printf("Pass key: ");
    scanf("%d", &passkey);

    int counter = 0;

    FILE* file = fopen(image, "rb");
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


int main()
{
    printf("image name: ");
    scanf("%s", &image);

    stegimage();

}
