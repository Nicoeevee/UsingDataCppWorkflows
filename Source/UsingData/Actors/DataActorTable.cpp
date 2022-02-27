// Fill out your copyright notice in the Description page of Project Settings.


#include "DataActorTable.h"

#if WITH_EDITOR
void ADataActorTable::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!bRunCode || ItemType == EItemType::None) { return; }

	if (ItemDataTable)
	{
		// Get clean Row Name
		const FName RowName = FName(UEnum::GetDisplayValueAsText(ItemType).ToString());
		FItemInformationTable* Row = ItemDataTable->FindRow<FItemInformationTable>(RowName, "Item Details");
		
		if(Row)
		{
			GenericItemInfo.ItemType = Row->ItemType;
			GenericItemInfo.Mesh = Row->Mesh;
			GenericItemInfo.ItemCost = Row->ItemCost;
			GenericItemInfo.ItemImage = Row->ItemImage;
			GenericItemInfo.ItemInfo = Row->ItemInfo;
			GenericItemInfo.ItemName = Row->ItemName;
			GenericItemInfo.CurveFloat = Row->CurveFloat;
			GenericItemInfo.RotationDuration = Row->RotationDuration;

			Mesh->SetStaticMesh(GenericItemInfo.Mesh);

			mFloatCurve = GenericItemInfo.CurveFloat;
			mRotationDuration = GenericItemInfo.RotationDuration;
		}
	}
	
}
#endif
