// Fill out your copyright notice in the Description page of Project Settings.


#include "DataLibrary.h"

bool UDataLibrary::SaveTable(FString SaveDirectory, FString FileName, UDataTable* DataTable, bool AllowOverwriting)
{
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!DataTable) { return false; }
	if (!AllowOverwriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	return FFileHelper::SaveStringToFile(DataTable->GetTableAsCSV(), *SaveDirectory);
}
