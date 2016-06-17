#include "method.h"
//#include "zlib.h"


method::method()
{
}


method::~method()
{
}
//string codes;
//static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//	//int i;
//	char buff[0x50];
//	sprintf(buff, "%s,%s|", argv[0], argv[1]);
//	codes += buff;
//	/*for(int i=0; i<argc; i++){
//	codes += argv[i];
//	codes += ",";
//	//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//	printf("\n");
//	codes += "|";*/
//	return 0;
//}
const  string DefaultPrinter()
{
	TCHAR szBuffer[1024] = { 0 };
	DWORD length = 1024;
	int ret = ::GetDefaultPrinter(szBuffer, &length);
	
	return szBuffer;
}
//string GetDownData( const char* password, const char* dt, const char* taskID,  const char* ip, int port) {
//	char buff[0x100];
//	sprintf(buff, "%s,%s,%s", password, dt, taskID);
//	string sendStr = buff;
//	Socket so;
//	//so.CInit("192.168.0.215",5555);
//	so.CInit(ip, port);
//	so.CCreateSocket();
//	if (!so.CConnect()) {
//		so.CCloseSocket();
//		return "301";//连接服务器失败
//
//	}
//	so.Send(sendStr);
//
//
//	int recvInt = 0, allRecvLen = 0;
//	char* recvBuff = (char*)malloc( 0x400 *0x400* 10);
//	while (true) {
//		if (!so.Recv(recvBuff + allRecvLen, int(0x400), recvInt)) break;
//		allRecvLen += recvInt;
//	}
//	so.CCloseSocket();
//	//AfxMessageBox("收完");
//
//	if ((strstr(recvBuff, "error")) != NULL) {
//		string buff= recvBuff;
//		buff = buff.substr(buff.find("error")+6);
//		return buff;
//	}
//
//	LodePNG_DecompressSettings setting;
//	setting.ignoreAdler32 = 0;
//
//	unsigned char* zip_buffer = (unsigned char*)malloc(0x400 * 0x400 * 10);// 这个是输出缓冲
//	size_t zip_length; // 输出长度
//	//int ret=1;
//	//int ret= uncompress(zip_buffer, &zip_length, (Bytef*)recvBuff, allRecvLen);	
//	int ret = LodePNG_zlib_decompress(&zip_buffer, &zip_length, (unsigned char*)recvBuff, allRecvLen, &setting);
//	free(recvBuff);
//	recvBuff = NULL;
//	if (ret != 0) {
//		char buff[0x50];
//		sprintf(buff, "309", ret);//解压失败
//		return buff;
//	}
//	*(zip_buffer + zip_length) = 0;
//	char* p = (char*)zip_buffer;
//	//char* p = (char*)recvBuff;
//	/*char* q = strstr((char*)zip_buffer, " ");
//	*q = 0;
//	string orgID = p;
//	p = q + 1;*/
//
//	char sqlBuff[0x200];
//
//	filePath();//设置数据库目录文件
//
//	string rtn = FindAndCreatDB(DBPathName); //检测库
//	if (rtn != "OK") {
//		return rtn;
//	}
//
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	rc = sqlite3_open(DBPathName, &db);
//	if (rc) {
//		sqlite3_close(db);
//		sprintf(buff, "311", sqlite3_errmsg(db));//打开本地sqlite数据库文件失败
//		return buff;
//	}
//
//	sprintf(sqlBuff, "delete from number where  printtask_code='%s'",  taskID);
//	sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);//插入前清除无效数据
//	rc = sqlite3_exec(db, "BEGIN;", NULL, 0, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		sprintf(buff, "313", zErrMsg);
//		sqlite3_free(zErrMsg);
//		sqlite3_close(db);
//		return buff;
//	}
//	
//	list<string> vdata=splitPrintStr2(p,"|");
//	
//	for ( list<string>::iterator iter = vdata.begin();iter != vdata.end(); ++iter ){
//		string box=iter->substr(0,iter->find(","));
//	
//		if (box.length()>25)
//		{
//			
//			sprintf(sqlBuff, "insert into number(box_code,box_sourcecode,printtask_code,flag) values('%s','%s','%s',1)", box.c_str(), box.c_str() , taskID);
//			rc = sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);
//			if (rc != SQLITE_OK) {
//				sprintf(buff, "314", zErrMsg);//插入sqlite数据失败
//				sqlite3_free(zErrMsg);
//				sqlite3_close(db);
//				return buff;
//			}
//		}
//		
//		*iter=iter->substr(iter->find(",")+1);
//		list<string> vdata_small=splitPrintStr2(*iter,",");
//		for ( list<string>::iterator iter_small = vdata_small.begin();iter_small != vdata_small.end(); ++iter_small ){
//			sprintf(sqlBuff, "insert into number(box_code,box_sourcecode,printtask_code,flag) values('%s','%s','%s',2)", box.c_str(), iter_small->c_str() , taskID);
//			rc = sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);
//			if (rc != SQLITE_OK) {
//				sprintf(buff, "314", zErrMsg);
//				sqlite3_free(zErrMsg);
//				sqlite3_close(db);
//				return buff;
//			}
//		}
//
//		
//	}
//	//while (true) {
//	//	q = strstr(p, "|");
//	//	if (NULL == q) break;
//	//	*q = 0;
//	//	string record = p;
//	//	p = q + 1;
//
//	//	string code = record.substr(0, record.find(","));
//	//	record = record.substr(record.find(",") + 1);
//	//	//string flag = record.substr(record.find(",") + 1);
//	//	sprintf(sqlBuff, "insert into number(orgid,taskid,flag,code) values('%s','%s',%s,'%s')", orgID.c_str(), taskID, flag.c_str(), code.c_str());
//	//	rc = sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);
//	//	if (rc != SQLITE_OK) {
//	//		sprintf(buff, "SQL error: %s", zErrMsg);
//	//		sqlite3_free(zErrMsg);
//	//		sqlite3_close(db);
//	//		return buff;
//	//	}
//	//}
//	free(zip_buffer);
//	zip_buffer = NULL;
//
//	sqlite3_exec(db, "COMMIT;", NULL, 0, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		sprintf(buff, "SQL error: %s", zErrMsg);
//		sqlite3_free(zErrMsg);
//		sqlite3_close(db);
//		return buff;
//	}
//	sqlite3_close(db);
//	return "299";
//}
//string GetNumbers(const char* orgID, const char* taskID, int num, const char* dbPathName) {
//	char buff[0x200];
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	rc = sqlite3_open(dbPathName, &db);
//
//
//	sprintf(buff, "select box_sourcecode, flag from number where printtask_code='%s' limit 100", taskID, num);
//
//	codes = "";
//	rc = sqlite3_exec(db, buff, callback, 0, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		sprintf(buff, "316", zErrMsg);//本地数据库查询出错
//		sqlite3_free(zErrMsg);
//		sqlite3_close(db);
//		return buff;
//	}
//
//	if (codes.length() > 0)
//	{
//		codes = codes.substr(0, codes.length() - 1);
//	}
//	else
//	{
//		codes+="298";
//	}
//	return codes;
//}
//
//long method::printNew(string pp, LPCTSTR printerNameT, LONG nPrintType)
//{
//	string printStr = pp;
//	int rtn = 0;
//
//	char printerName[0x64] = { 0 };
//	strcpy(printerName, DefaultPrinter().c_str());
//
//	if (strstr(printerName, "Printer LP") != NULL
//		|| strstr(printerName, "Printer B") != NULL)
//	{
//		CTscPrinter printer;
//		printer.TscInit(printerName);
//		rtn = printer.PrintTsc2(NULL, printStr, nPrintType);
//		printer.TscUnInit();
//	}
//	else if (strstr(printerName, "POSTEK") != NULL)
//	{
//		CPskPrinter printer;
//		printer.PskInit(printerName);
//		rtn = printer.PrintPsk2(NULL, printStr, nPrintType);
//		printer.PskUnInit();
//	}
//	else if (strstr(printerName, "ZDesigner") != NULL || strstr(printerName, "Microsoft") != NULL)
//	{
//		CZbraPrinter printer;
//		rtn = printer.PrintZbra2(printerName, printStr, nPrintType);
//	}
//	else
//	{
//		MessageBox(NULL, "请检查是否正确设置默认打印机！", NULL, MB_OK);
//	}
//	return rtn;
//}
//
//long method::printNew_1(string pp, LPCTSTR printerNameT, LONG nPrintType)
//{
//	string printStr = pp;
//	int rtn = 0;
//
//	char printerName[0x64] = { 0 };
//	strcpy(printerName, DefaultPrinter().c_str());
//
//	if (strstr(printerName, "Printer LP") != NULL
//		|| strstr(printerName, "Printer B") != NULL)
//	{
//		CTscPrinter printer;
//		printer.TscInit(printerName);
//		rtn = printer.PrintTsc2_1(NULL, printStr, nPrintType);
//		printer.TscUnInit();
//	}
//	else if (strstr(printerName, "POSTEK") != NULL)
//	{
//		CPskPrinter printer;
//		if (!printer.PskInit(printerName))
//		{
//			//MessageBox(NULL, "请检查是否连接打印机！", NULL, MB_OK);
//			return 0;
//		}
//		
//		rtn = printer.PrintPsk2_1(NULL, printStr, nPrintType);
//		printer.PskUnInit();
//	}
//	else if (strstr(printerName, "ZDesigner") != NULL || strstr(printerName, "Microsoft") != NULL)
//	{
//		CZbraPrinter printer;
//		rtn = printer.PrintZbra2_1(printerName, printStr, nPrintType);
//	}
//	else
//	{
//		
//		MessageBox(NULL, "请检查是否正确设置默认打印机！", NULL, MB_OK);
//	}
//	return rtn;
//}
//
//long method::printNew3(string pp, LPCTSTR printerNameT, LONG nPrintType)
//{
//	string printStr = pp;
//	int rtn = 0;
//	
//	char printerName[0x64] = { 0 };
//	strcpy(printerName, DefaultPrinter().c_str());
//	
//	if (strstr(printerName, "Printer LP") != NULL
//		|| strstr(printerName, "Printer B") != NULL)
//	{
//		CTscPrinter printer;
//		printer.TscInit(printerName);
//		
//		rtn = printer.PrintTsc3(NULL, printStr, nPrintType);
//		printer.TscUnInit();
//	}
//	else if (strstr(printerName, "POSTEK") != NULL)
//	{
//		CPskPrinter printer;
//		printer.PskInit(printerName);
//		rtn = printer.PrintPsk3(NULL, printStr, nPrintType);
//		printer.PskUnInit();
//	}
//	else if (strstr(printerName, "ZDesigner") != NULL || strstr(printerName, "Microsoft") != NULL)
//	{
//		CZbraPrinter printer;
//		rtn = printer.PrintZbra3(printerName, printStr, nPrintType);
//	}
//	else
//	{
//		MessageBox(NULL,"请检查是否正确设置默认打印机！",NULL,MB_OK);
//	}
//	return rtn;
//	
//}
//
//string method::DownloadData(LPCTSTR inVar)
//{
//	string InVar = inVar;
//	string userID, password, dt, taskID, taskType, ip, port;
//	/*userID = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);*/
//
//	password = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//
//	dt = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//
//	taskID = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//
//	
//
//	ip = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//	port = InVar;
//	string rtnStr = GetDownData( password.c_str(), dt.c_str(), taskID.c_str(),  ip.c_str(), atoi(port.c_str()));
//	return rtnStr;
//}
//
//string method::GetNumber(LPCTSTR inVar)
//{
//	string InVar = inVar;
//	string userID, taskID;
//	int num;
//	userID = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//	taskID = InVar.substr(0, InVar.find(" "));
//	InVar = InVar.substr(InVar.find(" ") + 1);
//	num = atoi(InVar.c_str());
//	filePath();
//	
//	string rtnData = GetNumbers(userID.c_str(), taskID.c_str(), num, DBPathName);
//	return rtnData;
//}
//
//string method::ReadRFID2(LONG overTime)
//{	
//	string retstring = "";
//	CReader_Cmrf801u reader;
//	if (reader.QuestReader801InUse())
//	{
//		retstring = reader.ReadRFID_CMRF801U(overTime);
//
//	}
//	else
//	{
//		CReader_D3 reader;
//		if (reader.QuestReaderD3InUse())
//		{
//			retstring = reader.ReadRFID_D3(overTime);
//			//MessageBox(NULL,"d3",NULL,MB_OK);
//		}
//	}
//	return retstring;
//}
//
//string method::WriteRFID2(LPCTSTR codeStr, LONG mode)
//{
//	string strResult;
//	string retstring = "";
//	CReader_Cmrf801u reader;
//	if (reader.QuestReader801InUse())
//	{
//		retstring = reader.WriteRFID_CMRF801U(codeStr, mode);
//	}
//	else
//	{
//		CReader_D3 reader;
//		if (reader.QuestReaderD3InUse())
//		{
//			retstring = reader.WriteRFID_D3(codeStr, mode);
//			//AfxMessageBox("d3");
//		}
//	}
//	return strResult;
//}
//
//long method::printtag2(LPCTSTR pp, LPCTSTR printerNameT, LONG nPrintType)
//{
//	string printStr = pp;
//	int rtn = 0;
//
//	char printerName[0x64] = { 0 };
//	strcpy(printerName, DefaultPrinter().c_str());
//
//	if (strstr(printerName, "Printer LP") != NULL
//		|| strstr(printerName, "Printer B") != NULL)
//	{
//		CTscPrinter printer;
//		printer.TscInit(printerName);
//		rtn = printer.PrintTscTag2(NULL, printStr, nPrintType);
//		printer.TscUnInit();
//	}
//	else
//	{
//		MessageBox(NULL, "请检查是否正确设置默认打印机！", NULL, MB_OK);
//	}
//	return rtn;
//}
//string method::readUkey(int num){
//	Ukey key;
//	if(key.init()!="OK"){
//		return "init error";
//	};
//	return key.read(10);
//}
//string method::writeUkey(string data){
//	Ukey key;
//	if(key.init()!="OK"){
//		return "init error";
//	};
//	return key.write(data);
//}
long method::printWhite(string pp, LPCTSTR printerNameT, LONG nPrintType){
	string printStr = pp;
	int rtn = 0;

	char printerName[0x64] = { 0 };
	strcpy(printerName, DefaultPrinter().c_str());

	if (strstr(printerName, "POSTEK") != NULL)
	{
		CPskPrinter printer;
		printer.PskInit(printerName);
		rtn = printer.PrintPskWhite(NULL, printStr, nPrintType);
		printer.PskUnInit();
	}
	else if (strstr(printerName, "Printer LP") != NULL
			|| strstr(printerName, "Printer B") != NULL)
		{
			CTscPrinter printer;
			printer.TscInit(printerName);
			rtn = printer.PrintTscWhite(NULL, printStr, nPrintType);
			printer.TscUnInit();
		}
	else
	{
		MessageBox(NULL, "请检查是否正确设置默认打印机！", NULL, MB_OK);
	}
	return rtn;
}
//long method::printWine(string pp, LPCTSTR printerNameT, LONG nPrintType){
//
//	string printStr = pp;
//	int rtn = 0;
//
//	char printerName[0x64] = { 0 };
//	strcpy(printerName, DefaultPrinter().c_str());
//
//	if (strstr(printerName, "POSTEK") != NULL)
//	{
//		CPskPrinter printer;
//		printer.PskInit(printerName);
//		rtn = printer.PrintPsk2Wine(NULL, printStr, nPrintType);
//		printer.PskUnInit();
//	}
//	else
//	{
//		MessageBox(NULL, "请检查是否正确设置默认打印机！", NULL, MB_OK);
//	}
//	return rtn;
//
//}