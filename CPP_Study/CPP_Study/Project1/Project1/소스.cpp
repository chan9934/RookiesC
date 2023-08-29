class GameObject
{
protected:
	Log& getLog() { return log_; }

private:
	static Log& log_;
};
class Enemy : public GameObject
{
	void doSomething()
	{
		getLog().write("IO canLog!");
	}
};