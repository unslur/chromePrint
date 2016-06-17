// NativeMessaging.cpp : 定义控制台应用程序的入口点。
//

#pragma comment(lib,"comsupp.lib") 
//#include "zlib.h"
//#pragma comment(lib,"Zlib.lib")

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;
typedef bool(__stdcall *fxjkOpenKeyEx)(char* cPassWord);
typedef void(__stdcall *fxjkClose)();
typedef char*(__stdcall *fxjkReadSector)(char* value, long iSector);
typedef char*(__stdcall *fxjkReadCluster)(long iCluster);
typedef bool(__stdcall *fxjkWriteSector)(string cDataWrite, long iSector);
typedef bool(__stdcall *fxjkWriteCluster)(string cDataWrite, long iSector);
typedef bool(__stdcall *fxjkChangePwd)(string cOldPwd, string cNewPwd);
typedef bool (__stdcall *fxjkGetSerial)(char* Serial);
fxjkOpenKeyEx Open = NULL;
fxjkClose Close = NULL;
fxjkGetSerial GetSerial = NULL;
fxjkChangePwd ChangePwd = NULL;
fxjkWriteSector WriteSector = NULL;
fxjkReadSector ReadSector = NULL;

//#define __MYDEBUG__

int UkeyInit();


string function(vector<string> RecvStr);
bool sendMessage(string message);
string recvMessaage();
bool vaildIn=false;
std::string msg ="";//接受的字符串
DWORD WINAPI ThreadFun(LPVOID pM)  
{ 
	std::string msg_pre=msg;
	while (true)
	{
		Sleep(1000*2);
		if (msg_pre==msg)
		{
			exit(0);
		}
		msg_pre=msg;
	} 
	
	return 0;  
} 
int countnum=0;
int main()
{
	
	HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL); 
	while (1)
	{
		
#ifndef __MYDEBUG__
		//MessageBox(NULL, "ssss", NULL, MB_OK);
		msg = recvMessaage();  
#endif // !__MYDEBUG__
		vaildIn=true;

#ifdef __MYDEBUG__
		// s
		//msg = "#DownloadData#ea1965c52c6bbd1b885ac666da8e8e68 153169228 1459308128428604153 211.88.22.174 8888#";  
		//m
		//msg = "#printWine#http://182.148.107.188:18082/jiusy/time/index.html\n品名:时间的味道\n年份:2016年\n产地:泸州\n香型:浓香型\n等级:优级\n溯源码:25417852145632145214\n|http://182.148.107.188:18082/jiusy/time/index.html\n品名:时间的味道\n年份:2016年\n产地:泸州\n香型:浓香型\n等级:优级\n溯源码:25417852145632145214\n#3#";  
		//msg="#GetNumber#1165 2081457406245301128 100#";
		msg="#printNew2#http://cdcspt.zyczs.gov.cn/zycqt/receive/search?code=51012730061805200001915090100000047\\n溯源码:82345678908234567890123456789011\\n品 名:三七\\n重    量:20g\\n产 地:云南文山市\\n生产日期:2012.09.18\\n批 号:887966530187G\\n厂家:云南天虹中药材有限虹中药材有限虹中药材有限\\n|*CPC*ZYCZS12345678901234567890123456789022\\n溯源码:82345678908234567890123456789022\\n品 名:三七\\n重    量:20g\\n产 地:云南文山市\\n生产日期:2012.09.18\\n批 号:887966530187G\\n厂 家:云南天虹中药材有限公司\\n#3#";
#endif // __MYDEBUG__

		
		//MessageBox(NULL, msg.c_str(), NULL, MB_OK);
		std::string message = "{\"text\":\"297\"}";
		msg = U2G(msg.c_str());
		//MessageBox(NULL, msg.c_str(), NULL, MB_OK);
		if (msg.find("#stop#") != string::npos)
		{
			break;
		}
		if (msg.find("Listen") != string::npos)
		{

			sendMessage( "{\"text\":\"296\"}");
			continue;
		}
		//MessageBox(NULL, msg.c_str(), NULL, MB_OK);
		vector<string> receiveStr = VsplitPrintStr(msg);
		message = function(receiveStr);
		
		if (!sendMessage(message))
		{
			MessageBox(NULL, message.c_str(), NULL, MB_OK);
		}
			
		

		
	}
	//char ss[25]={0};
	//itoa(countnum,ss,10);
	//MessageBox(NULL,ss, NULL, MB_OK);
    return 0;
}

