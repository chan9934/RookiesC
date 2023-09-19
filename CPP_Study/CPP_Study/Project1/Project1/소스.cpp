class Audio
{
public:
	virtual ~Audio() {}
	virtual void playSound(int soundID) = 0;
	virtual void stopSound(int soundID) = 0;
	virtual void stopAllSounds() = 0;
};

class ConsoleAudio : public Audio
{
	virtual void playSound(int soundID)
	{

	}
	virtual void stopSound(int soundID)
	{

	}
	virtual void stopAllSounds()
	{

	}
};

class Locator
{
public:
	static Audio* getAudio() { return service_; }
	static void provide(Audio* service) { service_ = service; }

private:
	static Audio* service_;
};