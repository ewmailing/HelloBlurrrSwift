
/*
// Recommend trying to avoid Foundation because it is unfinished and big 
// (and may not be included yet in your Swift distribution).
// SDL and BlurrrCore provide most of the C library so it can be avoided.
// Modify your CMakeBlurrrDefaultOptionsOverride.cmake to include these 
// libraries or not. That file controls whether the libraries will be 
// copied into your app bundle.

#if os(Linux)
    import Glibc
#else
    import Darwin
#endif

import Foundation

*/




let PINBUTTON: UInt32 = 25 // Pi2: 22
var g_pigpioDeviceId: Int32 = -1;




let HAPPY_FACE_SIZE : CInt = 32
struct HappyFaceData
{
	var x : Float32 /* position of happyface */
	var y : Float32 /* position of happyface */
	var xvel : Float32 /* velocity of happyface */
	var yvel : Float32 /* velocity of happyface */

	var size : Int32

	var angle : Double /* orientation of happyface */
	var rotationSpeed : Double /* velocity of rotation */
	
	init()
	{
		x = 0.0;
		y = 0.0;
		xvel = 0.0;
		yvel = 0.0;
		size = HAPPY_FACE_SIZE;
		angle = 0;
		rotationSpeed = 0;

	}
}

var s_facesArray = [HappyFaceData]()

var g_appDone = false;
var s_happyFaceTexture : COpaquePointer = nil;
var s_mainRenderer : COpaquePointer = nil;
var s_lastFrameTime : Uint32 = 0
var g_gameClock : COpaquePointer = nil

let SCREEN_WIDTH : CInt = 1280
let SCREEN_HEIGHT : CInt = 720
//let SCREEN_WIDTH : CInt = 640
//let SCREEN_HEIGHT : CInt = 480
let NUM_HAPPY_FACES = 50


func LoadTexture(theRenderer: COpaquePointer)
{
	let base_path = SDL_GetBasePath();
	if(nil == base_path)
	{
		print("SDL_GetBasePath() returned NULL");
		return;
	}
	//let resource_file_path = String.fromCString(base_path)! + "icon.bmp";
	//let resource_file_path = String.fromCString(base_path)! + "swift_logo.bmp";
	let resource_file_path = String.fromCString(base_path)! + "swift_logo.png";
	SDL_free(base_path);
	
	//	var bmp_surface = SDL_LoadBMP(resource_file_path);
	//let bmp_surface = SDL_LoadBMP_RW(SDL_RWFromFile(resource_file_path, "rb"), 1);
	let bmp_surface = IMG_Load_RW(SDL_RWFromFile(resource_file_path, "rb"), 1);
	if(bmp_surface == nil)
	{
		print("could not load bmp");
		return;
	}
	
	/* set white to transparent on the happyface */
/*
	let pixel_format = SDL_EXT_GetPixelFormat(bmp_surface)
	SDL_SetColorKey(bmp_surface, 1,
		SDL_MapRGB(pixel_format, 255, 255, 255));
*/
	/* convert RGBA surface to texture */
	s_happyFaceTexture = SDL_CreateTextureFromSurface(theRenderer, bmp_surface);
	if(nil == s_happyFaceTexture)
	{
		print("could not create texture");
		return;
	}
	SDL_SetTextureBlendMode(s_happyFaceTexture, SDL_BLENDMODE_BLEND);
	
	/* free up allocated memory */
	SDL_FreeSurface(bmp_surface);
	
	
}

func RandomInt(min:Int32, max:Int32) -> Int32
{
	return BlurrrRandom_GetSint32InRange(min, max);
}

func RandomFloat(min:Float32, max:Float32) -> Float32
{
	return BlurrrRandom_GetFloatInRange(min, max);
}

func InitializeHappyFaces()
{
	s_facesArray.reserveCapacity(NUM_HAPPY_FACES)
	for(var i = 0; i < NUM_HAPPY_FACES; i++)
	{
		var happy_face : HappyFaceData = HappyFaceData();
		s_facesArray.append(happy_face)
	}
	
	for(var i = 0; i < NUM_HAPPY_FACES; i++)
	{
		s_facesArray[i].size = RandomInt(20, max: 120);

		s_facesArray[i].x = RandomFloat(0.0, max: Float32(SCREEN_WIDTH - s_facesArray[i].size));
		s_facesArray[i].y = RandomFloat(0.0, max: Float32(SCREEN_WIDTH - s_facesArray[i].size));
		s_facesArray[i].xvel = RandomFloat(-0.1, max: 0.1);
		s_facesArray[i].yvel = RandomFloat(-0.1, max: 0.1);

		s_facesArray[i].size = RandomInt(20, max: 80);

		s_facesArray[i].angle = Double(RandomFloat(-360.0, max: 360.0));
		s_facesArray[i].rotationSpeed = Double(RandomFloat(-0.3, max: 0.3));
	}
}


