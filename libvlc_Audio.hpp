/*****************************************************************************
 * libvlc_Audio.hpp: Audio API
 *****************************************************************************
 * Copyright © 2014 the VideoLAN team
 *
 * Authors: Alexey Sokolov <alexey@alexeysokolov.co.cc>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/* This file is autogenerated */



#ifndef LIBVLC_CXX_AUDIO_H
#define LIBVLC_CXX_AUDIO_H

#include <libvlc_common.hpp>
#include "libvlcpp.hpp"

namespace VLC 
{


class Audio : public Internal<
{
public:
    /**
     * Copy libvlc_media_player_t from another to new Audio object.
     * \param another existing Audio
     */
    Audio(const Audio& another);

    /**
     * Copy libvlc_media_player_t from another Audio
     * to this Audio
     * \param another existing Audio
     */
    const Audio& operator=(const Audio& another);

    /**
     * Check if 2 Audio objects contain the same libvlc_media_player_t.
     * \param another another Audio
     * \return true if they contain the same libvlc_media_player_t
     */
    bool operator==(const Audio& another) const;

    ~Audio();

    /**
     * Set callbacks and private data for decoded audio. Use
     * Audio::setFormat() or Audio::setFormatCallbacks() to configure the
     * decoded audio format.
     *
     * \param play  callback to play audio samples (must not be NULL)
     *
     * \param pause  callback to pause playback (or NULL to ignore)
     *
     * \param resume  callback to resume playback (or NULL to ignore)
     *
     * \param flush  callback to flush audio buffers (or NULL to ignore)
     *
     * \param drain  callback to drain audio buffers (or NULL to ignore)
     *
     * \param opaque  private pointer for the audio callbacks (as first
     * parameter)
     *
     * \version LibVLC 2.0.0 or later
     */
    void setCallbacks(libvlc_audio_play_cb play, libvlc_audio_pause_cb pause, libvlc_audio_resume_cb resume, libvlc_audio_flush_cb flush, libvlc_audio_drain_cb drain, void * opaque);

    /**
     * Set callbacks and private data for decoded audio. Use
     * Audio::setFormat() or Audio::setFormatCallbacks() to configure the
     * decoded audio format.
     *
     * \param set_volume  callback to apply audio volume, or NULL to apply
     * volume in software
     *
     * \version LibVLC 2.0.0 or later
     */
    void setVolumeCallback(libvlc_audio_set_volume_cb set_volume);

    /**
     * Set decoded audio format. This only works in combination with
     * Audio::setCallbacks() .
     *
     * \param setup  callback to select the audio format (cannot be NULL)
     *
     * \param cleanup  callback to release any allocated resources (or NULL)
     *
     * \version LibVLC 2.0.0 or later
     */
    void setFormatCallbacks(libvlc_audio_setup_cb setup, libvlc_audio_cleanup_cb cleanup);

    /**
     * Set decoded audio format. This only works in combination with
     * Audio::setCallbacks() , and is mutually exclusive with
     * Audio::setFormatCallbacks() .
     *
     * \param format  a four-characters string identifying the sample format
     * (e.g. "S16N" or "FL32")
     *
     * \param rate  sample rate (expressed in Hz)
     *
     * \param channels  channels count
     *
     * \version LibVLC 2.0.0 or later
     */
    void setFormat(const std::string& format, unsigned rate, unsigned channels);

    /**
     * Selects an audio output module.
     *
     * \note Any change will take be effect only after playback is stopped
     * and restarted. Audio output cannot be changed while playing.
     *
     * \param psz_name  name of audio output, use psz_name of
     *
     * \see AudioOutputDescription
     *
     * \return 0 if function succeded, -1 on error
     */
    int outputSet(const std::string& psz_name);

    /**
     * Gets a list of potential audio output devices,
     *
     * \see Audio::outputDeviceSet() .
     *
     * \note Not all audio outputs support enumerating devices. The audio
     * output may be functional even if the list is empty (NULL).
     *
     * \note The list may not be exhaustive.
     *
     * \warning Some audio output devices in the list might not actually work
     * in some circumstances. By default, it is recommended to not specify
     * any explicit audio device.
     *
     * \return A NULL-terminated linked list of potential audio output
     * devices. It must be freed it with
     * libvlc_audio_output_device_list_release()
     *
     * \version LibVLC 2.2.0 or later.
     */
    libvlc_audio_output_device_t * outputDeviceEnum();

