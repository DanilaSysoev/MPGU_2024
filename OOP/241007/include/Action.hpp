#pragma once

class Action {
private:
    int additionalArg;

public:
    Action(int additionalArg);

    void operator()() const;
    int operator()(int coefficient) const;
};

