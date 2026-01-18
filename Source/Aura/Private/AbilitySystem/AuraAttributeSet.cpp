// Copyright Afonso Pordeus.

#include "AbilitySystem/AuraAttributeSet.h"
#include <Net/UnrealNetwork.h>

// Macro para simplificar OnRep functions
#define DEFINE_ONREP_FUNCTION(ClassName, PropertyName) \
void ClassName::OnRep_##PropertyName(const FGameplayAttributeData& Old##PropertyName) const \
{ \
	GAMEPLAYATTRIBUTE_REPNOTIFY(ClassName, PropertyName, Old##PropertyName); \
}

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(25);
	InitMaxMana(100);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

DEFINE_ONREP_FUNCTION(UAuraAttributeSet, Health)
DEFINE_ONREP_FUNCTION(UAuraAttributeSet, MaxHealth)
DEFINE_ONREP_FUNCTION(UAuraAttributeSet, Mana)
DEFINE_ONREP_FUNCTION(UAuraAttributeSet, MaxMana)
#undef DEFINE_ONREP_FUNCTION
