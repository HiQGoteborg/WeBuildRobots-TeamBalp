#include "communication.h"
#include "gmock/gmock.h"
#include "Arduino.h"
#include "Wire.h"

using ::testing::Return;
using ::testing::NotNull;
using ::testing::_;

class CommunicationTest : public ::testing::Test {
    protected:
/*
    class MockTimerCallback : public Timer::CallbackInterface {
        public:
            virtual ~MockTimerCallback() {}
            MOCK_METHOD0(onTimeout, void());
    };
*/
    RedBotMotorsMock* redbotMotorMock;
    ArduinoMock* arduinoMock;
    WireMock* wireMock;
    CommunicationTest() :
        redbotMotorMock( redbotMotorInstance() ),
        arduinoMock( arduinoMockInstance() ),
        wireMock( WireMockInstance() )
        {}
    virtual ~CommunicationTest() {
        releaseRedbotMock();
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

    Communication communication(redbotMotorMock);
    communication.receiveData(2);
    communication.sendData();
}

TEST_F(CommunicationTest, Forward_1_255)
{
    EXPECT_CALL(*wireMock, available())
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*wireMock, read())
        .Times(2)
        .WillOnce(Return(1))
        .WillOnce(Return(255));


    printf("*** expect %p %d\n", redbotMotorMock, 255);
    //EXPECT_CALL(*redbotMotorMock, drive(_))
     //   .Times(1);

    EXPECT_CALL(*wireMock, write(NotNull(), 2))
        .Times(1);

    Communication communication(redbotMotorMock);
    communication.receiveData(2);
    communication.sendData();
}




TEST_F(CommunicationTest, Right_2_200)
{
    EXPECT_CALL(*wireMock, available())
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*wireMock, read())
        .Times(2)
        .WillOnce(Return(2))
        .WillOnce(Return(200));


    printf("*** expect %p %d\n", redbotMotorMock, 255);
    //EXPECT_CALL(*redbotMotorMock, drive(_))
     //   .Times(1);

    EXPECT_CALL(*wireMock, write(NotNull(), 2))
        .Times(1);

    Communication communication(redbotMotorMock);
    communication.receiveData(2);
    communication.sendData();
}




TEST_F(CommunicationTest, Left_3_125)
{
    EXPECT_CALL(*wireMock, available())
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*wireMock, read())
        .Times(2)
        .WillOnce(Return(3))
        .WillOnce(Return(125));


    printf("*** expect %p %d\n", redbotMotorMock, 255);
    //EXPECT_CALL(*redbotMotorMock, drive(_))
     //   .Times(1);

    EXPECT_CALL(*wireMock, write(NotNull(), 2))
        .Times(1);

    Communication communication(redbotMotorMock);
    communication.receiveData(2);
    communication.sendData();
}




TEST_F(CommunicationTest, Stop_4_0)
{
    EXPECT_CALL(*wireMock, available())
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*wireMock, read())
        .Times(2)
        .WillOnce(Return(4))
        .WillOnce(Return(0));


    printf("*** expect %p %d\n", redbotMotorMock, 255);
    //EXPECT_CALL(*redbotMotorMock, drive(_))
     //   .Times(1);

    EXPECT_CALL(*wireMock, write(NotNull(), 2))
        .Times(1);

    Communication communication(redbotMotorMock);
    communication.receiveData(2);
    communication.sendData();
}



