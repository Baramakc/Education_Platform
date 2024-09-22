#pragma once
#include <winsock2.h>
#include "Client_date.h"
#include <thread>
#include "Send_Recv.h"

class Client_Inteface {
	SOCKET* sock;
	Date date;

	//Сделать приём данных на сервере
	void send_date() {

	}

	//Сделать отправку данных при регестрации или изменени бщих данных на сервер
	void recv_date(Date date) {

	}

	void exam(const std::string const date, const std::string name_date, bool &buffer) {
		buffer = is_date_available(sock, date, name_date);
	}


	void autorization() {
		while (true) {
			std::string oth_login, oth_password;
			std::cout << "Input your login: "; std::cin >> oth_login;
			bool is_login = false, is_password = false;
			std::thread thread_login(&Client_Inteface::exam,oth_login, "login", is_login);
			thread_login.detach();
			std::cout << "Input your password: "; std::cin >> oth_password;
			std::thread thread_passord(&Client_Inteface::exam,oth_password, "password", is_password);
			thread_passord.detach();
			
		}
	}

	void registration() {
		std::string oth_login, oth_password, oth_name, oth_role;
		do {
			std::cout << "Input your login: "; std::cin >> oth_login;
			if (oth_login.length() > 5 && oth_login.length() < 20) break;
			else std::cout << "Login size less four simvols\nReturn please\n";
		} while (true);
		do {
			std::string buffer;
			std::cout << "Input your password: "; std::cin >> oth_password;
			std::cout << "Input your password again: "; std::cin >> buffer;
			if ((oth_password == buffer) && (oth_password.length() > 5 && oth_password.length() < 20)) break;
			else std::cout << "The passwords are not the same\nReturn please\n";
		} while (true);
		std::cout << "Input your name: "; std::cin >> oth_name;
		std::cout << "Input your role(teacher, student, parent): "; std::cin >> oth_role;
		date.set_key();
		date.set_login(oth_login); date.set_password(oth_password); date.set_userName(oth_name); date.set_role(oth_role);
		recv_date(date);
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

