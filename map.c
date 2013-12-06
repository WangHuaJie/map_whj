/*************************************************************************
        > File Name: Transportation_System.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 04 Dec 2013 08:42:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"file.h"

int 
main(void)
{
    AdjMatrix G;
    int choice;
    Create(&G);
    do
    {
        printf("\n\n***The urban traffic situation query system***");
        printf("\n1.Display the basic information");
        printf("\n2.Search some-city's triffic sitution");
        printf("\n3.Add a new road");
        printf("\n4.Delete a old road");
        printf("\n5.Search the shortest road from one plase to another");
        printf("\n6.Search the minimum connected road from some-city");
        printf("\n0.sign out");
        printf("\n\nPlease input your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Display(&G);break;
            case 2:Search(&G);break;
            case 3:Add(&G);break;
            case 4:Del(&G);break;
            case 5:Shortcut(&G);break;
            case 6:MiniSpanTree(&G);break;
            case 0:return 0;
        }
    }while(1);
}



    
    