func main_loop()
{
	let start_frame : Uint32 = BlurrrTicker_UpdateTime(g_gameClock);
	let current_time = start_frame;
	let delta_time = current_time - s_lastFrameTime;
//	println("start:\(start_frame), current:\(current_time), delta:\(delta_time)")
	var the_result : CInt = 0;
	repeat
	{
		var the_event : SDL_Event = SDL_Event();
		
		the_result = SDL_PollEvent(&the_event)
		if(the_result > 0)
		{
			let event_type: SDL_EventType = SDL_EventType(the_event.type);
			
			switch(event_type.rawValue)
			{
				case SDL_MOUSEBUTTONDOWN.rawValue:
					print("SDL_MOUSEBUTTONDOWN");
				
				case SDL_QUIT.rawValue:
					g_appDone = true;
				case SDL_APP_TERMINATING.rawValue:
					g_appDone = true;
				case SDL_KEYDOWN.rawValue:
                                if(SDL_Keycode(SDLK_AC_BACK) == the_event.key.keysym.sym)
                                {
                                        g_appDone = true;
                                }
                                else if(SDL_Keycode(SDLK_ESCAPE) == the_event.key.keysym.sym)
                                {
                                        g_appDone = true;
                                }

				default:
					break;
			}
		}
	
		
	} while(the_result > 0)
	



#if BLURRR_PLATFORM_RASPBERRY_PI
	let current_value = gpio_read(g_pigpioDeviceId, PINBUTTON);
	if(current_value >= 1)
	{
		BlurrrTicker_SetSpeed(g_gameClock, 10.0); // 10x speed
	}
	else
	{
		BlurrrTicker_SetSpeed(g_gameClock, 1.0); // normal speed
	}
#endif



	
	Render(s_mainRenderer, delta_time: delta_time)
	
	s_lastFrameTime = current_time;

	// Try to not suck up all the CPU
	SDL_Delay(10);
}



func Render(the_renderer:COpaquePointer, delta_time:Uint32)
{
	let dt = delta_time;
	var dst_rect : SDL_Rect = SDL_Rect();
	
	/* setup boundaries for happyface bouncing */
//	let maxx = Float32(SCREEN_WIDTH - HAPPY_FACE_SIZE);
//	let maxy = Float32(SCREEN_HEIGHT - HAPPY_FACE_SIZE);
	let minx : Float32 = 0.0;
	let miny : Float32 = 0.0;
	
	/* setup rects for drawing */
	dst_rect.w = HAPPY_FACE_SIZE;
	dst_rect.h = HAPPY_FACE_SIZE;
	
	/* fill background in with black */
	SDL_SetRenderDrawColor(the_renderer, 0, 0, 0, 255);
	SDL_RenderClear(the_renderer);
	
	/*
	loop through all the happy faces:
	- update position
	- update velocity (if boundary is hit)
	- draw
	*/
	for(var i = 0; i < NUM_HAPPY_FACES; i++)
	{
		var happy_face : HappyFaceData = s_facesArray[i]
	let maxx = Float32(SCREEN_WIDTH - happy_face.size);
	let maxy = Float32(SCREEN_HEIGHT - happy_face.size);
		
		happy_face.x = (happy_face.xvel * Float32(dt)) + happy_face.x;
		happy_face.y = (happy_face.yvel * Float32(dt)) + happy_face.y;
		if(happy_face.x > maxx)
		{
			happy_face.x = maxx;
			happy_face.xvel = -happy_face.xvel;
		}
		else if(happy_face.y > maxy)
		{
			happy_face.y = maxy;
			happy_face.yvel = -happy_face.yvel;
		}
		if (happy_face.x < minx)
		{
			happy_face.x = minx;
			happy_face.xvel = -happy_face.xvel;
		}
		else if (happy_face.y < miny)
		{
			happy_face.y = miny;
			happy_face.yvel = -happy_face.yvel;
		}


		happy_face.angle = (happy_face.rotationSpeed * Double(dt)) + happy_face.angle;



		s_facesArray[i] = happy_face
		
		dst_rect.x = Int32(happy_face.x + 0.5);
		dst_rect.y = Int32(happy_face.y + 0.5);

		dst_rect.w = happy_face.size;
		dst_rect.h = happy_face.size;

		//SDL_RenderCopy(the_renderer, s_happyFaceTexture, nil, &dst_rect);
		SDL_RenderCopyEx(the_renderer, s_happyFaceTexture, nil, &dst_rect, happy_face.angle, nil, SDL_RendererFlip(0));
	}
	
	
	/* update screen */
	SDL_RenderPresent(the_renderer);
	
}


