#include "resource_add.h"
#include <windows.h>
#include <stdio.h>
#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")  
static char* resourcePath = NULL;

static char* lastFileName = NULL;

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
	if (lastFileName)
	{
		free(lastFileName);
		lastFileName = NULL;
	}
	lastFileName = (char*)malloc(strlen(resourcePath) + strlen(filename));

	strcpy(lastFileName, resourcePath);
	strcat(lastFileName, filename);

	return lastFileName;
}