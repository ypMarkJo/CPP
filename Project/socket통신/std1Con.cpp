//std1Console.cpp

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	int ret;
	//---------------------------------------------------------
	//Validate

	const char* serverip = "164.125.123.41";
	short port = 5000;

	short count = 7;
	if (argc == 2) count = (short)atoi(argv[1]);
	if (count <= 0||count>6) count = 7;
	printf("request Count:%d\n", count);
	if (count == 7)
	{
		printf("Wrong number! The number should be between 1~6\n");
		return 0;
	}
	
	
	else
	{
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		//----------------------------------------------------------
		//initialize windows socket
		WSADATA wsaDAta = { 0, };
		ret = WSAStartup(MAKEWORD(2, 2), &wsaDAta);
		if (ret != 0)
		{
			printf("WSAStartup failed: %d\n", ret);
			return 1;
		}

		//----------------------------------------------------------
		// socket
		SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//소켓은 주소와 포트번호로 구성
		if (sock == INVALID_SOCKET)
		{
			printf("socket() failed![%d]\n", WSAGetLastError());
			WSACleanup();//WS2_32.DLL 사용을 종료
			return 1;
		}

		//----------------------------socket address
		sockaddr_in name;
		memset(&name, 0x00, sizeof(name));//memory set : 형태를 초기화
		name.sin_family = AF_INET;
		inet_pton(AF_INET, serverip, &name.sin_addr);//텍스트 형태의 IP주소를 binary형태로 변환
		name.sin_port = htons(port);//big endian과 little endian을 변환

		// connect
		if (connect(sock, (sockaddr*)&name, sizeof(name)) == SOCKET_ERROR)
		{
			printf("socket()failed![%d]\n", WSAGetLastError());
			closesocket(sock);//서버 소켓 종료
			WSACleanup();//WS2_32.DLL 사용(소켓통신)을 종료
			return 1;
		}

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		short type[2];//0번 테이블에서 2개만 보내달라.
		type[0] = htons(0);
		type[1] = htons(count);

		//send
		if (send(sock, (const char*)type, sizeof(type), 0) == SOCKET_ERROR)
		{
			printf("send() failed![% d]\n", WSAGetLastError());
		}
		else
			printf("success\n");

		short tlen;
		recv(sock, (char*)&tlen, sizeof(short), 0);//전체 길이
		tlen = ntohs(tlen);

		short cnt;
		recv(sock, (char*)&cnt, sizeof(short), 0); //개수
		cnt = ntohs(cnt);

		char buf[1024];
		short slen;
		for (int i = 0; i < cnt; i++)
		{
			recv(sock, (char*)&slen, sizeof(short), 0);//문자열 길이
			slen = ntohs(slen);

			recv(sock, buf, slen, 0);//문자열 길이
			buf[slen] = '\0';

			printf("%s\n", buf);
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	closesocket(sock);
	WSACleanup();
	}
}