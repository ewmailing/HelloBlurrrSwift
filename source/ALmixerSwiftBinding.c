//
//  ALmixerSwiftBinding.c
//  SwiftSDL
//
//  Created by Eric Wing on 6/10/15.
//  Copyright (c) 2015 PlayControl Software LLC. All rights reserved.
//

#include "ALmixerSwiftBinding.h"

//#include "ALmixer.h"

ALmixer_Data* ALmixer_LoadStream_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RW(rw_ops,file_ext, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

ALmixer_Data* ALmixer_LoadAll_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALuint access_data)
{
	return ALmixer_LoadSample_RW(rw_ops, file_ext, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}


ALmixer_Data* ALmixer_LoadStream(const char* file_name, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample(file_name, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

ALmixer_Data* ALmixer_LoadAll(const char* file_name, ALuint access_data)
{
	return ALmixer_LoadSample(file_name, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}




ALmixer_Data* ALmixer_LoadStream_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RAW_RW(rw_ops, file_ext, desired_format, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

ALmixer_Data* ALmixer_LoadAll_RAW_RW(struct ALmixer_RWops* rw_ops, const char* file_ext, ALmixer_AudioInfo* desired_format, ALuint access_data)
{
	return ALmixer_LoadSample_RAW_RW(rw_ops, file_ext, desired_format, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}



ALmixer_Data* ALmixer_LoadStream_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint buffer_size, ALuint max_queue_buffers, ALuint num_startup_buffers, ALuint suggested_number_of_buffers_to_queue_per_update_pass, ALuint access_data)
{
	return ALmixer_LoadSample_RAW(file_name, desired_format, buffer_size, AL_FALSE, max_queue_buffers, num_startup_buffers, suggested_number_of_buffers_to_queue_per_update_pass, access_data);
}

ALmixer_Data* ALmixer_LoadAll_RAW(const char* file_name, ALmixer_AudioInfo* desired_format, ALuint access_data)
{
	return ALmixer_LoadSample_RAW(file_name, desired_format, ALMIXER_DEFAULT_PREDECODED_BUFFERSIZE, AL_TRUE, 0, 0, 0, access_data);
}






ALint ALmixer_PlayChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops)
{
	return ALmixer_PlayChannelTimed(which_channel, almixer_data, number_of_loops, -1);
}

ALuint ALmixer_PlaySource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops)
{
	return ALmixer_PlaySourceTimed(al_source, almixer_data, number_of_loops, -1);
	
}

ALint ALmixer_FadeInChannel(ALint which_channel, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks)
{
	return ALmixer_FadeInChannelTimed(which_channel, almixer_data, number_of_loops, fade_ticks, -1);
}


ALuint ALmixer_FadeInSource(ALuint al_source, ALmixer_Data* almixer_data, ALint number_of_loops, ALuint fade_ticks)
{
	return ALmixer_FadeInSourceTimed(al_source, almixer_data, number_of_loops, fade_ticks, -1);
}


ALuint ALmixer_CountTotalChannels(void)
{
	return ALmixer_AllocateChannels(-1);
}


ALuint ALmixer_CountReservedChannels(void)
{
	return ALmixer_ReserveChannels(-1);
}



