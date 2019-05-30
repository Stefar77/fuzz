#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>

#define lenbuf 4096

int     rfd;

void    execute_code(unsigned char *p){
        int(*fn)();
        fn=p;
        fn();
        return;
}

void    fuzz(){
        unsigned char *code = mmap(NULL, lenbuf, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        while(1){
                for(int i=0; i<lenbuf; i++) code[i]=rand() % 255;

                int pid = fork();
                if(pid == -1) exit(0);

                if(pid == 0) {
                        execute_code(code);
                }else{
                        int     status;
                        pid_t   r;
                        r=waitpid(pid, &status, 0);
                        if(r == -1) {
                                        kill(pid, 9);
                                        sleep(1);
                                        waitpid(pid, &status, WNOHANG);
                        }
                }
        }
}

int     main(int argc, char *argv[]) {
        unsigned num;

        if(argc < 2){ printf("give seeds!\n"); exit(1); }

        sscanf(argv[1], "%u", &num);

        srand((unsigned) num);
        fuzz();
}
