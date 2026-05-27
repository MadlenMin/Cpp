#include "Replace.hpp"

std::string replace_all(const std::string& content, 
                        const std::string& oldStr, 
                        const std::string& newStr) {
    if (oldStr.empty()) {
        return content;
    }
    
    std::string result;
    size_t i = 0;
    
    while (i < content.length()) {
        if (i + oldStr.length() <= content.length() &&
            content.substr(i, oldStr.length()) == oldStr) {
            result += newStr;
            i += oldStr.length();
        } else {
            result += content[i];
            i++;
        }
    }
 
    return result;
}