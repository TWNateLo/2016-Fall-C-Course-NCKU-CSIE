/*************************************************************************
*學號: B24046037
*姓名: 羅政昕
*編譯方式: gcc -o hw1_1 hw1_1.c
*執行方式: ./hw1_1
*程式功能: Calculate and Print the volume of the sphere with radius of 10.
*更新日期: 2016.09.22
**************************************************************************/



#include <stdio.h>
#define pi 3.14
#define r 10
int main (void)
{
        int volume;
        volume = 4.0f/3.0f * pi * r * r * r;    //If the 4.0f/3.0f is changed to just 4/3, the output will be wrong because 4/3 will be calculated as 1 in c.
        printf("The volume of this sphere is: \"%d\"\n", volume);   //Print out the volume of the designated sphere.
        return 0;
}