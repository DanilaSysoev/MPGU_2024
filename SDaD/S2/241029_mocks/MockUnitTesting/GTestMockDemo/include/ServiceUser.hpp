#pragma once

class Service;

class ServiceUser {
public:
    ServiceUser(Service* service);

    void veryStrongAlgorithmUsesService() const;

    ~ServiceUser();

private:
    Service* _service;
};
