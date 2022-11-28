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
void addposition(struct position *source, int *n, double *dist)
{
    char name [25];
    double time;
    double latitude;
    double longitude;
    double altitude;
    double distance;
    struct position thisdistance;
    struct position original;
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
    thisdistance=source[*n];
    original=source[0];
    double dislat=thisdistance.latitude;
    double origlat=original.latitude;
    dislat=(dislat-origlat);
    dislat=pow((dislat),2);
    double dislon=thisdistance.longitude;
    double origlon=original.longitude;
    dislon=(dislon-origlon);
    dislon=pow((dislon),2);
    double disalt=thisdistance.altitude;
    double origalt=original.altitude;
    disalt=(disalt-origalt);
    disalt=pow((disalt),2);
    distance=sqrt(dislat+dislon+disalt);
    dist[*n]=distance;
    *n=*n+1;
}
struct position people[20];
int main()
{
    double dist[20];
    dist[0]=0;
    int check;
    int spot;
    printf("Would you like to enter the data manually or from a file?\nEnter '1' for manual and '2' for from a file\n");
    scanf("%d",&check);
    if (check==1)
    {
        int num=0, others=0;
        printf("please enter number of other users\n");
        scanf("%d",&others);
        others+=1;
        printf("please enter your position\n");
        addposition(people,&num,dist);
        printf("currently %d people added\n",num);
        for (int i = 1; i < others; i++)
        {
            printf("enter other persons position please\n");
            addposition(people,&num,dist);
            printf("now %d entry\n", num);
        }
        double temp=dist[1];
        for (int i = 1; i < num; i++)
        {
            if (temp>dist[i])
            {
                temp=dist[i];
            }
        }
        for (int i = 1; i < num; i++)
        {
            if (temp==dist[i])
            {
                spot=i;
            }
        }
        struct position closest = people[spot];
        printf("The closes person to the first entry is at latitude %.2lf, longitude %.2lf, altitude %.2lf and their name is %s.", closest.latitude, closest.longitude, closest.altitude, closest.name);
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