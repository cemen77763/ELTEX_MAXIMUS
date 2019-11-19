#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define handle_error(msg)\
 do { perror(msg); return -1; } while(0);

// 1 - take top card of the deck
// 2 - report that you pass
// 3 - report about losing
// 4 - report aboun won
// 5 - report about draw

 int client_server_interaction(int sfd, int k, struct sockaddr_in *peer_addr, socklen_t *peer_addr_size){
 	char buff[2];

 	switch(k){
 		case 1:{
 			buff[0] = '1'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) peer_addr, *peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 2:{
 			buff[0] = '2'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) peer_addr, *peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 3:{
 			buff[0] = '3'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) peer_addr, *peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 4:{
 			buff[0] = '4'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) peer_addr, *peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 5:{
 			buff[0] = '5'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) peer_addr, *peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
		default: {
			return 0; //wrong variable k
			break;
		}
	}
	//retrun -1 -- message sending error
 }

 int main(){
 	int sfd;
 	int k = 1;
 	char buff[2];
 	struct sockaddr_in peer_addr;
 	socklen_t peer_addr_size;

 	sfd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (sfd == -1)
 		handle_error("socket");

 	peer_addr.sin_family = AF_INET;
 	peer_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 	peer_addr.sin_port = htons(2121);
 	peer_addr_size = sizeof(struct sockaddr_in);

 	client_server_interaction(sfd, k, &(peer_addr), &(peer_addr_size));

 	close(sfd);
 	exit(EXIT_SUCCESS);
 }