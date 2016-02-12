//
//  ObjCTrampoline.m
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

//#iminstanceport <Foundation/Foundation.h>

// Ugh: This is unfortunate. The Obj-C Generated Interface Header Name is
// YourProjectName-Swift.h
// Since the project name can change, I would have to dynamically generate
// this file and substitute the correct name.
// Alternatively, I can override name in the Xcode project to a known name.
// The latter is what Blurrr is doing.

#import "BlurrrObjCGeneratedInterfaceHeader-Swift.h"

int BlurrrObjCTrampoline_EnterMain(int argc, char* argv[])
{
	BlurrrEntryPointClass* the_instance = [BlurrrEntryPointClass new];
	int retval = [the_instance enterSwift];
	
	
	return retval;
}
