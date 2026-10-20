// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define DRAW_SPHERE(Location) \
		if(GetWorld()) DrawDebugSphere( \
		GetWorld(), Location, 25.f, 12, FColor::Red, true);

#define DRAW_LINE(Start, END) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, END, FColor::Red, true, -1.f, 0, 1.f);

#define DRAW_POINT(End) \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Red, true);

#define DRAW_VECTOR(Start, End) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, End, FColor::Red, true, -1.f, 0, 1.f); \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Red, true);