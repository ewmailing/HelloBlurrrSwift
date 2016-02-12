//
//  SDLSwiftBinding.c
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#include "SDLSwiftBinding.h"

#include "SDL.h"

/*
SDL_EventType SDL_EXT_EventGetType(SDL_Event the_event)
{
	return the_event.type;
}

SDL_EventType SDL_EXT_EventGetTypeFromPtr(SDL_Event* the_event)
{
	if(NULL == the_event)
	{
		return 0; // ?
	}
	return SDL_EXT_EventGetType(*the_event);
}

*/

SDL_PixelFormat* SDL_EXT_GetPixelFormat(SDL_Surface* the_surface)
{
	if(NULL == the_surface)
	{
		return NULL;
	}
	return the_surface->format;
}


int SDL_GameControllerAddMappingsFromFile(const char* file)
{
	return SDL_GameControllerAddMappingsFromRW(SDL_RWFromFile(file, "rb"), 1);
}



int SDL_RWclose(SDL_RWops* ctx)
{
	return ctx->close(ctx);
}