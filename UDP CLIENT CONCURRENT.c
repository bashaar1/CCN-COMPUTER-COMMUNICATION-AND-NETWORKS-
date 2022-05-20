#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 8080
#define IP "127.0.0.0"
int main()
{
    for (int i = 0; i <5; i++)
    {
        if(fork()==0)
        {
        int sockfd=socket(AF_INET,SOCK_DGRAM,0);
        struct sockaddr_in sockaddr;
        sockaddr.sin_addr.s_addr=INADDR_ANY;
        sockaddr.sin_family=AF_INET;
        sockaddr.sin_port=htons(PORT);
        int len=(sizeof(sockaddr));
        sendto(sockfd,"KAISA HO BHAI",14,0,(struct sockaddr * )&sockaddr,len);
        char buffer[10];
        recvfrom(sockfd,buffer,10,MSG_WAITALL,(struct sockaddr *)&sockaddr,&len);
        buffer[9]='\0';
        printf("\n%s",buffer);
        close(sockfd);
        close(0);
        }
    }
    
    return 0;
}