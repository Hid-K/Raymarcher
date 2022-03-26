#ifndef RAYMARCHER_SOCKET_CLIENT_H
#define RAYMARCHER_SOCKET_CLIENT_H

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include "../DLLProcessor/DLLProcessor.h"
#include "../SingleLinkedList/SLL.h"

#define RAYMARCHER_DEFAULT_SERVER_PORT 1030

typedef int sockfd_t;

sockfd_t connectToRaymarcherServer(uint32_t serverIP, uint16_t serverPort);

#define connectToRaymarcherServer(serverIP) connectToRaymarcherServer(serverIP, RAYMARCHER_DEFAULT_SERVER_PORT)

void serverDataEventHandler(void * data, size_t dataLength);

void * sendDataToServer(sockfd_t socket, void * data, size_t dataLength);

void * sllToRawData(SLL * list);

#endif