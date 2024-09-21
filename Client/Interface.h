#pragma once
#include <winsock2.h>
#include "Client_date.h"

class Client_Inteface {
	SOCKET* sock;
	Date date;

	void autorization() {

	}

	void registration() {
		std::string oth_login, oth_password, oth_name, oth_role;
		do {
			std::cout << "Input your login: "; std::cin >> oth_login;
			if (oth_login.size() > 5) break;
			else std::cout << "Login size less four simvols\nReturn please\n";
		} while (true);
		do {
			std::string buffer;
			std::cout << "Input your password: "; std::cin >> oth_password;
			std::cout << "Input your password again: "; std::cin >> buffer;
			if (oth_password == buffer) break;
			else std::cout << "The passwords are not the same\nReturn please\n";
		} while (true);
		std::cout << "Input your name: "; std::cin >> oth_name;
		std::cout << "Input your role(teacher, student, parent): "; std::cin >> oth_role;
		date.set_key();
		date.set_login(oth_login); date.set_password(oth_password); date.set_userName(oth_name); date.set_role(oth_role);
		autorization();
	}

	void first_inteface() {
		while (true) {
			std::cout << "\nHello user!\nChoose an action:\n1 - Autorization\n2 - Registration\n";
			int choose; std::cout << "Input: "; std::cin >> choose;
			switch (choose) {
			case 1: autorization();
			case 2: registration();
			default: std::cout << "Uncorrect number!";
			}
		}
	}
public:
	Client_Inteface(SOCKET* oth_sock) {
		this->sock = oth_sock;
		this->first_inteface();
	}
	~Client_Inteface() {
		delete sock;
	};
};

