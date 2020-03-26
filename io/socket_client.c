#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char **argv)
{
	int sfd, n;
	struct sockaddr_in servaddr;
	char recvline[MAXLINE], sendline[MAXLINE];

	if (argc != 2) {
		printf("usage: ./client <ipaddress>\n");
		exit(0);
	}

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd < 0) {
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	// 设置socket的绑定信息
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);

	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}

	if (connect(sfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
		printf("connect error: %s(errno: %d)\n", strerror(errno),errno);
		exit(0);
	}

	printf("send message to server:\n");
	fgets(sendline, MAXLINE, stdin);
	if (send(sfd, sendline, strlen(sendline), 0) < 0) {
		printf("send message error: %s(errno: %d)\n", strerror(errno),errno);
	}

	close(sfd);
	exit(0);
}
