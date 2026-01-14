// Copyright Afonso Pordeus.


#include "Characters/AuraEnemy.h"

AAuraEnemy::AAuraEnemy()
{

}

void AAuraEnemy::HighlightActor()
{
	bDebugHighlighted = true;
}

void AAuraEnemy::UnHighlightActor()
{
	bDebugHighlighted = false;
}
