#ifndef _SERVER_H_
#define _SERVER_H_
#include <stdio.h> // use perror function
#include <stdlib.h> // use exit function
#include <string.h> // use bzero function
#include <netinet/in.h> // use struct sockaddr_in
#include <unistd.h> // use close function
#include <iostream> // use cout, cin
using namespace std;

#define PORT_NUMBER 55555

class Server{
	int sockfd;
	int newsockfd;
	int port;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
public:
	Server();
	~Server();
public:
	void error(const char *msg);
	void initsock();
	void bindsock();
	void listensock();
	void acceptsock();
	void recvsock();
	void sendsock();
	void closesock();
};

#endif /* _SERVER_H_ */