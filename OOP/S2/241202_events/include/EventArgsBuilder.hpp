#pragma once

namespace EventSystem {
    class EventArgs;

    class EventArgsBuilder {
    public:
        virtual EventArgs* build() = 0;

        virtual ~EventArgsBuilder() = default;
    };
}