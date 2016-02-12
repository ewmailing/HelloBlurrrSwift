//
//  SDLSwiftBinding.h
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#ifndef __SwiftSDL__ALmixerSwiftBinding__
#define __SwiftSDL__ALmixerSwiftBinding__

#include "ALmixer.h"

/*
#undef ALmixer_LoadStream_RW
inline ALmixer_Data* ALmixer_LoadStream_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RW(rw_ops,file_ext, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

#undef ALmixer_LoadAll_RW
inline ALmixer_Data* ALmixer_LoadAll_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint access_data)
{
	return ALmixer_LoadSample_RW(rw_ops, file_ext, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}


#undef ALmixer_LoadStream
inline ALmixer_Data* ALmixer_LoadStream(const char* file_name, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample(file_name, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

#undef ALmixer_LoadAll
inline ALmixer_Data* ALmixer_LoadAll(const char* file_name, ALuint access_data)
{
	return ALmixer_LoadSample(file_name, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}




#undef ALmixer_LoadStream_RAW_RW
inline ALmixer_Data* ALmixer_LoadStream_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RAW_RW(rw_ops, file_ext, desired_format, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

#undef ALmixer_LoadAll_RAW_RW
inline ALmixer_Data* ALmixer_LoadAll_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint access_data)
{
	return ALmixer_LoadSample_RAW_RW(rw_ops, file_ext, desired_format, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}



#undef ALmixer_LoadStream_RAW
inline ALmixer_Data* ALmixer_LoadStream_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RAW(file_name, desired_format, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

#undef ALmixer_LoadAll_RAW
inline ALmixer_Data* ALmixer_LoadAll_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint access_data)
{
	return ALmixer_LoadSample_RAW(file_name, desired_format, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}






#undef ALmixer_PlayChannel
inline ALint ALmixer_PlayChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops)
{
	return ALmixer_PlayChannelTimed(which_channel, almixer_data, number_of_loops, -1);
}

#undef ALmixer_PlaySource
inline ALuint ALmixer_PlaySource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops)
{
	return ALmixer_PlaySourceTimed(al_source, almixer_data, number_of_loops, -1);
	
}

#undef ALmixer_FadeInChannel
inline ALint ALmixer_FadeInChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks)
{
	return ALmixer_FadeInChannelTimed(which_channel, almixer_data, number_of_loops, fade_ticks, -1);
}


#undef ALmixer_FadeInSource
inline ALuint ALmixer_FadeInSource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks)
{
	return ALmixer_FadeInSourceTimed(al_source, almixer_data, number_of_loops, fade_ticks, -1);
}


#undef ALmixer_CountTotalChannels
inline ALuint ALmixer_CountTotalChannels(void)
{
	return ALmixer_AllocateChannels(-1);
}


#undef ALmixer_CountReservedChannels
inline ALuint ALmixer_CountReservedChannels(void)
{
	return ALmixer_ReserveChannels(-1);
}
*/

#undef ALmixer_LoadStream_RW
ALmixer_Data* ALmixer_LoadStream_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data);


#undef ALmixer_LoadAll_RW
ALmixer_Data* ALmixer_LoadAll_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint access_data);


#undef ALmixer_LoadStream
ALmixer_Data* ALmixer_LoadStream(const char* file_name, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data);

#undef ALmixer_LoadAll
ALmixer_Data* ALmixer_LoadAll(const char* file_name, ALuint access_data);




#undef ALmixer_LoadStream_RAW_RW
ALmixer_Data* ALmixer_LoadStream_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data);

#undef ALmixer_LoadAll_RAW_RW
ALmixer_Data* ALmixer_LoadAll_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint access_data);



#undef ALmixer_LoadStream_RAW
ALmixer_Data* ALmixer_LoadStream_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data);

#undef ALmixer_LoadAll_RAW
ALmixer_Data* ALmixer_LoadAll_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint access_data);






#undef ALmixer_PlayChannel
ALint ALmixer_PlayChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops);

#undef ALmixer_PlaySource
ALuint ALmixer_PlaySource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops);

#undef ALmixer_FadeInChannel
ALint ALmixer_FadeInChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks);


#undef ALmixer_FadeInSource
ALuint ALmixer_FadeInSource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks);


#undef ALmixer_CountTotalChannels
ALuint ALmixer_CountTotalChannels(void);


#undef ALmixer_CountReservedChannels
ALuint ALmixer_CountReservedChannels(void);





#endif /* defined(__SwiftSDL__ALmixerSwiftBinding__) */
