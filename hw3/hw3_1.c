/*************************************************************************
*學號: B24046037
*姓名: 羅政昕
*編譯方式: gcc hw3_1.c -o hw3_1
*執行方式: ./hw3_1 1 -1
                ./hw3_1 2 100
*程式功能: This program prints the bit pattern of a number of int or float.
*更新日期: 2016.10.23
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv) {
        /* This part print out the 32 bits binary of an integer */
        if(atoi(argv[1]) == 1) {
                int i = atoi(argv[2]), k, a;
                for(a = 31; a > -1; a--) {
                        k = i >> a;
                        if(k & 1) {
                                printf("1");
                        }
                        else {
                                printf("0");
                        }
                }
                printf("\n");
        }
        /* This part print out the 32 bits IEEE flaoting point binary of a float */
        if(atoi(argv[1]) == 2) {
                float f = atof(argv[2]);
                int i, j;
                char* p;
                p = (unsigned char *)&f;
                p+=3;

                for(i = 0; i < sizeof(float); i++)
                {
                        for(j = 7; j >=0 ; j--)
                        {
                                printf("%d", *p & (1 << j) ? 1 : 0);
                                if((i==0 && j==7) || (i==1 && j==7))
                                        printf(" ");
                        }
                        p--;
                }
                printf("\n");
        }
}
