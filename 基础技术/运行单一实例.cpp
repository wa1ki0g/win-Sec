//程序判断的原理，用CreatMutex函数创建一个命名的互斥对象，如果对象调用成功
//而且通过调用GetLastError函数获取的返回码为ERROR_ALREADY_EXISTS,则表示该
//命名互斥对象存在，即程序重复运行。否则认为程序是首次运行。

#include <stdio.h>
#include <windows.h>
 BOOL IsAlready()
 {
 	HANDLE hmutex = NULL;
 	hmutex = ::CreateMutex(NULL,FALSE,"TEST");
 	if(hmutex)
 	{
 		if(ERROR_ALREADY_EXISTS == ::GetLastError())
 		{
 			return TRUE;
		 }
		 
	 }
	 return FALSE;
 }
 int WINAPI WinMain(HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow)
 {
 	BOOL flag = IsAlready();
 	if (flag == TRUE)
 	{
 		printf("already");
 		
	 }
	 else printf("NOT already");
	 system("pause");
	 return 0;
 }