let TemplateHelper_HandleAppEvents : @convention(c) (UnsafeMutablePointer<Void>, UnsafeMutablePointer<SDL_Event>) -> CInt =
{
	(user_data, the_event) -> CInt in
	
	//	var event_type = SDL_EXT_EventGetTypeFromPtr(the_event);
	var event_type:SDL_EventType = SDL_EventType(the_event.memory.type);
	
	switch(event_type)
	{
	case SDL_APP_TERMINATING:
		/* Terminate the app.
		Shut everything down before returning from this function.
		*/
		
		return 0;
	case SDL_APP_LOWMEMORY:
		/* You will get this when your app is paused and iOS wants more memory.
		Release as much memory as possible.
		*/
		return 0;
	case SDL_APP_WILLENTERBACKGROUND:
		/* Prepare your app to go into the background.  Stop loops, etc.
		This gets called when the user hits the home button, or gets a call.
		*/
		
		return 0;
	case SDL_APP_DIDENTERBACKGROUND:
		/* This will get called if the user accepted whatever sent your app to the background.
		If the user got a phone call and canceled it, you'll instead get an    SDL_APP_DIDENTERFOREGROUND event and restart your loops.
		When you get this, you have 5 seconds to save all your state or the app will be terminated.
		Your app is NOT active at this point.
		*/
		return 0;
	case SDL_APP_WILLENTERFOREGROUND:
		/* This call happens when your app is coming back to the foreground.
		Restore all your state here.
		*/
		return 0;
	case SDL_APP_DIDENTERFOREGROUND:
		/* Restart your loops here.
		Your app is interactive and getting CPU again.
		*/
		return 0;
	default:
		/* No special processing, add it to the event queue */
		return 1;
	}
}

// This function is the official starting point of the Swift program.
func BlurrrMain() -> Int32
{
	if(SDL_Init(Uint32(SDL_INIT_VIDEO)) < 0)
	{
		print("Could not initialize SDL");
	}
	if(IMG_Init(Int32(IMG_INIT_JPG.rawValue | IMG_INIT_PNG.rawValue | IMG_INIT_TIF.rawValue)) < 0)
	{
		print("Could not initialize SDL_image");
	}
	if(TTF_Init() < 0)
	{
		print("Could not initialize SDL_ttf");
	}
	/*
	if(ALmixer_Init(0, 0, 0) == ALboolean(AL_FALSE))
	{
		print("Could not initialize ALmixer");
	}
	*/
	
	SDL_SetEventFilter(TemplateHelper_HandleAppEvents, nil);

	let the_window = SDL_CreateWindow("Blurrr Swift",
		CInt(0x1FFF0000), CInt(0x1FFF0000),
		CInt(SCREEN_WIDTH), CInt(SCREEN_HEIGHT), 
		Uint32(0)
		| SDL_WINDOW_FULLSCREEN_DESKTOP.rawValue
	);
	
	
	let the_renderer = SDL_CreateRenderer(the_window, -1, Uint32(0x00000004));
	s_mainRenderer = the_renderer;

	SDL_RenderSetLogicalSize(the_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	
	LoadTexture(the_renderer);
	
	InitializeHappyFaces();
	
	g_gameClock = BlurrrTicker_Create();
	BlurrrTicker_Start(g_gameClock);




#if BLURRR_PLATFORM_RASPBERRY_PI
	g_pigpioDeviceId = pigpio_start(nil, nil);
	
	if(g_pigpioDeviceId < 0)
	{
		print("pigpio initialialization failed. Make sure you started the pigpiod daemon before running this program.");
	}
	set_mode(g_pigpioDeviceId, PINBUTTON, UInt32(PI_INPUT));
#endif


	
	while(!g_appDone)
	{
		main_loop();
	}


//	ALmixer_Quit();
	SDL_Quit();
	
	return 0;
}



