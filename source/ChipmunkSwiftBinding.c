//
//  ALmixerSwiftBinding.c
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#include "ChipmunkSwiftBinding.h"

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
)
{
	cpCollisionHandler* collision_handler = cpSpaceAddCollisionHandler(space, a, b);
	if(begin)
	{
		collision_handler->beginFunc = begin;
	}
	if(preSolve)
	{
		collision_handler->preSolveFunc = preSolve;
	}
	if(postSolve)
	{
		collision_handler->postSolveFunc = postSolve;
	}
	if(separate)
	{
		collision_handler->separateFunc = separate;
	}
	collision_handler->userData = data;
}


