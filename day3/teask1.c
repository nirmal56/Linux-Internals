// create 2 processes.
#include<stdio.h>
#include<unistd.h>



int main()
{
int pid_i,pid_j;
printf("Current process = %d\n",getpid());
printf("Current process = %d\n",getpid());
pid_i=fork();
pid_j=fork();
if(pid_i==0)
{
printf("New chil process pid = %d\n",getpid());
printf("New child parent proces pod =%d\n",getppid());

}
else
{
printf("Parent process pid = %d\n",getpid());
printf("Parents parent proces pod =%d\n",getppid());
}
if(pid_j==0)
{
printf("New chil process pid = %d\n",getpid());
printf("New child parent proces pod =%d\n",getppid());

}
else
{
printf("Parent process pid = %d\n",getpid());
printf("Parents parent proces pod =%d\n",getppid());
}
return 0;
}