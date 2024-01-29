#pragma once

#define DRAW_TRACKING_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true); // this is MACRO
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_TRCKING_LINE(StartLocation, EndLocation, LineDistance) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation * LineDistance, FColor::Black, true, -1.0f, 0, 2.0f); 
#define DRAW_LINE(StartLocation, EndLocation, LineDistance) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation * LineDistance, FColor::Black, false, -1.0f, 0, 2.0f); // this is MACRO
#define DRAW_TRCKING_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Black, true);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Black, false, -1.f);
#define DRAW_TRACKING_VECTOR(StartLocation, EndLocation, LineDistance) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation * LineDistance, FColor::Black, true, -1.0f, 0, 2.0f); \
		DrawDebugPoint(GetWorld(), StartLocation + EndLocation * LineDistance, 15.f, FColor::Black, true); \
	}
#define DRAW_VECTOR(StartLocation, EndLocation, LineDistance) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation * LineDistance, FColor::Black, false, -1.0f, 0, 2.0f); \
		DrawDebugPoint(GetWorld(), StartLocation + EndLocation * LineDistance, 15.f, FColor::Black, false, -1.0f); \
	}
