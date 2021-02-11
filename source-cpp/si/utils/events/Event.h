/*
 * Copyright (c) 2021 Phani Srikar (Pikachuxxx) All rights reserved.
 * Distributed under Distributed under BSD-style License. (see LICENSE.txt)
 */

#ifndef SION_UTIL_EVENT_H
#define SION_UTIL_EVENT_H

namespace SiON { namespace utils { namespace events {

    /// The general purpose Event System that can be used for managing any kind of events
    class Event
    {
    public:
        /// The destructor is kept virtual because Event is a polymorphic base class and how it destructs the event is unknown
        virtual ~Event() {}

        /// Each event uses a const char* to create a unique identifier (i.e event type is it's UUID)
        typedef const char* DescriptorType;

        /// Every derived Event needs to implement this function to describe itself
        ///
        /// @returns The descriptor type of this Event
        virtual DescriptorType type() const = 0;
    };

} } }

#endif // SION_UTIL_EVENT_H
