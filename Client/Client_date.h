#pragma once
#include <iostream>


class Date {
	std::string login;
	std::string password;
	std::string userName;
	std::string role;
	
	//Время захода

	char key;
    std::string hash(std::string buffer) {
        for (int i = 0; i < buffer.length(); i++) {
            if(buffer[i]%2 == 0) std::swap(buffer[i], buffer[buffer.length() - i - 1]);
        }
        return buffer + key;
    }
    std::string rehash(std::string buffer) {
        buffer.pop_back();
        for (int i = buffer.length() - 1; i >= 0; i--) {
            if (buffer[i] % 2 == 0) std::swap(buffer[i], buffer[buffer.length() - i - 1]);
        }
    }
public:
    std::string get_login() {
        return rehash(this->login);
    }
    std::string get_password() {       
        return rehash(this->password);
    }
    char get_key() {
        return this->key;
    }
    std::string get_userName() {        
        return rehash(this->userName);
    }
    std::string get_role() {
        return this->role;
    }

    std::string get_hash_login() {
        return this->login;
    }
    std::string gethash__password() {
        return this->password;
    }
    char get_hash_key() {
        return this->key;
    }
    std::string get_hash_userName() {
        return this->userName;
    }
    std::string get_hash_role() {
        return this->role;
    }


    void set_login(std::string buffer) {
        hash(buffer);
        this->login = buffer;
    }
    void set_userName(std::string buffer) {
        hash(buffer);
        this->userName = buffer;
    }
    void set_role(std::string buffer) {
        this->role = buffer;
    }
    void set_password(std::string buffer) {
        hash(buffer);
        this->password = buffer;
    }
    void set_key() {
        int buffer = rand() % 50;
        this->key = (char)buffer;
    }
    void set_key(char buffer) {
        this->key = buffer;
    }

};