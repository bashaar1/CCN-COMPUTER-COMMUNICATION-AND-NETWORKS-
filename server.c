#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#define port 8080
int main()
{
    int sockfd = socket(PF_INET,SOCK_DGRAM,0);
    struct sockaddr_in my,clientaddr;
    my.sin_addr.s_addr=INADDR_ANY;
    my.sin_family=PF_INET;
    my.sin_port=htons(port);
    int len = sizeof(my);
    bind(sockfd,(struct sockaddr*) &my,len);
    char buffer[1024];
    len=sizeof(clientaddr);
    int n=recvfrom(sockfd,buffer,1024,MSG_WAITALL,(struct sockaddr *)&clientaddr,&len);
    buffer[n]='\0';
    printf("Data Coming from client: %s\n",buffer);
    sendto(sockfd,"Ma theak chalo ma chalta hoon baad ma baat hoti",48,0,(struct sockaddr * )&my,len);
    close(sockfd);
    return 0;
}