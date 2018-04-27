	#include <iostream>
	#include <Windows.h>
	#include <TlHelp32.h>
	#include <string>
	#include <chrono>
	#include <thread>

	using namespace std;
	
		#pragma region
		 
		#define JUNKS \
		__asm _emit 0x52 \
		__asm _emit 0x86 \
		__asm _emit 0xd2 \
		__asm _emit 0x26 \
		__asm _emit 0x63 \
		__asm _emit 0x96 \
		__asm _emit 0x61 \
		__asm _emit 0x26 \
		__asm _emit 0x92 \
		__asm _emit 0x49 \
		__asm _emit 0x95 \
		__asm _emit 0x54 \
		__asm _emit 0x23 \
		__asm _emit 0x6e \
		__asm _emit 0x45 \
		__asm _emit 0x56 \
		__asm _emit 0x15 \
		__asm _emit 0x46 \
		__asm _emit 0x97 \
		__asm _emit 0x52 \
		__asm _emit 0x86 \
		__asm _emit 0x23 \
		__asm _emit 0x15 \
		__asm _emit 0x25 \
		__asm _emit 0x35 \
		__asm _emit 0x61 \
		__asm _emit 0x26 \
		__asm _emit 0x95 \
		__asm _emit 0x56 \
		__asm _emit 0x15 \
		__asm _emit 0x46 \
		__asm _emit 0x97 \
		__asm _emit 0x10 \
		__asm _emit 0x74 \
		__asm _emit 0x38 \
		__asm _emit 0x12 \
		__asm _emit 0x19 \
		__asm _emit 0x35 \
		__asm _emit 0x95 \
		__asm _emit 0x37 \
		__asm _emit 0x82 \

		 
		#pragma endregion

	#define darkblue 1
	#define darkgreen 2
	#define cyan 3
	#define darkred 4
	#define lila 5
	#define gold 6
	#define white 7
	#define blue 9
	#define green 10
	#define red 11
	#define yellow 14

	#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

	DWORD GetPid(char* ProcessName)
	{
		_JUNK_BLOCK(jmp_label1)
			HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		_JUNK_BLOCK(jmp_label2)
			PROCESSENTRY32 ProcEntry;

		_JUNK_BLOCK(jmp_label3)
			ProcEntry.dwSize = sizeof(ProcEntry);

		_JUNK_BLOCK(jmp_label4)
			do
			{
				_JUNK_BLOCK(jmp_label5)
					if (!strcmp(ProcEntry.szExeFile, ProcessName))
					{
						_JUNK_BLOCK(jmp_label6)
							DWORD dwPID = ProcEntry.th32ProcessID;

						_JUNK_BLOCK(jmp_label7)
							CloseHandle(hPID);

						_JUNK_BLOCK(jmp_label8)
							return dwPID;
					}

				_JUNK_BLOCK(jmp_label9)
			} while (Process32Next(hPID, &ProcEntry));

				_JUNK_BLOCK(jmp_label10)
	}

	int main()
	{

		SetConsoleTitle("Karmas Injector <3");

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle, &info);
		COORD new_size =
		{
			info.srWindow.Right - info.srWindow.Left + 1,
			info.srWindow.Bottom - info.srWindow.Top + 1
		};
		SetConsoleScreenBufferSize(handle, new_size);

		string name_of_dll;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "Karmas Injector, made by Karma#0001 on discord, based on Random Injector\n \n";
		cout << "Sub to me on YouTube.com/channel/UCI7rZOQInIQ933tGCkQyKRA? ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cyan);
		cout << "pProspect.xyz/ \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "discord.gg/QUUamR3 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		cout << "That is my discord ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "Join and talk about anything ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		cout << "Karma#0001 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "Enjoy! ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), darkred);
		cout << "<3 \n \n";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "Your DLL name: \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
		cin >> name_of_dll;

		string checkfor = ".dll";

		if (!(name_of_dll.find(checkfor) != std::string::npos))
		{
			name_of_dll += ".dll";
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
		cout << "\nInjecting ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cyan);
		cout << name_of_dll + " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
		cout << "into ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cyan);
		cout << "Counter Strike: Global Offensive";


		LPCSTR DLL_NAME = name_of_dll.c_str();

		_JUNK_BLOCK(jmp_label11)
			DWORD dwProcess;

		_JUNK_BLOCK(jmp_label12)

			char myDLL[MAX_PATH];

		_JUNK_BLOCK(jmp_label13)
			GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);

		_JUNK_BLOCK(jmp_label14)
			dwProcess = GetPid("csgo.exe");

		_JUNK_BLOCK(jmp_label15)
			HANDLE Process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

		_JUNK_BLOCK(jmp_label16)
			LPVOID allocatedMem = VirtualAllocEx(Process, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

		_JUNK_BLOCK(jmp_label17)
			WriteProcessMemory(Process, allocatedMem, myDLL, sizeof(myDLL), NULL);

		_JUNK_BLOCK(jmp_label18)
			CreateRemoteThread(Process, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

		_JUNK_BLOCK(jmp_label19)
			CloseHandle(Process);

		_JUNK_BLOCK(jmp_label24)

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), darkred);
		cout << "\n \n! ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		cout << "This Injector doesn't check if the DLL sucessfully injected! You have to see by yourself.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), darkred);
		cout << " !";

		auto start3 = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(30s);
		auto end3 = std::chrono::high_resolution_clock::now();

		_JUNK_BLOCK(jmp_label25)
			return 0;
	}


































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































