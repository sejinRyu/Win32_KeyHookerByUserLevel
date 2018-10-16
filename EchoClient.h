#pragma once
#include <iostream>
#include <string>
#include <array>
#include <thread>
#include <boost/asio.hpp>
#include <Windows.h>
#include <string.h>
#include "../DataType.h"

class EchoClient
{
private:
	const char* serverIP;
	const uByte2 port;
	boost::asio::io_service ioService;
	boost::asio::ip::tcp::endpoint endPoint;
	boost::asio::ip::tcp::socket socket;
	boost::system::error_code error;
	boost::system::error_code ignoredError;
public:
	EchoClient(const char* serverIP = "10.156.146.164",	//10.156.146.164
		const uByte2 port = 6974)
		:serverIP(serverIP),
		port(port),
		endPoint(boost::asio::ip::address::from_string(serverIP), port),
		socket(ioService)
	{
		socket.connect(endPoint, error);
		if (error)
		{
			throw error;
		}
	}
	~EchoClient()
	{
		socket.close();
	}

	auto sendwString(const std::wstring msg)
	{
		const wchar_t* buf = msg.c_str();
		SizeType bufSize = msg.length() * 2;
		socket.write_some(boost::asio::buffer(buf, bufSize), ignoredError);
		return;
	}
	auto receivewString()
	{
		wchar_t buf[1024] = { 0, };
		socket.read_some(boost::asio::buffer(buf, 1024), error);
		if (error)
		{
			if (error == boost::asio::error::eof)
				throw "connect end";
			else throw error;
		}
		std::wstring ret(buf);
		return ret;
	}

	auto sendString(const std::string msg)
	{
		const char* buf = msg.c_str();
		SizeType bufSize = msg.length();
		socket.write_some(boost::asio::buffer(buf, bufSize), ignoredError);
		return;
	}
	auto receiveString()
	{
		char buf[1024] = { 0, };
		socket.read_some(boost::asio::buffer(buf, 1024), error);
		if (error)
		{
			if (error == boost::asio::error::eof)
				throw "connect end";
			else throw error;
		}
		std::string ret(buf);
		return ret;
	}
};