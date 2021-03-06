#ifndef MY_CONNECT_ /* Include guard */
#define MY_CONNECT_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "text_analysis.h"
#include "SSL_Client.h"
#include "my_cache.h"

#define CacheMaxAge 600
#define CacheValueSize 5242880
#define MaxUrlLength 3000

int ConnectConduct(struct RequestInfo *requestInfo, int sock); // establish TCP connect to server according to CONNECT request
int ForwardMsg(int srcSock, int dstSock, int length, char* buf); // forward messages from srcSock to dstSock; return the length of message.
int ForwardHeader(int srcSock, int dstSock, unsigned char *buf);
int MForwardHeader(int srcSock, int dstSock, unsigned char *buf);
int ForwardSSLMsg(int srcSock, int dstSock, struct ProxyList* proxyList, int bufSize, int ClientNum, struct SSL_Client ***myclient_p, struct SSL_Client **myclient_log, char* buf, struct MyCache* myCache);                     
int makeTCPConnection(char* host, int port);

#endif // MY_CONNECT_