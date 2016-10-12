/*************************************************************************
*學號: B24046037
*姓名: 羅政昕
*編譯方式: gcc -o hw1_2 hw1_2.c
*執行方式: ./hw1_2 5
*程式功能: Get a value from user, calculate and print out the value of the polynomial.
*更新日期: 2016.09.22
**************************************************************************/





# include <stdio.h>
# include <stdlib.h>
int main (int argc, char **argv)
{
        int x, r;
        x = atoi(argv[1]);      //using argv to get command line input and atoi() to convert char to int.
        r = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;      //The designated polynomial
        printf("The value of the polynomial is: \"%d\"\n", r);  //Print out the calculation of the polynomial
        return 0;
}