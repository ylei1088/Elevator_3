#include<stdio.h>
#include<stdlib.h>

int main(){

    int floors [16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int size = sizeof(floors)/sizeof(floors[0]);

    int currentFloor;
    int playerFloor;
    int checkValidFloor = 0;

    printf("Choose a floor: ");
    scanf("\n%d", &playerFloor);

    for(int i = 0; i < size; i++)
    {
        if(playerFloor == floors[i])
        {
            checkValidFloor = 1;
        }
    }

    if(checkValidFloor == 1)
    {
        for(int i = 0; i < size; i++)
        {
            if(playerFloor > i)
            {
                printf("%d\n",i);   
            }
            else if(playerFloor == i)
            {
                printf("%d\n",i);
                printf("DING!\n");
            }
        }
    }
    else
    {
        printf("Invalid Floor Inserted !");
    }
    

    return 0;
}