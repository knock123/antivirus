#include <iostream>
#include "antivirus.hpp"
#include <bitset>

int hex_to_binary(std::string hex);

int main(int argc, char *argv[])
{
/*
    std::ofstream fileWriter;

    // File Open
    fileWriter.open("File_1.txt");
    fileWriter << "this is a test file." << std::endl;
    fileWriter << "second line of the file." << std::endl;
    fileWriter << "third line of the file." << std::endl;

    std::ifstream fileReader;
    std::string myline;

    fileReader.open(argv[1]);
    if (fileReader.is_open())
    {
        while (getline(fileReader, myline))
        {
            std::cout << myline << std::endl;
        }
    fileReader.close();
    }    
    else
    {
        std::cout << "File not fond, please try again" << std::endl;
    }

    // File Close
    fileWriter.close();
    return 0;
*/
    // ANTIVIRUS::Traverse(".");
    
    // DIR* dirr = nullptr;
    // struct dirent* ptrr;
    // dirr = opendir(".");
    // ptrr=readdir(dirr);
    // std::string line;
    
    // std::ifstream File(ptrr->d_name);
    // while (getline(File, line))
    // {
    //     std::cout << line << std::endl;
    // }

    std::string nameANDsignature = "TestVirus.D=255044462d312e340a332030206f62";
    
    std::string somestring = "some";
    std::string another = "another";
    // for (int i = 0; i < somestring.length(); i++)
    // {
    //     for (int j = 0; j < another.length(); j++)
    //     {
    //         if (another[j] == 't') {break;}
    //         else {std::cout << another[j] << std::endl;}
    //     }
    // }

    char a = 'a';
    std::
    std::cout << ANTIVIRUS::AsciiToBinary(a) << std::endl;
}

