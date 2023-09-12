class Bjorn
{
public:
	Bjorn() : velocity_(0), x_(0), y_(0) {}
	void update(World& world, Graphics& graphics);


private:
	static const int WALK_ACCELERATION = 1;

	int velocity_;
	int x_, y_;

	Volume volume_;

	Sprite spriteStand_;
	Sprite spriteWalkLeft_;
	Sprite spriteWalkRight_;
};
class Volume
{

};
class Sprite
{

};
class World
{

};
class Graphics
{

};

