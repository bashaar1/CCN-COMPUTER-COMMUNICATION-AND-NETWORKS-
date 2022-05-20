#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define port 8080
int main()
{
    int sockfd  = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in my;
    my.sin_addr.s_addr=INADDR_ANY;
    my.sin_port=htons(port);
    my.sin_family=AF_INET;
    int len = sizeof(my);
    sendto(sockfd,"KAISA HO SERVER",16,0,(struct sockaddr *)&my,len);
    char buff[49];
    recvfrom(sockfd,buff,48,MSG_WAITALL,(struct sockaddr *)&my,len);
    printf("\n%s",buff);
    close(sockfd);
    return 0;
}