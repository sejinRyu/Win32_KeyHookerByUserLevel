#include "../EchoServer.h"
#include <fstream>

int main()
{
	system("title server");
	try
	{
		EchoServer server;
		std::ofstream swag("D:\\key.txt", std::ios::out | std::ios::app);
		std::cout << "connect" << std::endl;
		while (true)
		{
			auto tmp = server.receiveString();
			swag << tmp;
			std::cout << tmp;
		}
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}
	return 0;
}