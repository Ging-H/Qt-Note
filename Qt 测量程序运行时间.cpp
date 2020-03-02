#include <QDebug>  
#include <QTime>  

//方法1 利用QTime，其精度为ms级
void main{
QTime time;  
  
time.start();  
function();  
  
qDebug()<<time.elapsed()/1000.0<<"s";  
}

// 利用gettimeofday()，其精度为us级
#include <QDebug>  
#include <sys/time.h>  

void main{
struct timeval tpstart,tpend;  
float timeuse;  
  
gettimeofday(&tpstart,NULL);  
function();  
gettimeofday(&tpend,NULL);  
timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;  
  
qDebug()<<timeuse<<"s";  
}

//利用clock()，其精度为ms级
void main{
#include <QDebug>  
#include <sys/time.h>  
  
double time_Start = (double)clock();  
function();  
double time_End = (double)clock();  
      
qDebug()<<(time_End - time_Start)/1000.0<<"s";  
}