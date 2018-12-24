#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h> // gethostbyname
#include <netinet/in.h>
#include <arpa/inet.h> // htons()
#include <fcntl.h> // O_CREAT etc
#include <error.h>
#include <string.h>

#define PORT 80 // tcp port

int connect(char* s) {
	int fd;
	if ((fd = open("one.html", O_CREAT|O_TRUNC|O_WRONLY)) < 0) {
		perror("Open error");
		return -1;
	}
	
	struct hostent *host;
	if ((host = gethostbyname(s)) == NULL) {
		perror("Get host by name error");
		return -1;
	}
	printf("hostname: %s\n", host->h_name);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr = *((struct in_addr *)host->h_addr);
	servaddr.sin_port = htons(PORT);

	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		perror("socket creat error");
		return -1;
	}

	// connect
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect error");
		return -1;
	}

	char cmd[1024]; // http 1.1
	char tmp[100]; // web page path
	printf("enter the web page path: ");
	fgets(tmp, 100, stdin);
	sprintf(cmd, "GET /%s HTTP/1.1\r\nHost:%s\r\n\r\n",tmp, s);

	if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
		perror("send error");
		return -1;
	}
	char buf[1024]; // receiving data
	while(1) {
		if (recv(sockfd, buf, 1024, 0) < 1)
			break;
		write(fd, buf, strlen(buf));
	}

	close(sockfd);
	close(fd);
	printf("Connection end!\n");
	return 0;
}
