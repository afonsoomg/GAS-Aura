// Copyright Afonso Pordeus.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"

#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
		AAuraEnemy();

	    /** ~Begin of IEnemyInterface   */
		virtual void HighlightActor() override;
		virtual void UnHighlightActor() override;
		/** ~End of IEnemyInterface   */

};
