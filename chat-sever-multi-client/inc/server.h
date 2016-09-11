#ifndef _SERVER_H_
#define _SERVER_H_

#include <arpa/inet.h> // use inet_addr() function
#include "header.h"

class Server{
	int sockfd;
	int newsockfd;
	int port;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	string clientname;
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