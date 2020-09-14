/*
 * FileUtils.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: devel
 */

#include <fstream>
#include <string>
#include <cerrno>
#include <iostream>
#include <algorithm>

#include "file_utils.hpp"

namespace license {
using namespace std;

string get_file_contents(const char *filename, size_t max_size) {
	ifstream in(filename, std::ios::binary);
	if (in) {
		string contents;
		size_t index = (size_t)in.seekg(0, ios::end).tellg();
		size_t limited_size = min(index, max_size);
		contents.resize(limited_size);
		in.seekg(0, ios::beg);
		in.read(&contents[0], limited_size);
		return contents;
	}
	throw(errno);
}

string remove_extension(const string& path) {
	if (path == "." || path == "..") {
		return path;
	}
	size_t dotpos = path.find_last_of(".");
	//no dot
	if (dotpos == string::npos) {
		return path;
	}
	//find the last path separator
	size_t pathsep_pos = path.find_last_of("\\/");
	if (pathsep_pos == string::npos) {
		return (dotpos == 0 ? path : path.substr(0, dotpos));
	} else if(pathsep_pos >= dotpos +1) {
		return path;
	}
	return path.substr(0, dotpos);
}

}
