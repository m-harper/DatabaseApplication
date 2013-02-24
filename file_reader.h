#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <fstream>

class File_Reader {
public:
	bool read_customers();
	std::string get_token(std::string&);
};

#endif
