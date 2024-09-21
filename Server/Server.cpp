#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#pragma warning(disable: 4996)

#include <iostream>
#include "experimental/filesystem"





int main() {
	WORD dllver = MAKEWORD(2, 1);
	WSADATA wsad;

	

	if (WSAStartup(dllver, &wsad)) {
		std::cout << "dll error";
	}

	SOCKADDR_IN addr_info;
	memset(&addr_info, 0, sizeof(SOCKADDR_IN));

	int size_addr = sizeof(addr_info);

	addr_info.sin_port = htons(4321);
	addr_info.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);
	bind(sListen, (SOCKADDR*)&addr_info, size_addr);
	listen(sListen, SOMAXCONN);

	SOCKET sConnect = accept(sListen, (SOCKADDR*)&addr_info, &size_addr);

	if (sConnect != 0) {
		std::cout << "Server connect with Client!";
		
	}

	system("pause");
	return 0;
}