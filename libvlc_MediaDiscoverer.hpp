/*****************************************************************************
 * libvlc_MediaDiscoverer.hpp: MediaDiscoverer API
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



#ifndef LIBVLC_CXX_MEDIADISCOVERER_H
#define LIBVLC_CXX_MEDIADISCOVERER_H

#include <libvlc_common.hpp>

namespace VLC 
{


class MediaDiscoverer 
{
public:
    /**
     * Move underlying libvlc_media_discoverer_t object from
     * MediaDiscoverer another to new MediaDiscoverer.
     * \param another existing MediaDiscoverer
     */
    MediaDiscoverer(MediaDiscoverer&& another);

    /**
     * Move underlying libvlc_media_discoverer_t object from
     * MediaDiscoverer another to this MediaDiscoverer.
     * \param another existing MediaDiscoverer
     * \return this
     */
    const MediaDiscoverer& operator=(MediaDiscoverer&& another);

    ~MediaDiscoverer();

    // libvlc_media_discoverer_new_from_name
    /**
     * Discover media service by name.
     *
     * \param p_inst  libvlc instance
     *
     * \param psz_name  service name
     */
    MediaDiscoverer(Instance & p_inst, const std::string& psz_name);

    /**
     * Get media service discover object its localized name.
     *
     * \return localized name
     */
    std::string localizedName();

    /**
     * Get event manager from media service discover object.
     *
     * \return event manager object.
     */
    libvlc_event_manager_t * eventManager();

    /**
     * Query if media service discover object is running.
     *
     * \return true if running, false if not
     */
    bool isRunning();

private:
    /**
     * Release media discover object. If the reference count reaches 0, then
     * the object will be released.
     */
    void release();


    bool m_own;
    MediaDiscoverer& operator=(const MediaDiscoverer& another);
    MediaDiscoverer(const MediaDiscoverer& another);
    bool operator==(const MediaDiscoverer& another);

    libvlc_media_discoverer_t* m_obj;
};

} // namespace VLC

#endif

