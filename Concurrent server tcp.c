#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 8080
int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in my,cli;
    my.sin_family=AF_INET;
    my.sin_addr.s_addr=htonl(INADDR_ANY);
    my.sin_port=htons(PORT);
    int len =sizeof(my);
    bind(sockfd,(struct sockaddr *)&my,len);
    listen(sockfd,5);
    int lent=sizeof(cli);

    while (1)
    {
    
    int clifd=accept(sockfd,(struct sockaddr *)&cli,&lent);
    send(clifd,"HEllo From  SERVER\0",20,0);
    char buffer[1024];
    int n=recv(clifd,buffer,1024,0);
    buffer[n]='\0';
    printf("%s",buffer);
    char b[INET_ADDRSTRLEN];
    inet_ntop( AF_INET, &cli.sin_addr,b,sizeof( b ));
    printf("Client Address  = %s",b);
    }
    
    close(sockfd);
}