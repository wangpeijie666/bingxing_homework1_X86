#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include <iostream>
#include <stdlib.h>
#include<windows.h>
using namespace std;
int main()
{
        srand((int)time(0));
        int len=10000;
        int*a=new int[len];
        int*sum=new int[len];
        int**b=new int*[len];
        for(int i=0;i<len;i++)
                b[i]=new int[len];
        for(int i=0;i<len;i++)
                a[i]=rand()%100;
        for(int i=0;i<len;i++)
                for(int j=0;j<len;j++)
                        b[i][j]=rand()%100;
        for(len=10000;len>=1000;len=len-1000)
        {
        LARGE_INTEGER t1, t2, tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);
         for(int i=0;i<len;i++)
        {
                sum[i]=0;
                for(int j=0;j<len;j++)
                        sum[i]+=b[j][i]*a[j];
        }
        QueryPerformanceCounter(&t2);
        cout << "n="<<len<<" "<<"TimeConsume:" << ((t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart)<<endl;
        }

        delete[]a;
        delete[]sum;
        for(int i=0;i<len;i++)
                delete[]b[i];
        return 0;


}
