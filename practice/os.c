#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    char fname[20],lname[20],age[3];
    char ch;
    fptr = fopen("file.txt","w");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    printf("Enter num: ");
    scanf("%d",&num);

    fprintf(fptr,"%d",num);
    fclose(fptr);

    printf("Enter first name,lastname and age\n");
    do{
        scanf("%s %s %s",fname,lname,age);
        fprintf(fp,"%s %s %s\n",fname,lname,age);
    }
    while((ch= getc(stdin)) != EOF);
    fclose

    return 0;
}