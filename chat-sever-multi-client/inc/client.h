#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "header.h"

class Client{
	int sockfd;
	int port;
	char buffer[256];
	struct sockaddr_in serv_addr;
	struct hostent *server;
public:
	Client();
	~Client();
public:
	void error(const char *msg);
	void initsock();
	void connectsock();
	void sendsock();
	void recvsock();
	void closesock();
};
#endif /* _CLIENT_H_ */