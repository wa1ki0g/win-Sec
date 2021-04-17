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
