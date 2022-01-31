#include <iostream>
#include <Windows.h>

DWORD BaseAddress = 0x509B74;
DWORD Entities = 0x50F500;

int main()
{
	DWORD Health = 0xF8;
	DWORD ARammo = 0x150;
	//read
	float healthval = *reinterpret_cast<int*>(*reinterpret_cast<uintptr_t*>(BaseAddress) + Health);
	int Arammoval = *reinterpret_cast<int*>(*reinterpret_cast<uintptr_t*>(BaseAddress) + ARammo);

	//write
	do
	{
	*reinterpret_cast<int*>(*reinterpret_cast<uintptr_t*>(BaseAddress) + Health) = 99999;
	*reinterpret_cast<int*>(*reinterpret_cast<uintptr_t*>(BaseAddress) + ARammo) = 1337;
	} while (healthval <= 0 || healthval <= 100);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{

	if (dwReason == DLL_PROCESS_ATTACH) {

		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);

	}
	return TRUE;
}
