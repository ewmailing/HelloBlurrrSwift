//
//  SDLSwiftBinding.h
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#ifndef __SwiftSDL__SDLSwiftBinding__
#define __SwiftSDL__SDLSwiftBinding__

#include "SDL.h"
#include "SDL_main.h"

// This is a hack. These are usually provided by the C standard math library.
// But the Swift/C library is not fully ready yet on non-Apple platforms.
// Additionally, Visual Studio has been a pain about these historically.
// Redefine them here with a unique identifer to avoid clashes.
#define SDL_M_PI    3.14159265358979323846264338327950288
#define SDL_M_PI_2    1.57079632679489661923132169163975144
#define SDL_M_PI_4    0.785398163397448309615660845819875721

/*
SDL_EventType SDL_EXT_EventGetType(SDL_Event the_event);
SDL_EventType SDL_EXT_EventGetTypeFromPtr(SDL_Event* the_event);
*/
SDL_PixelFormat* SDL_EXT_GetPixelFormat(SDL_Surface* the_surface);

#undef SDL_GameControllerAddMappingsFromFile
int SDL_GameControllerAddMappingsFromFile(const char* file);

/*
#undef SDL_RWclose
inline int SDL_RWclose(SDL_RWops* ctx)
{
	return ctx->close(ctx);
}
*/
#undef SDL_RWclose
int SDL_RWclose(SDL_RWops* ctx);


#undef KMOD_CTRL
#define KMOD_CTRL   0x00C0
#undef KMOD_SHIFT
#define KMOD_SHIFT  0x0003
#undef KMOD_ALT
#define KMOD_ALT    0x0300
#undef KMOD_GUI
#define KMOD_GUI    0x0C00


#endif /* defined(__SwiftSDL__SDLSwiftBinding__) */
