#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#define PORT 8080
#define IP "127.0.0.1"
int main()
{


    for(int i=0;i<5;i++){
    if(fork()==0){
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in my;
    my.sin_addr.s_addr=INADDR_ANY;
    my.sin_port=htons(PORT);
    my.sin_family=AF_INET;
    int len =sizeof(my);
    connect(sockfd,(struct sockaddr *)&my,len);
    char buffer[1024];
    int n=recv(sockfd,buffer,1024,0);
    buffer[n]='\0';
    printf("%s",buffer);
    send(sockfd,"Ma Theak Tum sunao\n",19,0);
    close(sockfd);
    close(0);
    }
    }
    return 0;
}