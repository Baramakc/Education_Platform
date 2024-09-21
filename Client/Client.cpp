#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#pragma warning(disable: 4996)

#include <iostream>
#include <string>

#include "Interface.h"



int main() {
	WORD dllver = MAKEWORD(2, 1);
	WSADATA wsad;

	if(WSAStartup(dllver, &wsad)){
		std::cout << "dll error";
	}

	

	SOCKADDR_IN addr_info;
	memset(&addr_info, 0, sizeof(SOCKADDR_IN));

	addr_info.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr_info.sin_port = htons(4321);
	addr_info.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(sListen, (SOCKADDR*)&addr_info, sizeof(addr_info)) == 0) {
		std::cout << "Client connected with Server!\n";
		Client_Inteface client_inteface(&sListen);
	}

	system("pause");
	return 0;
}