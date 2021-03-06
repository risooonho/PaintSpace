// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetComponent.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Leap_NoPI.h"
#include "HandMenuWidgetComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class PAINTSPACE_API UHandMenuWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
	
public:
	UHandMenuWidgetComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

/*	UFUNCTION(BlueprintCallable, Category = "Event")
	static void OnHMWComponentOverlapBegin(class AActor* OtherActor, class PrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION(BlueprintCallable, Category = "Event")
	static void OnHMWComponentOverlapEnd(class AActor* OtherActor, class PrimitiveComponent* OtherComponent, int32 OtherBodyIndex);*/

private:
	void CheckLeapFrame();
	void ChangeMenuState();

	Leap::Controller LeapController;
	int64_t PrevFrameID;
	class UHandMenuWidget* HandMenuWidgetInstance;
	UHandMenuWidgetComponent* HMWComponentParent;
	TArray<UHandMenuWidgetComponent*> HMWComponentChildren;

	bool HasLeftHand;
	bool PalmFacingPlayer;
	bool MenuShowing;
	
};
