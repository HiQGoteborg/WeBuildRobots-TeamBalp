#include "communication.h"
#include "gmock/gmock.h"
#include "Arduino.h"
#include "Wire.h"

using ::testing::Return;
using ::testing::NotNull;

class CommunicationTest : public ::testing::Test {
    protected:
/*
    class MockTimerCallback : public Timer::CallbackInterface {
        public:
            virtual ~MockTimerCallback() {}
            MOCK_METHOD0(onTimeout, void());
    };
*/
    ArduinoMock* arduinoMock;
    WireMock* wireMock;
    CommunicationTest() :
        arduinoMock( arduinoMockInstance() ),
        wireMock( WireMockInstance() )
        {}
    virtual ~CommunicationTest() {
        releaseArduinoMock();
        releaseWireMock();
    }
};

TEST_F(CommunicationTest, VersionCall_0_0)
{
    EXPECT_CALL(*wireMock, available())
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*wireMock, read())
        .Times(2)
        .WillOnce(Return(0))
        .WillOnce(Return(0));

    EXPECT_CALL(*wireMock, write(NotNull(), 2))
        .Times(1);

    Communication communication;
    communication.receiveData(2);
    communication.sendData();
}


