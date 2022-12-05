#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<math.h>
#include<sched.h>

#define div CLOCKS_PER_SEC


void countA(){
    
    time_t s,e;
    s=clock();
    
    for(int i = 1;i<pow(2,32);i++){
        
    }
    e=clock();
    
    printf("The time taken by thread_A is : %f\n",((double) (e-s)/div));
}

void countB(){

    time_t s,e;
    s=clock();
   
    for(int i = 0;i<pow(2,32);i++){

    }
    e=clock();
    
    printf("The time taken by thread_b is : %f\n",((double) (e-s))/div );
}

void countC(){
   
    time_t s,e;
    s=clock();
    
    for(int i = 0;i<pow(2,32);i++){

    }
    e=clock();
 
    printf("The time taken by thread_c is : %f\n",((double) (e-s))/div );
}

int main(){
    for(int x=0;x<80;x=x+15){
    pthread_t thread_A,thread_B,thread_C;
    struct sched_param paramA;
    struct sched_param paramB;
    struct sched_param paramC;
    int policyA = SCHED_OTHER;
    int policyB = SCHED_RR;
    int policyC = SCHED_FIFO;
    pthread_create(&thread_A,NULL,countA,NULL);
    pthread_setschedparam(thread_A,policyA,&paramA);
    pthread_setschedparam(thread_B,policyB,&paramB);
    paramA.sched_priority=x;
    pthread_join(thread_A,NULL);

    pthread_create(&thread_B,NULL,countB,NULL);
    pthread_setschedparam(thread_B,policyB,&paramB);
    paramB.sched_priority=x;
    pthread_join(thread_B,NULL);

    pthread_create(&thread_C,NULL,countC,NULL);
    pthread_setschedparam(thread_C,policyC,&paramC);
    paramC.sched_priority=x;
    pthread_join(thread_C,NULL);
    }
    
}