#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
//server Code TCP
#define port 8080
int main()
{
    int sockfd;
    sockfd=socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in my;
    my.sin_addr.s_addr=INADDR_ANY;
    my.sin_family=PF_INET;
    my.sin_port=htons(port);
    bind(sockfd,(struct sockaddr *)&my,sizeof(my));
    listen(sockfd,10);
    struct sockaddr_in newclientdata;
    int len=sizeof(struct sockaddr_in);
    int clientsfd=accept(sockfd,(struct sockaddr *)&newclientdata,&len);
    send(clientsfd,"Client Kaisa ha?",17,0);
    char buffer[1024];
    int n=recv(clientsfd,buffer,1024,0);
    buffer[n]='\0';
    printf("Clinet Response To server : %s\n",buffer);
    close(sockfd);
    return 0;
}