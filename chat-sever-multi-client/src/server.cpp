#include "../inc/server.h"

Server::Server()
{
	
}

Server::~Server()
{
	
}

void Server::error(const char *msg)
{
	perror(msg);
	exit(1);
}

void Server::initsock()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		error("ERROR opening socket");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	port = PORT_NUMBER;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
}

void Server::bindsock()
{
	int tmp = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	if(tmp < 0)
	{
		error("ERROR on binding");
	}
}

void Server::listensock()
{ 
	listen(sockfd, 5);
}

void Server::acceptsock()
{	
	clilen = sizeof(cli_addr);
	cout << "accept is running" << endl;
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if(newsockfd < 0)
	{
		error("ERROR on accept");
	}
}

void Server::recvsock()
{
	int tmp;
	cout << "recv" << endl;
	bzero(buffer, 256);
	tmp = read(newsockfd, buffer, 255);
	if(tmp < 0)
	{
		error("ERROR reading from socket");
	}
	cout << "Client: " << buffer;
}

void Server::sendsock()
{
	int tmp;
	tmp = write(newsockfd, "I got message", 18);
	if(tmp < 0)
	{
		error("ERROR writing from socket");
	}
}

void Server::closesock()
{
	close(newsockfd);
	close(sockfd);
}