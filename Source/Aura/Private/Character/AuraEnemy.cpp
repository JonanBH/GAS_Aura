// Copyright Armabit


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAuraEnemy::HighlightActor()
{
	if(USkeletalMeshComponent* CharacterMesh = GetMesh())
	{
		CharacterMesh->SetRenderCustomDepth(true);
		CharacterMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}

	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void AAuraEnemy::UnHighlightActor()
{
	

	if(USkeletalMeshComponent* CharacterMesh = GetMesh())
	{
		CharacterMesh->SetRenderCustomDepth(false);
		CharacterMesh->SetCustomDepthStencilValue(0);
	}

	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
		Weapon->SetCustomDepthStencilValue(0);
	}
}