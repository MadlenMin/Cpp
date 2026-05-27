#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments " << '\n';
        std::cout << argv[0] << " <filename> <old_str> <new_str>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string oldStr   = argv[2];
    std::string newStr   = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += '\n';
    }
    infile.close();

    std::string processed = replace_all(content, oldStr, newStr);
    outfile << processed;
    outfile.close();

    return 0;
}