#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ServiceMock.hpp"
#include "ServiceUser.hpp"

class ServiceMockGMock : public Service {
public:
    MOCK_METHOD0(provideService, void());
    MOCK_METHOD1(provideParametrizedService, void(int));
};

TEST(ServiceUserTests, serviceUsedOneTime) {
    ServiceMock* service = new ServiceMock();
    ServiceUser su(service);

    su.veryStrongAlgorithmUsesService();
    ASSERT_EQ(1, service->getCallsCnt());
}

TEST(ServiceUserTests, serviceParametrizedUsedOneTimeWith10) {
    ServiceMock* service = new ServiceMock();
    ServiceUser su(service);

    su.veryStrongAlgorithmUsesService();
    ASSERT_EQ(1, service->getCallsCnt(10));
}

TEST(ServiceUserTests, serviceParametrizedUsedZeroTimeWith20) {
    ServiceMock* service = new ServiceMock();
    ServiceUser su(service);

    su.veryStrongAlgorithmUsesService();
    ASSERT_EQ(0, service->getCallsCnt(20));
}

TEST(ServiceUserTestsGmock, serviceUsedOneTime) {
    ServiceMockGMock* service = new ServiceMockGMock();
    ServiceUser su(service);

    EXPECT_CALL(*service, provideService()).Times(1);

    su.veryStrongAlgorithmUsesService();
}

TEST(ServiceUserTestsGmock, serviceParametrizedUsedOneTimeWith10) {
    ServiceMockGMock* service = new ServiceMockGMock();
    ServiceUser su(service);

    EXPECT_CALL(*service, provideParametrizedService(10)).Times(1);

    su.veryStrongAlgorithmUsesService();
}
