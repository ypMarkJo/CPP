#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //printf
#include <stdlib.h>//atoi
#include <string.h> //strerror()
#include <errno.h>//errno- ���� ��ȣ�� ��������.
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

	//���� ���̺귯�� �ʱ�ȭ
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
		clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);//�����¿��� ������ �Ǹ� �ٷ� �����Է�.connect �õ��ϸ� ���� ����
		if (clientSocket < 0)
		{
			printf("accept()failed![%d:%s]\n", errno, strerror(errno));
			continue;
		}
		// clientSocket is connected to a client!
		if (inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientName, sizeof(clientName)) == NULL)//inet_ntop() : Ŭ�󿡼�  �� ����� ���� �� �ְ� ��ȯ.
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
		
		printf("����: [%d, %d]\n", req[0], req[1]);
		
		char sendstr[1024];
		int offset = 2;
		short len;
//		= htons(27);//�� ����.
//		memcpy(sendstr, &len, sizeof(short));//���� �տ� ��ü ����
		len = htons(req[1]);
		memcpy(sendstr + offset, &len, sizeof(short));//���ڵ� ī��Ʈ
		offset += sizeof(short);

		for (short i = 0; i < req[1]; i++)
		{
			len = strlen(data[i]);
			short tlen = htons(len); //---------------------------------------------------------------------------------------------------��
			memcpy(sendstr + offset/*��Ʈ�� ���۵Ǵ� ��ġ,����� ���� �� ����*/, &tlen, sizeof(short));//                            [�̷��� �Ѽ�Ʈ]
			offset += sizeof(short);
			memcpy(sendstr + offset/*������ ���۵Ǵ� ��ġ*/, data[i], len);//   --------------------------------------------------------��
			offset += len;
		}
		len = htons(offset);//�� ����.
		memcpy(sendstr, &len, sizeof(short));//���� �տ� ��ü ����
				//len = htons(10); //---------------------------------------------------------------------------------------------------��
		//memcpy(sendstr +4/*��Ʈ�� ���۵Ǵ� ��ġ,����� ���� �� ����*/, &len, sizeof(short));//                            [�̷��� �Ѽ�Ʈ]
		//memcpy(sendstr +6/*������ ���۵Ǵ� ��ġ*/, "I love you", 10);//   -------------------------------------------------��

		//len = htons(9); 
		//memcpy(sendstr + 16/*��Ʈ�� ���۵Ǵ� ��ġ,����� ���� �� ����*/, &len, sizeof(short));
		//memcpy(sendstr + 18/*������ ���۵Ǵ� ��ġ*/,"2��(��Ʈ)", 9);

		send(clientSocket, sendstr, offset, 0);

		printf("���� �Ϸ�\n");

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		closesocket(clientSocket); // Close client socket
	}
	WSACleanup();

	return 1;



}
