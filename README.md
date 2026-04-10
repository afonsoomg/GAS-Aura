# GAS-Aura

A technical study project focused on learning and applying Unreal Engine 5's Gameplay Ability System (GAS) in an RPG-style character framework.

This repository documents my hands-on exploration of core GAS concepts such as:

- Ability System Component setup
- AttributeSet creation and replication
- Gameplay Effect application
- PlayerState-based GAS ownership
- HUD and widget integration with gameplay attributes
- Character initialization flow for multiplayer-safe GAS setup

The project is being developed as a C++-driven Unreal Engine study, with emphasis on understanding architecture, data flow, and the relationship between gameplay systems and UI.

---
## Learning Context

This project was developed as a hands-on technical study while following the Udemy course *Unreal Engine 5 GAS Top Down RPG*.

The purpose of this repository is to deepen my understanding of Unreal Engine 5's Gameplay Ability System (GAS), gameplay architecture, and RPG-oriented system design through practical implementation in C++.

Rather than presenting this as a fully original game project, I treat it as a structured learning repository focused on studying:

- Ability System Component setup
- AttributeSets and replication
- Gameplay Effect application
- character and player state responsibilities
- gameplay-to-UI communication
- scalable Unreal gameplay architecture

This repository is part of my broader effort to strengthen my skills as a gameplay programmer focused on Unreal Engine, C++, and maintainable gameplay systems.

## Overview

`GAS-Aura` is a study project built to better understand how Gameplay Ability System is structured and initialized inside an Unreal Engine RPG framework.

Rather than treating GAS as a black box, the goal here is to break the system into understandable parts:

- where the Ability System Component should live
- how attributes are declared, replicated, and clamped
- how Characters, PlayerState, and HUD communicate
- how Gameplay Effects are applied to targets
- how UI can react to attribute changes through widget controllers

This project is focused on code structure and system understanding.

---

## Current Technical Focus

The repository currently explores:

### GAS foundation
- Custom `AbilitySystemComponent`
- Custom `AttributeSet`
- GAS ownership through `PlayerState`
- Character-side initialization through `PossessedBy` and `OnRep_PlayerState`

### Attributes and replication
- Health / MaxHealth
- Mana / MaxMana
- Replication notifications (`OnRep_*`)
- Value clamping in `PreAttributeChange`
- Post-effect hooks with `PostGameplayEffectExecute`

### Character and player architecture
- `AuraCharacterBase` implementing `IAbilitySystemInterface`
- `AuraCharacter` handling player-side GAS initialization
- `AuraPlayerState` owning ASC + AttributeSet
- Separation between base character logic and player-controlled character logic

### Gameplay Effects
- `AuraEffectActor` for applying effects to overlapping targets
- Support for:
  - Instant effects
  - Duration effects
  - Infinite effects
- Configurable application and removal policies

### UI integration
- `AuraHUD`
- `AuraUserWidget`
- Widget Controller layer
- Overlay widget controller broadcasting:
  - Health
  - Max Health
  - Mana
  - Max Mana

This structure follows a “systems first” approach, where gameplay data is exposed cleanly to UI instead of hardwiring widget logic directly into gameplay classes.

---

## Project Goals

This repository was created as a technical learning project to improve skills in:

- Unreal Engine 5 C++
- Gameplay Ability System
- Gameplay architecture
- Replication-aware system design
- Character / PlayerState / HUD responsibilities
- Data-driven UI updates from gameplay systems

The broader goal is to build a stronger understanding of how scalable RPG gameplay systems can be organized in Unreal.

---

## Tech Stack

- **Unreal Engine 5**
- **C++**
- **Gameplay Ability System (GAS)**
- **UMG / HUD integration**
- **Replication-ready gameplay structure**

---

## Repository Structure

```text
Source/
├── Aura/
│   ├── Public/
│   │   ├── AbilitySystem/
│   │   │   ├── AuraAbilitySystemComponent.h
│   │   │   └── AuraAttributeSet.h
│   │   ├── Actors/
│   │   │   └── AuraEffectActor.h
│   │   ├── Characters/
│   │   │   ├── AuraCharacter.h
│   │   │   ├── AuraCharacterBase.h
│   │   │   └── AuraEnemy.h
│   │   ├── Game/
│   │   │   └── AuraGameModeBase.h
│   │   ├── Interaction/
│   │   ├── Player/
│   │   │   ├── AuraPlayerController.h
│   │   │   └── AuraPlayerState.h
│   │   └── UI/
│   │       ├── HUD/
│   │       │   └── AuraHUD.h
│   │       ├── WidgetControllers/
│   │       │   ├── AuraWidgetController.h
│   │       │   └── OverlayWidgetController.h
│   │       └── Widgets/
│   │           └── AuraUserWidget.h
│   ├── Private/
│   │   ├── AbilitySystem/
│   │   ├── Actors/
│   │   ├── Characters/
│   │   ├── Game/
│   │   ├── Interaction/
│   │   ├── Player/
│   │   └── UI/
│   ├── Aura.Build.cs
│   ├── Aura.cpp
│   └── Aura.h
