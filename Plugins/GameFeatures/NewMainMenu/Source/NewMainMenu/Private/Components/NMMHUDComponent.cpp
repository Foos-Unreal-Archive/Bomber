﻿// Copyright (c) Yevhenii Selivanov

#include "Components/NMMHUDComponent.h"
//---
#include "Data/NMMDataAsset.h"
#include "MyUtilsLibraries/WidgetUtilsLibrary.h"
#include "UI/MyHUD.h"
#include "Widgets/NewMainMenuWidget.h"
#include "Widgets/NMMCinematicStateWidget.h"
//---
#include UE_INLINE_GENERATED_CPP_BY_NAME(NMMHUDComponent)

// Default constructor
UNMMHUDComponent::UNMMHUDComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

// Returns HUD actor of this component.
AMyHUD* UNMMHUDComponent::GetHUD() const
{
	return Cast<AMyHUD>(GetOwner());
}

AMyHUD& UNMMHUDComponent::GetHUDChecked() const
{
	AMyHUD* MyHUD = GetHUD();
	checkf(MyHUD, TEXT("%s: 'MyHUD' is null"), *FString(__FUNCTION__));
	return *MyHUD;
}

// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called
void UNMMHUDComponent::OnRegister()
{
	Super::OnRegister();

	const UNMMDataAsset& NewMainMenuDataAsset = UNMMDataAsset::Get(this);
	const AMyHUD& HUD = GetHUDChecked();

	constexpr int32 HighZOrder = 3;
	constexpr bool bAddToViewport = true;
	MainMenuWidgetInternal = HUD.CreateWidgetByClass<UNewMainMenuWidget>(NewMainMenuDataAsset.GetMainMenuWidgetClass(), bAddToViewport, HighZOrder);

	InCinematicStateWidgetInternal = HUD.CreateWidgetByClass<UNMMCinematicStateWidget>(NewMainMenuDataAsset.GetInCinematicStateWidgetClass());
}

// Clears all transient data created by this component
void UNMMHUDComponent::OnUnregister()
{
	// --- Destroy Main Menu widgets

	if (MainMenuWidgetInternal)
	{
		FWidgetUtilsLibrary::DestroyWidget(*MainMenuWidgetInternal);
		MainMenuWidgetInternal = nullptr;
	}

	if (InCinematicStateWidgetInternal)
	{
		FWidgetUtilsLibrary::DestroyWidget(*InCinematicStateWidgetInternal);
		InCinematicStateWidgetInternal = nullptr;
	}

	Super::OnUnregister();
}
