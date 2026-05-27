#include "Replace.hpp"
#include <sstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
       std::cout << "Wrong number of arguments "<< '\n';
	   std::cout << argv[0] <<"<filname> <old_str> <new_str>" << std::endl;
        return 1;
    }
	std::string filname;
	std::string oldStr;
	std::string newStr;
	filname = argv[1];
	oldStr = argv[2];
	newStr = argv[3];

	std::ifstream infile(filname.c_str());
	if (!infile.is_open())
	{
   	 	std::cerr << "Error: Could not open file" << std::endl;
   	 	return 1;
	}
	std::ofstream outfile((filname + ".replace").c_str());
	 if (!outfile.is_open()) {
        std::cerr << "Error: could not create output file\n";
        return 1;
    }
	std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
	infile.close();
	std::string processed = replace_all(content, oldStr, newStr);
	outfile << processed;
	outfile.close();
	return 0;
}