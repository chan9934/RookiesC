class Monster
{
public:
	virtual ~Monster() {}
	virtual const char* getAttack() = 0;

protected:
	Monster(int startingHealth) : health_(startingHealth) {}

private:
	int health_;
};