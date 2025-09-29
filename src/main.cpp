#include <iostream>
#include <set>
#include <string>
#include "messages.hpp"
#include "avl_tree.hpp"
#include <regex>
#include <sstream>

bool validUFID(std::string ufid) {
	std::regex ufidReg("^[0-9]{8}$");
	return std::regex_match(ufid, ufidReg);
}

bool validCommand(std::string cmd) {
	std::set<std::string> cmds = {"insert", "remove", "search", "printInorder", "printPreorder", "printPostorder", "printLevelCount", "removeInorder"};
	return cmds.count(cmd) > 0;
}

int main() {
	int numOfCmd;
	std::cin >> numOfCmd;
	std::cin.ignore();
	AVLTree tree;
	std::string line;

	// I used geeks for geeks for the istringstream stuff (https://www.geeksforgeeks.org/cpp/stringstream-c-applications/)
	for (int i = 0; i < numOfCmd; i++) {
		if (!std::getline(std::cin, line)) {
			break;
		}
		if (line.empty()) {
			continue;
		}

		std::istringstream iss(line);
		std::string cmd;
		iss >> cmd;

		if (!validCommand(cmd)) {
			std::cout << msg::UNSUCCESS << std::endl;
			continue;
		}

		if (cmd == "insert") {
			std::string name, ufid;
			iss >> name;
			iss >> ufid;
			name = name.substr(1, name.length() - 2); // remove quotation marks
			if (name.empty() || ufid.empty() || !validUFID(ufid)) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			int id = std::stoi(ufid);
			tree.insert(name, id);
		}

		if (cmd == "remove") {
			std::string ufid;
			iss >> ufid;
			if (ufid.empty() || !validUFID(ufid)) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			int id = std::stoi(ufid);
			tree.remove(id);
		}

		if (cmd == "search") {
			std::string param;
			iss >> param;
			if (param.empty()) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			bool isName = false;
			for (char c : param) {
				if (!isdigit(c)) {
					isName = true;
					break;
				}
			}
			if (isName) {
				if (param.front() != '"' || param.back() != '"' || param.length() < 2) {
					std::cout << msg::UNSUCCESS << std::endl;
					continue;
				}
				param = param.substr(1, param.length() - 2);
				tree.search(param);
			} else {
				if (!validUFID(param)) {
					std::cout << msg::UNSUCCESS << std::endl;
					continue;
				}
				int id = std::stoi(param);
				tree.search(id);
			}
		}

		if (cmd == "printInorder") {
			tree.printInOrder();
		}

		if (cmd == "printPreorder") {
			tree.printPreOrder();
		}

		if (cmd == "printPostorder") {
			tree.printPostOrder();
		}

		if (cmd == "printLevelCount") {
			tree.printLevelCount();
		}

		if (cmd == "removeInorder") {
			std::string n_str;
			iss >> n_str;
			if (n_str.empty()) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			bool isName = false;
			for (char c : n_str) {
				if (!isdigit(c)) {
					isName = true;
					break;
				}
			}
			if (isName) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			int n = std::stoi(n_str);
			if (n <= 0) {
				std::cout << msg::UNSUCCESS << std::endl;
				continue;
			}
			tree.removeInOrder(n);
		}
	}
	return 0;
}