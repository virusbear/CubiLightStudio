#pragma once

#include "Port.h"

namespace CubiLight
{
    class Link {
    private:
        Port& mStart;
        Port& mEnd;
    public:
            Link(Port& start, Port& end): mStart(start), mEnd(end) { mEnd.LinkFrom(mStart); };
            ~Link() { mEnd.Unlink(); };
            Port& GetStart() const { return mStart; };
            Port& GetEnd() const { return mEnd; };
    };
}
