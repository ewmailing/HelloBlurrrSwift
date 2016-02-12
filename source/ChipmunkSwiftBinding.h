//
//  SDLSwiftBinding.h
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#ifndef __SwiftSDL__ChipmunkSwiftBinding__
#define __SwiftSDL__ChipmunkSwiftBinding__

#include "chipmunk.h"

/// Set a collision handler to be used whenever the two shapes with the given collision types collide.
/// You can pass NULL for any function you don't want to implement.
void EXT_cpSpaceAddCollisionHandler(
	cpSpace *space,
	cpCollisionType a, cpCollisionType b,
	cpCollisionBeginFunc begin,
	cpCollisionPreSolveFunc preSolve,
	cpCollisionPostSolveFunc postSolve,
	cpCollisionSeparateFunc separate,
	void *data
);



#endif /* defined(__SwiftSDL__ChipmunkSwiftBinding__) */
