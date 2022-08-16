#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char image[1024] = "";

int getimagechars()
{
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
    int countfilechars = 0;
    while ((num_read = fread(&s, 1, 1, file))) {
        countfilechars++;
    }
    
    return countfilechars;
}

int stegimage()
{
    char input[1024] = "";
    int keyshift = 1;

    printf("Text to insert: ");
    scanf("%s", input);

    printf("Key shift: ");
    scanf("%d", &keyshift);

    printf("pass key: %d", getimagechars());

    FILE *fptr;

    fptr = fopen(image,"a");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }


    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j < ((int)input[i])*keyshift; j++)
        {
            fprintf(fptr, "%c", 32);
        }
        fprintf(fptr, "%c", '\n');
    }

    fclose(fptr);

}


int main()
{
    printf("image name: ");
    scanf("%s", &image);

    stegimage();
}