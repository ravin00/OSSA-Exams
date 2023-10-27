#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    
    int pid;
    pid = fork();

    if(pid == 0){

        printf("child : My PID is %d,My parent's PID is %d\n ",getpid(),getppid());
        // sleep(100); create orphan process
        //   wait(100);//avoid orphan process
    }else {
        printf("Parent : My PID is %d,My child's PID is %d\n",getpid(),getppid());
    //     //while(1){
    //         sleep(100); create zombie process
    // }
    //     // sleep(100);//zombie process avoid
       
    }

    return 0;

}