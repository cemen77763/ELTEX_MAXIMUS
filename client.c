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
 do { perror(msg); exit(EXIT_FAILURE); } while(0);

// 1 - взять верхнюю карту из колоды
// 2 - сообщить о том что пасуешь
// 3 - сообщить о проигрыше
// 4 - сообщить о выигрыше
// 5 - сообщить о ничьей

 int main(){
 	int sfd;
 	int k = 3;
 	char buff[2];
 	struct sockaddr_in peer_addr;
 	socklen_t peer_addr_size;

 	sfd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (sfd == -1)
 		handle_error("socket");

 	peer_addr.sin_family = AF_INET;
 	peer_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 	//peer_addr.sin_port = htons(2121);
 	peer_addr.sin_port = htons(5000);
 	peer_addr_size = sizeof(struct sockaddr_in);


 	switch(k){
 		case 1:{
 			buff[0] = '1'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) &peer_addr, peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 2:{
 			buff[0] = '2'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) &peer_addr, peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 3:{
 			buff[0] = '3'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) &peer_addr, peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 4:{
 			buff[0] = '4'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) &peer_addr, peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
 		case 5:{
 			buff[0] = '5'; buff[1] = '\0';
 			if (sendto(sfd, buff, 2, 0, (struct sockaddr*) &peer_addr, peer_addr_size) == -1)
 			handle_error("sendto");
 			break;
 		}
		default: {
			break;
		}
 	}




 	close(sfd);
 	exit(EXIT_SUCCESS);
 }