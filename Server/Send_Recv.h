#pragma once
#include <winsock2.h>
#include <iostream>


void recv_message(SOCKET* sock) {
	char msg[1024];
	recv(*sock, msg, 1024, 0);
	std::cout << msg;
}

void send_message(SOCKET* sock, std::string msg) {

	send(*sock, msg.c_str(), 1024, 0);
}