/*
 * FileUtils.h
 *
 *  Created on: Apr 8, 2019
 *
 */

#ifndef FILEUTILS_H_
#define FILEUTILS_H_
#include <string>
#include <vector>

namespace license {


std::string get_file_contents(const char *filename,size_t max_size);
std::string remove_extension(const std::string& path);

} /* namespace license */

#endif