    /**
     * Configures an explicit audio output device.
     *
     * If the module paramater is NULL, audio output will be moved to the
     * device specified by the device identifier string immediately. This is
     * the recommended usage.
     *
     * A list of adequate potential device strings can be obtained with
     * Audio::outputDeviceEnum() .
     *
     * However passing NULL is supported in LibVLC version 2.2.0 and later
     * only; in earlier versions, this function would have no effects when
     * the module parameter was NULL.
     *
     * If the module parameter is not NULL, the device parameter of the
     * corresponding audio output, if it exists, will be set to the specified
     * string. Note that some audio output modules do not have such a
     * parameter (notably MMDevice and PulseAudio).
     *
     * A list of adequate potential device strings can be obtained with
     * Instance::audioOutputDeviceList() .
     *
     * \note This function does not select the specified audio output plugin.
     * Audio::outputSet() is used for that purpose.
     *
     * \warning The syntax for the device parameter depends on the audio
     * output. Some audio output modules require further parameters (e.g. a
     * channels map in the case of ALSA).
     *
     * \param module  If NULL, current audio output module. if non-NULL, name
     * of audio output module (
     *
     * \see AudioOutputDescription )
     *
     * \param device_id  device identifier string
     *
     * \return Nothing. Errors are ignored (this is a design bug).
     */
    void outputDeviceSet(const std::string& module, const std::string& device_id);

    /**
     * Toggle mute status.
     *
     * \warning Toggling mute atomically is not always possible: On some
     * platforms, other processes can mute the VLC audio playback stream
     * asynchronously. Thus, there is a small race condition where toggling
     * will not work. See also the limitations of Audio::setMute() .
     */
    void toggleMute();

    /**
     * Get current mute status.
     *
     * \return the mute status (boolean) if defined, -1 if
     * undefined/unapplicable
     */
    int mute();

    /**
     * Set mute status.
     *
     * \param status  If status is true then mute, otherwise unmute
     *
     * \warning This function does not always work. If there are no active
     * audio playback stream, the mute status might not be available. If
     * digital pass-through (S/PDIF, HDMI...) is in use, muting may be
     * unapplicable. Also some audio output plugins do not support muting at
     * all.
     *
     * \note To force silent playback, disable all audio tracks. This is more
     * efficient and reliable than mute.
     */
    void setMute(int status);

    /**
     * Get current software audio volume.
     *
     * \return the software volume in percents (0 = mute, 100 = nominal /
     * 0dB)
     */
    int volume();

    /**
     * Set current software audio volume.
     *
     * \param i_volume  the volume in percents (0 = mute, 100 = 0dB)
     *
     * \return 0 if the volume was set, -1 if it was out of range
     */
    int setVolume(int i_volume);

    /**
     * Get number of available audio tracks.
     *
     * \return the number of available audio tracks (int), or -1 if
     * unavailable
     */
    int trackCount();

    /**
     * Get the description of available audio tracks.
     *
     * \return list with description of available audio tracks, or NULL
     */
    std::list<TrackDescription> trackDescription();

    /**
     * Get current audio track.
     *
     * \return the audio track ID or -1 if no active input.
     */
    int track();

    /**
     * Set current audio track.
     *
     * \param i_track  the track ID (i_id field from track description)
     *
     * \return 0 on success, -1 on error
     */
    int setTrack(int i_track);

    /**
     * Get current audio channel.
     *
     * \return the audio channel
     *
     * \see libvlc_audio_output_channel_t
     */
    int channel();

    /**
     * Set current audio channel.
     *
     * \param channel  the audio channel,
     *
     * \see libvlc_audio_output_channel_t
     *
     * \return 0 on success, -1 on error
     */
    int setChannel(int channel);

    /**
     * Get current audio delay.
     *
     * \return the audio delay (microseconds)
     *
     * \version LibVLC 1.1.1 or later
     */
    int64_t delay();

    /**
     * Set current audio delay. The audio delay will be reset to zero each
     * time the media changes.
     *
     * \param i_delay  the audio delay (microseconds)
     *
     * \return 0 on success, -1 on error
     *
     * \version LibVLC 1.1.1 or later
     */
    int setDelay(int64_t i_delay);

private:
    /**
     */
    void retain();

    /**
     */
    void release();


    libvlc_media_player_t* m_obj;
};

} // namespace VLC

#endif

