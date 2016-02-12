//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

// SDL for iOS does some really funky stuff that requires us to start in C.
// There is macro magic done by including SDL.h and defining the main function.
// There is no public way to directly go from C->Swift, 
// but fortunately, Objective-C can get us to C.
// And iOS includes Obj-C support (unlike the Linux ports).

#include "SDL.h"

int BlurrrObjCTrampoline_EnterMain(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	int retval = BlurrrObjCTrampoline_EnterMain(argc, argv);
	
	return retval;
	
}

