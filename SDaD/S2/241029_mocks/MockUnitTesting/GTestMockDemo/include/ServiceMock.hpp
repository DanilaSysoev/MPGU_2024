#pragma once
#include <map>
#include "Service.hpp"

class ServiceMock : public Service {
public:
    void provideService() override {
        ++callsCnt;
    }

    void provideParametrizedService(int parameter) override {
        parametrizedCallsCnt[parameter] += 1;
    }

    int getCallsCnt() const {
        return callsCnt;
    }

    int getCallsCnt(int parameter) const {
        if(parametrizedCallsCnt.count(parameter) > 0)
            return parametrizedCallsCnt.at(parameter);
        return 0;
    }

private:
    int callsCnt = 0;

    std::map<int, int> parametrizedCallsCnt;
};
