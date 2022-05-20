#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080
int main()
{
    int sockfd;
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in my;
    my.sin_port=htons(PORT);
    my.sin_addr.s_addr = INADDR_ANY;
    my.sin_family=AF_INET;
    int len=sizeof(my);
    bind(sockfd,(struct sockaddr *)&my,len);
    char buffer[1024];
    struct sockaddr_in clientaddr;
    int s =sizeof(clientaddr);
    char b[INET_ADDRSTRLEN];
    while (1)
    {
        recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)&clientaddr,&s);
        inet_ntop( AF_INET, &clientaddr.sin_addr,b,sizeof( b ));
        sendto(sockfd,"Received",9,0,(struct sockaddr *)&clientaddr,s);
        printf("Received DATA from %s",b);
        printf("\n%s",buffer);
    
    }
    close(sockfd);
    return 0;
}