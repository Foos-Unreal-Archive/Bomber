﻿// Copyright (c) Yevhenii Selivanov

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
//---
#include "NMMUtils.generated.h"

enum class ENMMState : uint8;

class UMovieSceneSequencePlayer;

/**
 * Static helper functions about New Main Menu.
 */
UCLASS(Blueprintable, BlueprintType, DisplayName = "New Main Menu Utils")
class NEWMAINMENU_API UNMMUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/*********************************************************************************************
	 * Object getters
	 ********************************************************************************************* */
public:
	/** Returns New Main Menu Subsystem. */
	UFUNCTION(BlueprintCallable, Category = "C++", DisplayName = "Get NMM Base Subsystem", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMBaseSubsystem* GetBaseSubsystem(const UObject* OptionalWorldContext = nullptr);

	/** Returns Spots Manager. */
	UFUNCTION(BlueprintCallable, Category = "C++", DisplayName = "Get NMM Spots Subsystem", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMSpotsSubsystem* GetSpotsSubsystem(const UObject* OptionalWorldContext = nullptr);

	/** Returns the Data Asset of the Main Menu. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM Data Asset", meta = (WorldContext = "OptionalWorldContext"))
	static const class UNMMDataAsset* GetDataAsset(const UObject* OptionalWorldContext = nullptr);

	/** Returns the HUD component of the Main Menu. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM HUD Component", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMHUDComponent* GetHUDComponent(const UObject* OptionalWorldContext = nullptr);

	/** Returns the Player Controller component of the Main Menu. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM Player Controller Component", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMPlayerControllerComponent* GetPlayerControllerComponent(const UObject* OptionalWorldContext = nullptr);

	/** Returns the widget of the Main Menu. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM Main Menu Widget", meta = (WorldContext = "OptionalWorldContext"))
	static class UNewMainMenuWidget* GetMainMenuWidget(const UObject* OptionalWorldContext = nullptr);

	/** Returns the widget of the In Cinematic State. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM In Cinematic State Widget", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMCinematicStateWidget* GetInCinematicStateWidget(const UObject* OptionalWorldContext = nullptr);

	/** Returns the Save Game data of the Main Menu. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NMM Save Game Data", meta = (WorldContext = "OptionalWorldContext"))
	static class UNMMSaveGameData* GetSaveGameData(const UObject* OptionalWorldContext = nullptr);

	/*********************************************************************************************
	 * Cinematic helpers
	 ********************************************************************************************* */
public:
	/** Returns true if given cinematic wants to skip. */
	UFUNCTION(BlueprintPure, Category = "C++")
	static bool ShouldSkipCinematic(const struct FNMMCinematicRow& CinematicRow);

	/** Returns the Playback Settings by given cinematic state. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NNM Cinematic Settings")
	static const struct FMovieSceneSequencePlaybackSettings& GetCinematicSettings(ENMMState MainMenuState);

	/** Returns the total frames of the cinematic by given cinematic state. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NNM Cinematic Total Frames")
	static int32 GetCinematicTotalFrames(ENMMState MainMenuState, const UMovieSceneSequencePlayer* LevelSequencePlayer);

	/** Return the playback position params by given cinematic state. */
	UFUNCTION(BlueprintPure, Category = "C++", DisplayName = "Get NNM Playback Position Params")
	static struct FMovieSceneSequencePlaybackParams GetPlaybackPositionParams(ENMMState MainMenuState, const UMovieSceneSequencePlayer* LevelSequencePlayer);
};
