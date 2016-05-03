//
#include <RedBot.h>
class Communication {
    public:
        Communication(RedBotMotors* motors)
            : _motors(motors), _state(cmd)  {}
        virtual ~Communication() {}
	void receiveData(int byteCount);
	void sendData() {}
    private:
        RedBotMotors* _motors;
        enum {cmd, data} _state;
        enum {version, drive, right, left, stop} _cmd;

};
