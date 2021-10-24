#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
void *process_producer (void * arg);
void *process_consumer1 (void *arg);
void *process_consumer2 (void *arg);
 
sem_t empty;    //信号量 empty
sem_t full;     //信号量 full
int running = 1;
 
int apple_num = 0;
 
int main(void)
{
    pthread_t consumer_t1;   //消费者1
    pthread_t consumer_t2;   //消费者2
    pthread_t producter_t;  //生产者
 
    //pshared表示信号量共享类型， 为0时，表示只能在当前进程的
    //多个线程之间共享，不为 0 时，是可以和其他进程间共享该信号量
    //使用信号量，用来协作生产者和消费者的顺序，即实现同步效果
    sem_init (&empty,0,1);  //初始化empty信号量
    sem_init (&full,0,0);   //初始化full信号量
 
    pthread_create(&consumer_t1,NULL,process_consumer1,(void*)&running);    //创建消费者线程1
     pthread_create(&consumer_t2,NULL,process_consumer2,(void*)&running);    //创建消费者线程2
    pthread_create(&producter_t,NULL,process_producer,(void *)&running); //创建生产者线程
 
    //sleep(1);       //睡眠 3 秒
    usleep(1000);   //睡眠10微秒
 
    running = 0;
 
    pthread_join(consumer_t1,NULL);
    pthread_join(consumer_t2,NULL);
    pthread_join(producter_t,NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
void *process_producer(void *arg)
{
    while(*(int*)arg)
    {
        sem_wait(&empty);
        apple_num++;
        printf("producter 生产了第 %d 个产品\n",apple_num);
        sem_post(&full);
        usleep(1);
    }
}
 
void *process_consumer1(void *arg)
{
    while(*(int *)arg)
    {
        sem_wait(&full);
        printf("consumer1 消费了第 %d 个产品\n",apple_num);
        sem_post(&empty);
        usleep(1);
    }
}
void *process_consumer2(void *arg)
{
    while(*(int *)arg)
    {
        sem_wait(&full);
        printf("consumer2 消费了第 %d 个产品\n",apple_num);
        sem_post(&empty);
        usleep(1);
    }
}
