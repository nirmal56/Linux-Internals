/*
1.Write a udp client server program,client writing messages to server program and server
return back the same toggled msg to client
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT 8000
#define MAXSZ 100

char* toggle(char str[]){
    char* ret_str=str;
    for(int i=0; i<strlen(str); i++){
        if(ret_str[i]>='A' && ret_str[i]<='Z')
            ret_str[i]=ret_str[i]+32;
        else if(ret_str[i]>='a' && ret_str[i]<='z')
            ret_str[i]=ret_str[i]-32;
    }
return ret_str;
}

int main(){
    int sockfd, newsockfd, n;
    char msg[MAXSZ];
    int clientAddrLen;
    socklen_t client;
    struct sockaddr_in cliaddr, servaddr;
    char buf[10000];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsocket:");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl(inaddrany)
    servaddr.sin_port = htons(PORT); // tcp protocol http port.

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("socket is now bound to port 8000\n");
    listen(sockfd, 5);

    while (1){
        printf("**************server is waiting for new client connection*************\n");
        clientAddrLen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientAddrLen);
        while (1){
            int n;
            n = recv(newsockfd, msg, MAXSZ, 0);
            if (n == 0){
                close(newsockfd);
                break;
            }
            msg[n] = 0;
            char *toggled = toggle(msg);
            send(newsockfd, msg, n, 0);
            printf("message recieved from the client is: %s\n", msg);
        }
    }
    return 0;
}