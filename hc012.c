#include <stdio.h>

int main(int arge,char *argv[])
{
    int k;
    int zznum;
    int sumnums = 0;

    char mychar;

    float myfloat;

    printf("Hello World\n");


    k = 24;
    printf("Value of k = %d\n",k);

    zznum = 4;
    printf("Values of zznum = %d\n",zznum);
    printf("Values of to vars are %d and %d\n",k,zznum);

    sumnums += k;
    printf("Total is %d\n",sumnums);

    mychar = 'c';

    printf("mychar is %c\n",mychar);
    printf("mychar is %d\n",mychar);

    myfloat = 24.3;
    printf("myfloat = %f\n",myfloat);


    return 0;
}
