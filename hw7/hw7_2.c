#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double power(double a,int b);
void itob(int i);       //int to binary
void ftob(float f);     //float to binary
void btof(char* bb);    //binary to float
union flt2bin{
        float f;
        unsigned u;
};
struct bin2flt{
        unsigned sign:1;
        long expo:8;
        unsigned mantisa:24;
};

int main(int argc, char *argv[]){
        if(atoi(argv[1]) == 1) {
                itob(atoi(argv[2]));
        }
        if(atoi(argv[1]) == 2) {
                ftob(atof(argv[2]));
        }
        //define the special char type here in the btof section or just pass the value in first
        if(atoi(argv[1]) == 3)  {
                //try to input argv[2] string to a char
                btof(argv[2]);
        }
}

void itob(int i) {
        /* This part print out the 32 bits binary of an integer */
                int k, a;
                int integ = i;
                for(a = 31; a > -1; a--) {
                        k = integ >> a;
                        if(k & 1) {
                                printf("1");
                        }
                        else {
                                printf("0");
                        }
                }
                printf("\n");
}

void ftob(float f){
        union flt2bin f2b;
        unsigned max = 0x80000000;
        f2b.f = f;
        while(max){
                printf("%d",(f2b.u & max) != 0);
                max>>=1;
        }
        printf("\n");
}
void btof(char* bb){
        char bin[sizeof(float)*8];
        int v = 0, i;
        float mantisa=0;
        int sign;
        struct bin2flt b2f;
        float  result;
        strcpy(bin, bb);
        for(i = 0;i < 32; i++){
                v += (bin[i] - '0') * power(2, 31-i);
        }
        b2f.sign = (v >> 31);
        b2f.expo = (v >> 23) - 127;
        b2f.mantisa =  v & 0x007FFFFF;
        sign = (b2f.sign == 1)? -1:1;
        mantisa = (float)(b2f.mantisa + 0x00800000) / 0x00800000;
        result = (float)(sign) * (float)power(2,b2f.expo) * mantisa;
        printf("%.23e\n", result);
}
double power(double a,int b){
        if(b == 0) return 1;
        if(b > 0)       return a * power(a, b-1);
        if(b < 0)       return (1 / a) * power(a, b+1);
}
