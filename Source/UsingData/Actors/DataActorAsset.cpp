// Fill out your copyright notice in the Description page of Project Settings.


#include "DataActorAsset.h"

#include "UsingData/Data/ItemDataAsset.h"

#if WITH_EDITOR
void ADataActorAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!bRunCode || ItemType == EItemType::None) { return; }

	if (ItemDataAsset)
	{
		for (int i = 0; i < ItemDataAsset->ItemInfoArray.Num(); i++)
		{
			if (ItemDataAsset->ItemInfoArray[i].ItemType== ItemType)
			{
				GenericItemInfo = ItemDataAsset->ItemInfoArray[i];

				Mesh->SetStaticMesh(GenericItemInfo.Mesh);

				mFloatCurve = GenericItemInfo.CurveFloat;
				mRotationDuration = GenericItemInfo.RotationDuration;
				break;
			}
		}
	}
}
#endif
