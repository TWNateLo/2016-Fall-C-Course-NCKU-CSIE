/*************************************************************************
*學號: B24046037
*姓名: 羅政昕
*編譯方式: gcc hw3_2.c -lm -o hw3_2
*執行方式: ./hw3_2 00000000100000000000000000000000

*程式功能: This program converts and prints the float of input bit pattern.
*更新日期: 2016.10.23
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (int argc, char **argv) {
        char *i = NULL;
        i = argv[1];
        int b, a, e = 0, m = 0;
        double exponent;
        double mantissa, ans;
        //calculate the exponent
        for(b = 1; b < 9; b++) {
                exponent += (double)(i[b] - '0') * pow(2, (8 - b));
                e += (int)(i[b] - '0');
        }
        if(e != 0) {    //try to calculate denormalized situation
                exponent -= 127;
        }
        if(e == 0) {
                exponent -= 126;
        }
        //calculate the mantissa
        for(a = 9; a < 32; a++) {
                mantissa += (double)(i[a] - '0') * ((double)0.5 / pow(2,(a - 9)));
                m += (int)(i[a] - '0');
        }
        if(e == 0 && m != 0) {  //try to calculate denormalized situation
                mantissa += 0;
        }
        else {
                mantissa++;
        }
        //final calculation
        ans = pow(2, exponent) * mantissa;
	//print positive or negative
        if(i[0] == '1' && e == 8 && m != 0) {
                printf("");
        }
        else if(i[0] == '1') {
                printf("-");
        }
	//final printing part
        if(e == 8 && m == 0){
                printf("inf\n");
        }
        else if(e == 8 && m != 0) {
                printf("nan\n");
        }
        else if(e == 0 && m == 0) {
                ans *= 0;
                printf("%.23e\n", ans);
	}
        else {
                printf("%.23e\n", ans);
        }
}
