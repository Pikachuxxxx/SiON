/*
 * Copyright (c) 2021 Phani Srikar (Pikachuxxx) All rights reserved.
 * Distributed under Distributed under BSD-style License. (see LICENSE.txt)
 */

#ifndef SION_UTIL_DISPATCHER_H
#define SION_UTIL_DISPATCHER_H

#include "Event.h"

 /// Forward declaration the (event + handle) connection, the dispatcher does not store any connections
class Connection;


namespace SiON { namespace utils { namespace events {

    /// The Dispatcher manages multiple observers that are interested in a certain event
    ///
    /// The dispatcher is the central class for event management. It offers clients
    /// the opportunity to use post() to submit a given event.Said event is then
    /// passed on to all observers that are listening to it.The dispatcher also
    /// handles new observers via subscribe() and permits the removal of observers via disconnect()
    class Dispatcher
    {
        /// Describes the slot an observer has to implement to be able to process events that are posted
        typedef std::function<void(const Event&)> SlotType;

        /// Subscribes a given slot to a certain event descriptor.The slot will be
        /// called whenever an event of the specified type has been posted.The order
        /// in which observers subscribe to certain events matters.
        /// 
        /// @param descriptor The Event to listen for
        /// @param slot Slot (aka observer function) to call in case such an event occurs
        /// 
        /// @returns Connection handle to identify the observing slot
        Connection Subscribe(const Event::DescriptorType& descriptor, SlotType&& slot);

        /// Unsubscribes an observer from receiving further events 
        ///
        /// The observer is identified by a connection object
        /// 
        /// @param connection The connection handle identifying the observer
        void Unsubscribe(const Connection& connection);

        /// Posts an event to all connected observers
        ///
        /// Any observer can get that event and process as they wish, this method only passes the event 
        /// to all the connected observers that has subscribed to this dispatcher
        /// 
        /// @param event An event of any configuration
        void Post(const Event& event) const;
    };

} } }

#endif // SION_UTIL_DISPATCHER_H