#include <QDebug>  
#include <QTime>  

//����1 ����QTime���侫��Ϊms��
void main{
QTime time;  
  
time.start();  
function();  
  
qDebug()<<time.elapsed()/1000.0<<"s";  
}

// ����gettimeofday()���侫��Ϊus��
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

//����clock()���侫��Ϊms��
void main{
#include <QDebug>  
#include <sys/time.h>  
  
double time_Start = (double)clock();  
function();  
double time_End = (double)clock();  
      
qDebug()<<(time_End - time_Start)/1000.0<<"s";  
}