string function(vector<string> RecvStr) {
	try
	{
	int rtn = 0;
	method fun;
	
	if (RecvStr[1] == "printNew") 
	{
		rtn = fun.printNew(RecvStr[2].c_str(), nullptr, atoi(RecvStr[3].c_str()));
		if (rtn < 1)
		{
			return  "{\"text\":\"failed\"}";
		} 
	}
	else if (RecvStr[1] == "printNew3")
	{
		rtn =fun.printNew3(RecvStr[2], nullptr, atoi(RecvStr[3].c_str()));
		if (rtn<1)
		{ 
			return "{\"text\":\"317\"}";//打印失败
		}
	}
	else if (RecvStr[1] == "DownloadData")
	{
		
			return  "{\"text\":\"" + fun.DownloadData(RecvStr[2].c_str()) + "\"}";
	}
	else if (RecvStr[1]=="printNew2")
	{
		//countnum++;
		rtn=fun.printNew_1(RecvStr[2], nullptr, atoi(RecvStr[3].c_str()));
		//rtn=1;
		if (rtn<1)
		{

			return "{\"text\":\"317\"}";//打印失败
		}
	}
	else if (RecvStr[1] == "GetNumber")
	{
		
		return "{\"text\":\"" + fun.GetNumber(RecvStr[2].c_str()) + "\"}";
	}
	else if (RecvStr[1] == "ReadRFID2")
	{
		//return "\"" + fun.ReadRFID2(atoi(RecvStr[2].c_str())) + "\"";
		return "{\"text\":\""+fun.ReadRFID2(atoi(RecvStr[2].c_str()))+"\"}";
	}
	else if (RecvStr[1] == "WriteRFID2")
	{
		return "{\"text\":\""+fun.WriteRFID2(RecvStr[2].c_str(), atoi(RecvStr[3].c_str()))+"\"}";
	}
	else if (RecvStr[1] == "printtag2")
	{
		//countnum++;
		rtn = fun.printtag2(RecvStr[2].c_str(), nullptr, atoi(RecvStr[3].c_str()));
		//rtn=1;
		if (rtn < 1)
		{
			return  "{\"text\":\"317\"}";//打印失败
		}

	}
	else if (RecvStr[1] == "ReadUkey")
	{
		return "{\"text\":\""+fun.readUkey(10)+"\"}";
	}
	else if (RecvStr[1] == "WriteUkey")
	{
		
		
		return "{\"text\":\""+fun.writeUkey(RecvStr[2])+"\"}";
	}
	else if (RecvStr[1] == "printWhite") 
	{
		rtn = fun.printWhite(RecvStr[2].c_str(), nullptr, atoi(RecvStr[3].c_str()));
		if (rtn < 1)
		{
			return  "{\"text\":\"317\"}";//打印失败
		} 
	}
	else if (RecvStr[1] == "printWine") 
	{
		rtn = fun.printWine(RecvStr[2].c_str(), nullptr, atoi(RecvStr[3].c_str()));
		if (rtn < 1)
		{
			return  "{\"text\":\"317\"}";//打印失败
		} 
	}
	/*else if (RecvStr[1] == "")
	{

	}*/
	else
	{

		return  "{\"text\":\"300\"}";
	}

	}
	catch (const std::exception&e)
	{
		MessageBox(NULL, e.what(), NULL, MB_OK);
		return "{\"text\":\"315\"}";//异常
	}
	return "{\"text\":\"297\"}";//打印成功

}



bool sendMessage(string message) {
	/*if (IDNO == MessageBox(NULL, message.c_str(), NULL, MB_YESNO)) {
		exit(-1);
	};*/
	message = Gb2312ToUtf8(message.c_str());
	bool flag = false;
	UINT len = message.length();
	std::cout << char(len >> 0)
		<< char(len >> 8)
		<< char(len >> 16)
		<< char(len >> 24);
	std::cout << message << std::flush;
#ifdef __MYDEBUG__
	getchar();  
#endif // __MYDEBUG__

	 flag=true;
	 return flag;
}
string recvMessaage() {
	std::string msg = "";//接受的字符串
	unsigned int length = 0;
	for (int i = 0; i < 4; i++) {//前四个字节为支付串长度控制
		unsigned int read_char = getchar();
		length = length | (read_char << i * 8);
	}

	for (int i = 0; i < length; i++) {
		msg += getchar();
	}
	return msg;
}
//////////////////////////






int UkeyInit() {
	try
	{
		HINSTANCE gt = LoadLibrary("xjkKeyMana.dll");
		if (gt == NULL) {
			return 1;//动态链接库加载失败
		}
		Open = (fxjkOpenKeyEx)GetProcAddress(gt, "xjkOpenKeyEx");

		Close = (fxjkClose)GetProcAddress(gt, "xjkCloseKey");
		GetSerial = (fxjkGetSerial)GetProcAddress(gt, "xjkGetSerial");
		ChangePwd = (fxjkChangePwd)GetProcAddress(gt, "xjkChangePwd");
		WriteSector = (fxjkWriteSector)GetProcAddress(gt, "xjkWriteSector");
		ReadSector = (fxjkReadSector)GetProcAddress(gt, "xjkReadSector");
		if (!Open || !Close || !GetSerial || !ChangePwd || !WriteSector || !ReadSector)
		{

			return 2;
		}

		bool rtn = Open("helloword");
		if (!rtn)
		{
			rtn = Open("888888");
			if (!rtn)
			{


				return 3;
			}
			return 0;

		}
	}
	catch (const std::exception&)
	{
		return 4;
	}
	return -1;
}