#include <iostream>
#include "Action.hpp"

Action::Action(int additionalArg)
    : additionalArg(additionalArg)
{}

void Action::operator()() const {
    std::cout << "Action functional object with additional argument: "
              << additionalArg
              << std::endl;
}

int Action::operator()(int coefficient) const {
    return coefficient * additionalArg;
}
