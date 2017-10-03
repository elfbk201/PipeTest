#pragma once
#include <string>

class Pipe
{
	int i = 0;
public:
	std::string ReadPipe(std::string name);
	bool CheckPipe(std::string cool [][2] ,int s,std::string str);
};