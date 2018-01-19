#include <stdio.h>
#include <Windows.h>
#include<time.h>
#include <tchar.h>

#define DIV 1024
#define WIDTH 7
#define GB(x) (((x).HighPart << 2) + ((DWORD)(x).LowPart) / 1024.0 / 1024.0 / 1024.0)

#pragma warning(disable: 4996)   

#define true 1
typedef	unsigned char U_CHAR;

//linux use this(gcc)
#define __int64 long long
//windows use this(vc++)
//#define __int64 __int64 

//get the system time
int getSystemTime(char* buffer){
	char buf[128];
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buf, sizeof(buf), "Now is %Y-%m-%d %H:%M:%S", timeinfo);
	strcpy(buffer,buf);
}

//get the cpu useage
FILETIME m_preidleTime;
FILETIME m_prekernelTime;
FILETIME m_preuserTime;
__int64 CompareFileTime2(FILETIME time1, FILETIME time2)
{
	__int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime;
	__int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime;
	return   b - a;
}
double CpuUseage()
{
	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;
	GetSystemTimes(&idleTime, &kernelTime, &userTime);

	double idle = CompareFileTime2(m_preidleTime, idleTime);
	double kernel = CompareFileTime2(m_prekernelTime, kernelTime);
	double user = CompareFileTime2(m_preuserTime, userTime);

	if (kernel + user == 0)
		return 0.0;
	//(all-empty)/all=cpu useage%
	double cpu = abs((kernel + user - idle) * 100.0 / (kernel + user));
	m_preidleTime = idleTime;
	m_prekernelTime = kernelTime;
	m_preuserTime = userTime;
	return cpu;
}
void getCPU(U_CHAR  sysStateCpu[5]){
	double cpu = CpuUseage();
	sprintf((char*)sysStateCpu, "%.2lf", cpu);
}

void getMemory(U_CHAR bufPreCPU[5]){
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	sprintf(bufPreCPU, "%d.00", statex.dwMemoryLoad);
}

int main(int argc, char *args[]){
	U_CHAR  sysStateCpu[5];
	if(argc>1){
		//CPU useage
		if(strcmp("cpu",args[1])==0){
			getCPU(sysStateCpu);
			printf("%s%%",sysStateCpu);
		}
		//memory useage
		else if(strcmp("memory",args[1])==0){
			
			getMemory(sysStateCpu);
			printf("%s%%",sysStateCpu);
		}
	}else{
		getCPU(sysStateCpu);
		printf("cpu:%s%%\n",sysStateCpu);
		getMemory(sysStateCpu);
		printf("memory:%s%%\n",sysStateCpu);
	}
	return 0;
}
