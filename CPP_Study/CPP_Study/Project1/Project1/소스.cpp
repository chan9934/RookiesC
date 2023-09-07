

enum Instruction
{
	INST_SET_HEALTH = 0x00,
	INST_SET_WISDOM = 0x01,
	INST_SET_AGILITY = 0x02,
	INST_SET_SOUND = 0x03,
	INST_SET_PARTICLES = 0x04,

};


class VM
{
public:
	VM() : stackSize_(0) {}
	void interpret(char bytecode[], int size)
	{
		for (int i = 0; i < size; ++i)
		{
			char instruction = bytecode[i];

			switch (instruction)
			{
			case INST_SET_HEALTH:
			{
				int amount = pop();
				int wizard = pop();
				setHealth(wizard, amount);
				break;
			}
			case INST_SET_WISDOM:
				setWisdom(0, 100);
				break;
			case INST_SET_AGILITY:
				setAgility(0, 100);
				break;
			case INST_SET_SOUND:
				playSound(pop());
				break;
			case INST_SET_PARTICLES:
				spawnParticles(pop());
				break;
			case INST_LITERAL:
			{
				int value = bytecode[++i];
				push(value);
				break;
			}
			case INST_GET_HEALTH:
			{
				int wizard = pop();
				push(getHealth(wizard));
				break;
			}
			case INST_ADD:
			{
				int b = pop();
				int a = pop();
				push(a + b);
				break;
			}
			}
		}
	}
private:
	static const int MAX_STACK = 128;
	int stackSize_;
	int stack_[MAX_STACK];

private:
	void push(int value)
	{
		assert(stackSize_ < MAX_STACK);
		stack_[stackSize_++] = value;
	}

	int pop()
	{a
		assert(stackSize_ > 0);
		return stack_[--stackSize_];
	}
};