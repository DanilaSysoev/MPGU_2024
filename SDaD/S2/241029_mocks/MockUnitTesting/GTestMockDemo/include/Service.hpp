#pragma once

class Service {
public:
    void virtual provideService() = 0;
    void virtual provideParametrizedService(int parameter) = 0;

    virtual ~Service() = default;
};
