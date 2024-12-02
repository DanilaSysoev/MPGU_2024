#pragma once

namespace EventSystem {
    class EventHandler;
    class EventArgsBuilder;

    class Event {
    public:
        Event(EventArgsBuilder* builder);

        void addHandler(EventHandler* handler);
        void removeHandler(EventHandler* handler);

        void notify(EventArgsBuilder* builder);

    private:
        // add some fields
    };
}