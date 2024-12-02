#pragma once

namespace EventSystem {
    class EventArgs;

    class EventHandler {
    public:
        virtual void operator()(const EventArgs* args) = 0;
        virtual ~EventHandler() = default;
    };
}