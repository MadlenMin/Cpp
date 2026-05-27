#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string replace_all(const std::string& content, 
                        const std::string& oldStr, 
                        const std::string& newStr);
#endif