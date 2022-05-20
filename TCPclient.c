#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#define port 8080
int main()
{
    int sockfd;
    sockfd = socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in my;
    my.sin_addr.s_addr=INADDR_ANY;
    my.sin_port=htons(port);
    my.sin_family=PF_INET;
    int len = (sizeof(my));
    connect(sockfd,(struct sockaddr *)&my,len);
    char buffer[20];
    int n =recv(sockfd,buffer,20,0);
    buffer[n]='\0';
    printf("%s",buffer);
    send(sockfd,"Ma Theak Tum sunao\n",19,0);
    close(sockfd);
}