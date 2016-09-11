#include "../inc/client.h"

Client::Client()
{

}

Client::~Client()
{

}

void Client::error(const char *msg)
{
	perror(msg);
	exit(1);
}

void Client::initsock()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		error("ERROR opening socket");
	}
	char name[] = "linux";
	server = gethostbyname(name);
	if(server == NULL)
	{
		error("ERROR, no such host");
	}
}

void Client::connectsock()
{
	port = PORT_NUMBER;
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);
	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		error("ERROR connecting");
	}
}

void Client::sendsock()
{
	string sMessage;
	cout << "Please enter the message: ";
	bzero(buffer, 256);
	fgets(buffer, 255, stdin);
	int tmp;
	tmp = write(sockfd, buffer, strlen(buffer));
	if(tmp < 0)
	{
		error("ERROR writing to socket");
	}
}

void Client::recvsock()
{
	bzero(buffer, 256);
	int tmp;
	tmp = read(sockfd, buffer, 255);
	if(tmp < 0)
	{
		error("ERROR reading from socket");
	}
	cout << buffer << endl;
}

void Client::closesock()
{
	close(sockfd);
}