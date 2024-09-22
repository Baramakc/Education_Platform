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

bool is_date_available(SOCKET *sock, std::string str, std::string name_date) {
	if (name_date == "login") {
		send(*sock, "is_login", 9, 0);
		send(*sock, str.c_str(), 20, 0);
		char is_bool[6];
		recv(*sock, is_bool, 6, 0);
		if (is_bool == "true") return true;
		else if (is_bool == "false") return false;
		else std::cout << "Incoorrect answer";
		return false;
	}
}
