#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //printf
#include <stdlib.h>//atoi
#include <string.h> //strerror()
#include <errno.h>//errno- 오류 번호를 저장해줌.
#include <WinSock2.h>
#include <WS2tcpip.h>//inet_ntop

#pragma comment(lib,"ws2_32.lib")

#define MAXPENDING 5//Maximum outstanding connection requests
#define STRINGBUFSIZE 1024

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddress, clientAddress;

	if (argc != 2)//Test for correct number of arguments
	{
		printf("std1Svr <Server Port>\n");
		return 0;
	}

	//소켓 라이브러리 초기화
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup() Error!\n");
		return 0;
	}

	int servPort = atoi(argv[1]);//First arg:local port

	//========================================================================
	// 1.socket() - Create socket for incoming connections
	//========================================================================
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		printf("socket()failed![%d: %s]\n", errno, strerror(errno));
		return 0;
	}

	//Construct local address structure
	memset(&serverAddress, 0, sizeof(serverAddress));//Zero out structure
	serverAddress.sin_family = AF_INET; //IPv4 address family
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);//An incoming interface
	serverAddress.sin_port = htons(servPort); //Local port

	//======================================================
	// 2.bind() - Bind to the local address
	//======================================================
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		printf("bind() failed![%d: %s]\n", errno, strerror(errno));
		closesocket(serverSocket);
		return 0;
	}

	//======================================================
	// 3.listen() - Mark the socket so it will listen for incoming connections
	//======================================================
	if (listen(serverSocket, MAXPENDING) == SOCKET_ERROR)
	{
		printf("listen() failed![%d:%s]\n", errno, strerror(errno));
		closesocket(serverSocket);
		return 0;
	}

	char clientName[STRINGBUFSIZE];  // String to contain client address
	

	int clientAddressLen = sizeof(clientAddress);

	printf("Stand by");

	for (;;)
	{
		clientName[0] = '\0'; //setempty
		

	//======================================================
	// 4.accept() - Wait for a client to connect --> block mode
	//======================================================
		clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);//대기상태에서 접속이 되면 바로 정보입력.connect 시도하면 정보 전달
		if (clientSocket < 0)
		{
			printf("accept()failed![%d:%s]\n", errno, strerror(errno));
			continue;
		}
		// clientSocket is connected to a client!
		if (inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientName, sizeof(clientName)) == NULL)//inet_ntop() : 클라에서  온 목록을 읽을 수 있게 변환.
		{
			printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
			closesocket(clientSocket);
			continue;
		}

		printf("[%s:%d]", clientName, ntohs(clientAddress.sin_port));

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		const char* data[] = {
			"john", "david", "lee", "kim", "workd", "hello"
		};

		//=========================================================================================
		// 5.recv() - Receive message from client
		//=========================================================================================
		short req[2];

		int numBytesRcvd = recv(clientSocket, (char*)req,sizeof(short)*2, 0);
		
		req[0] = ntohs(req[0]);
		req[1] = ntohs(req[1]);
		
		printf("수신: [%d, %d]\n", req[0], req[1]);
		
		char sendstr[1024];
		int offset = 2;
		short len;
//		= htons(27);//총 길이.
//		memcpy(sendstr, &len, sizeof(short));//제일 앞에 전체 길이
		len = htons(req[1]);
		memcpy(sendstr + offset, &len, sizeof(short));//레코드 카운트
		offset += sizeof(short);

		for (short i = 0; i < req[1]; i++)
		{
			len = strlen(data[i]);
			short tlen = htons(len); //---------------------------------------------------------------------------------------------------┐
			memcpy(sendstr + offset/*세트가 시작되는 위치,몇글자 나올 지 예고*/, &tlen, sizeof(short));//                            [이렇게 한세트]
			offset += sizeof(short);
			memcpy(sendstr + offset/*내용이 시작되는 위치*/, data[i], len);//   --------------------------------------------------------┘
			offset += len;
		}
		len = htons(offset);//총 길이.
		memcpy(sendstr, &len, sizeof(short));//제일 앞에 전체 길이
				//len = htons(10); //---------------------------------------------------------------------------------------------------┐
		//memcpy(sendstr +4/*세트가 시작되는 위치,몇글자 나올 지 예고*/, &len, sizeof(short));//                            [이렇게 한세트]
		//memcpy(sendstr +6/*내용이 시작되는 위치*/, "I love you", 10);//   -------------------------------------------------┘

		//len = htons(9); 
		//memcpy(sendstr + 16/*세트가 시작되는 위치,몇글자 나올 지 예고*/, &len, sizeof(short));
		//memcpy(sendstr + 18/*내용이 시작되는 위치*/,"2조(하트)", 9);

		send(clientSocket, sendstr, offset, 0);

		printf("전송 완료\n");

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		closesocket(clientSocket); // Close client socket
	}
	WSACleanup();

	return 1;



}
