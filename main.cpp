#include <iostream>
#include <Windows.h>

DWORD BaseAddress = 0x509B74;
DWORD Entities = 0x50F500;

int main()
{
	//UPDATED FOR EASIER READABILITY!
	
	DWORD Health = 0xF8;
	DWORD ARammo = 0x150;

	int healthvalr = static_cast<int>((BaseAddress) + Health);
	
	int* healhval = &healthvalr;
	
	int BH = *(int*)BaseAddress + Health;
	
	//-------------------------------

	int ammovaluer = static_cast<int>((BaseAddress)+ARammo);
	
	int* ammovalue = &ammovaluer;
	
	int AH = *(int*)BaseAddress + ARammo;
	
    while(1)
	{
		*(int*)BH = 1337; //derefcast to assign new values
		*(int*)AH = 42069;	    
	}
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{

	if (dwReason == DLL_PROCESS_ATTACH) {

		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);

	}
	return TRUE;
}
