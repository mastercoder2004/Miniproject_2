#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct position
{
    char name [25];
    double time;
    double latitude;
    double longitude;
    double altitude;
};
void addposition(struct position *source, int *n)
{
    char name [25];
    double time;
    double latitude;
    double longitude;
    double altitude;
    printf("enter person name:\n");
    scanf("%s",&name);
    printf("enter time:\n");
    scanf("%lf",&time);
    printf("enter latitude:\n");
    scanf("%lf",&latitude);
    printf("enter longitude:\n");
    scanf("%lf",&longitude);
    printf("enter altitude:\n");
    scanf("%lf",&altitude);
    struct position thisposition;
    strcpy(thisposition.name, name);
    thisposition.time = time;
    thisposition.latitude = latitude;
    thisposition.longitude = longitude;
    thisposition.altitude = altitude;
    source[*n]=thisposition;
    *n=*n+1;
}
struct position people[20];
int main()
{
    int check;
    printf("Would you like to enter the data manually or from a file?\nEnter '1' for manual and '2' for from a file\n");
    scanf("%d",&check);
    if (check==1)
    {
        int num=0, others=0;
        printf("please enter number of other users\n");
        scanf("%d",&others);
        others+=1;
        printf("please enter your position\n");
        addposition(people,&num);
        printf("currently %d people added\n",num);
        for (int i = 1; i < others; i++)
        {
            printf("enter other persons position please\n");
            addposition(people,&num);
            printf("now %d entry\n", num);
        }
        for (int i = 0; i < num; i++)
        {
            struct position thisguy = people[i];
            printf("person name; %s\n", thisguy.name);
            printf("person time; %.2lf\n", thisguy.time);
            printf("person latitude; %.2lf\n", thisguy.latitude);
            printf("person longitude; %.2lf\n", thisguy.longitude);
            printf("person altitude; %.2lf\n", thisguy.altitude);
        }
        
    }
    else if (check==2)
    {
        FILE* textfile;  //creates a variable to call and manipulate the file
        char character;
        printf("\n");
        textfile=fopen("../../../Downloads/sample_users.txt", "r");    //opens the file to read when given the relative path
        do
        {
            character = fgetc(textfile); //gets a single character
            printf("%c", character);
        }
        while (character != EOF);
        fclose(textfile);
    }
    else
    {
        printf("restart program");
    }
    
    return 0;
}