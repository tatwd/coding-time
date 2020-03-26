#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 4096

int main(void)
{
	int sfd, cfd;
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int n;

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd == -1) {
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	// 设置socket的绑定信息
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(6666);

	if (bind(sfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	if (listen(sfd, 10) == -1) {
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	printf("waiting for client's request ...\n");
	while (1) {
		// 等待客户端连接
		cfd = accept(sfd, (struct sockaddr *)NULL, NULL);
		if (cfd == -1) {
			printf("accept socket error: %s(errno: %d)\n", strerror(errno), errno);
			continue;
		}
		n = recv(cfd, buf, MAXLINE, 0);
		buf[n] = '\0';
		printf("recv message from client: %s\n", buf);
		close(cfd);
	}

	exit(0);
}
