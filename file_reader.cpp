#include "file_reader.h"
#include <iostream>
#include <string>

using namespace std;

//  Database db;

int main(int argc, char** argv) {
	File_Reader fr;
	fr.read_customers();
	return 0;
}

bool File_Reader::read_customers() {
	const char* file_name = "userprofile.txt";

	// Open the file
	cout << "Attempting to open " << file_name << "...";

	ifstream users;
	users.open(file_name);
	if (users.is_open()) {
		cout << " Success!\n";
	}
	else {
		cout << "Error, unable to open file\n";
		return false;
	}

	// File has successfully been opened
	// Read in a line
	// The first line is the attributes for the table
	string attributes;
	getline(users, attributes);

	File_Reader fr;
	// Table customers;

	string token = get_token(attributes);
	while (token != "") {
		// customers.add_attribute(token, string);
		cout << token << endl;
		token = get_token(attributes);
	}

	// Read in the customers' data
	string customer;
	getline(users, customer);
	cout << customer << endl;

	users.close();
}

std::string File_Reader::get_token(string& _line) {
	long index = _line.find('\t');
	if (index == -1) {
		string line = _line;
		_line = "";
		return line;
	}	

	std::string token = _line.substr(0, index);
	_line = _line.substr(index + 1);
	return token;
}
