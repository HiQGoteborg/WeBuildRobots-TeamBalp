//

class Communication {
    public:
        virtual ~Communication() {}
	void receiveData(int byteCount);
	void sendData() {}
    private:

};
