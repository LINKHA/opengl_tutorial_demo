#include "resource_add.h"
#include <windows.h>
#include <stdio.h>
#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")  
static char* resourcePath = NULL;

char lastFileName[_MAX_PATH];

char* register_dir()
{
	if (resourcePath)
		return resourcePath;

	char exePath[_MAX_PATH];
	GetModuleFileName(0, exePath, _MAX_PATH);
	PathRemoveFileSpec(exePath);

	char* lastName = "\\..\\..\\Binaries\\";

	resourcePath = (char*)malloc(strlen(exePath) + strlen(lastName));

	strcpy(resourcePath, exePath);
	strcat(resourcePath, lastName);

	return resourcePath;
}

char* file_name(char* filename)
{
	memset(lastFileName, 0, sizeof(lastFileName));

	strcpy(lastFileName, resourcePath);
	strcat(lastFileName, filename);

	return lastFileName;
}