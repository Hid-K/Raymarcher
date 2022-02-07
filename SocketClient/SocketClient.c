#include "SocketClient.h"


sockfd_t connectToRaymarcherServer(uint32_t serverIP, uint16_t serverPort = RAYMARCHER_DEFAULT_SERVER_PORT)
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = serverIP;
    servaddr.sin_port = htons(serverPort);
   
    // connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        return -1;
    }
    else
        printf("connected to the server..\n");

    return sockfd;
};

void serverDataEventHandler(void * data, size_t dataLength)
{

};

void * sendDataToServer(sockfd_t socket, void * data, size_t dataLength)
{
    write(socket, data, dataLength);

    SLL list = getSLL();

    int incomingDataSize = -1;
    ioctl(socket, FIONREAD, &incomingDataSize);

    void * incomungDataBuff = malloc(incomingDataSize);

    if(read(socket, incomungDataBuff, incomingDataSize) > 0)
    {
        return incomungDataBuff;
    } else
    {
        free(incomungDataBuff);
        return NULL;
    }
};