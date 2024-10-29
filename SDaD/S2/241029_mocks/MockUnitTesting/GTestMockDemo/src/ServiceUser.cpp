#include <iostream>
#include "Service.hpp"
#include "ServiceUser.hpp"

ServiceUser::ServiceUser(Service* service)
    : _service(service)
{}

void ServiceUser::veryStrongAlgorithmUsesService() const {
    std::cout << "Some actions before using service\n";
    _service->provideService();
    std::cout << "Some actions after using service\n";
    _service->provideParametrizedService(10);
}

ServiceUser::~ServiceUser() {
    if (_service)
        delete _service;
}
