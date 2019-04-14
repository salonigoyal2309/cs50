#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if(argc!=2){

        fprintf(stderr, "please enter file to open \n ");
        return 1;

    }

    FILE *fptr = fopen(argv[1],"r");

    if(fptr==NULL){

        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;

    }

    FILE *outptr;
    unsigned char buffer[512];
    char filename[10];
    int flag=0,counter=0;

    while(fread(buffer,512,1,fptr)==1){

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){

            if(flag==1){
                fclose(outptr);
            }
            else{
                flag=1;
            }

            sprintf(filename, "%03i.jpg", counter);
            outptr = fopen(filename, "w");
            counter++;

        }

        if (flag == 1){
            fwrite(&buffer, 512, 1, outptr);
        }

    }


    fclose(fptr);
    fclose(outptr);

    return 0;





}
