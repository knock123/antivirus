#include <iostream>
#include <fstream>
#include <dirent.h>
#include <bitset>

#if !defined(ANTIVIRUS)
#define ANTIVIRUS

// returns name of virus/trogan.
std::string Name(std::string str)
{
    std::string name;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '=') {break;}        
        else {name.push_back(str[i]);}
    }
    return name;
}

// returns signature of virus/trojan
std::string Signature(std::string str)
{
    std::string signature;
    for (int i = (str.find_first_of('='))+1; i < str.length(); i++)
    {
        signature.push_back(str[i]);
    }
    return signature;
}


void CountFoldersFiles (std::string  givenPath)
{   
    static int files = 0;
    static int folders = 0;
    std::string slash = "/";
    std::string path = givenPath;
    DIR* dir = nullptr;
    struct dirent* ptr;
    dir = opendir(path.c_str()); // change string parameter to c string before using.
    std::string currentDir = ".";
    std::string parentDir = "..";

    while ((ptr=readdir(dir)) != NULL)
    {
        // if it is a directory
        if (ptr->d_type == DT_DIR)
        {
            if ((ptr->d_name) == (currentDir) || (ptr->d_name) == (parentDir))
            {
                continue;
            }
            else
            {
                std::cout << "directory: " << ptr->d_name << std::endl;
                folders++;
                path = givenPath + slash + (ptr->d_name);
                CountFoldersFiles(path.c_str());
            }
            
        }
        // if its not a directory
        else
        {
            std::cout << ptr->d_name << std::endl;
            files++;
        }
    }
    std::cout << std::endl;
    closedir(dir);
    // if (ptr == NULL)
    // {
    //     std::cout << "\n" << "scanned: " << "folders: " << folders << " files: " << files << std::endl;
    // }
}

void Traverse (std::string givenPath)
{
    static int files = 0;
    static int folders = 0;
    std::string slash = "/";
    std::string path = givenPath;
    DIR* dir = nullptr;
    struct dirent* ptr;
    dir = opendir(path.c_str()); // change string parameter to c string before using.
    std::string currentDir = ".";
    std::string parentDir = "..";

    while ((ptr=readdir(dir)) != NULL)
    {
        // if it is a directory
        if (ptr->d_type == DT_DIR)
        {
            if ((ptr->d_name) == (currentDir) || (ptr->d_name) == (parentDir))
            {
                continue;
            }
            else
            {
                std::cout << "directory: " << ptr->d_name << std::endl;
                folders++;
                path = givenPath + slash + (ptr->d_name);
                Traverse(path.c_str());
            }
            
        }
        // if its not a directory
        else
        {
            std::cout << ptr->d_name << std::endl;
            files++;
        }
    }
    std::cout << std::endl;
    closedir(dir);
}

std::string HexToBinary (std::string hex)
{
    std::bitset<4>hexBinary0(hex[0]);
    std::bitset<4>hexBinary1(hex[1]);
    std::string hex0 = (std::string)(hexBinary0.to_string());
    std::string hex1 = (std::string)(hexBinary1.to_string());
    std::string hexStr = hex0 + hex1;
    return hexStr;
}

std::string AsciiToBinary (char c)
{
    std::bitset<8>binary(c); // cast parameter c to bitset
    std::string binaryString = (std::string)(binary.to_string()); // bitset to string
    return binaryString;
}

bool Scan (std::string file, std::string virusDB)
{
    std::ifstream targetFile(file);
    std::string fileLine;
    
    //start reading file line-by-line
    while(getline(targetFile, fileLine))
    {
        for (int i = 0; i < fileLine.length(); i++)
        {
            std::string ascBin = AsciiToBinary(fileLine[i]);
            std::string DBline;
            std::ifstream DataBase(virusDB);
            while(getline(DataBase, DBline))
            {
                std::string signature = Signature(DBline);
                int hexIndex = 0;
                std::string hex;
                hex.push_back((signature[hexIndex]));
                hex.push_back(signature[hexIndex+1]);
                
                // if first char in fileLine and first hex in DBline dont match no need to match the rest.
                if (ascBin != HexToBinary(hex))
                {
                    break;
                }
                else {continue;}
                
            }

        }
    }
}



#endif // ANTIVIRUS

