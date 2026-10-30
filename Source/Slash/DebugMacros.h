#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) \
		if(GetWorld()) DrawDebugSphere( \
		GetWorld(), Location, 25.f, 12, FColor::Red, true);

#define DRAW_SPHERE_SingleFrame(Location) \
		if(GetWorld()) DrawDebugSphere( \
		GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);

#define DRAW_LINE(Start, END) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, END, FColor::Red, true, -1.f, 0, 1.f);

#define DRAW_LINE_SingleFrame(Start, END) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, END, FColor::Red, false, -1.f, 0, 1.f);

#define DRAW_POINT(End) \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Red, true);

#define DRAW_POINT_SingleFrame(End) \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Red, false, -1.f);

#define DRAW_VECTOR(Start, End) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, End, FColor::Red, true, -1.f, 0, 1.f); \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Red, true);

#define DRAW_VECTOR_ARROW(Start, End) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, End, FColor::Green, true, -1.f, 0, 1.f); \
		if(GetWorld()) DrawDebugDirectionalArrow( \
		GetWorld(), Start, End, 20.f, FColor::Green, true, -1.f);

#define DRAW_VECTOR_SingleFrame(Start, End) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, End, FColor::Green, false, -1.f, 0, 1.f); \
		if(GetWorld()) DrawDebugPoint( \
		GetWorld(), End, 15.f, FColor::Green, false, -1.f);

#define DRAW_VECTOR_ARROW_SingleFrame(Start, End) \
		if(GetWorld()) DrawDebugLine( \
		GetWorld(), Start, End, FColor::Green, false, -1.f, 0, 1.f); \
		if(GetWorld()) DrawDebugDirectionalArrow( \
		GetWorld(), Start, End, 20.f, FColor::Green, false, -1.f);