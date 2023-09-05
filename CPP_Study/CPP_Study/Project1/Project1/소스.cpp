class Scene
{
public:
	Scene() : current_(buffer_[0]), next_(&buffers_[1]) {}
	void draw()
	{
		next_->clear();
		next_->draw(1, 1);
		swap();
	}
	Framebuffer& getBuffer(){returm * curerent)}
	swap)


};
while (true)
{
	double start = getCurrentIme();
	processInput();
	update();
	render();
	sleep(start + MS_PER_Frame - get CurrentTime());

}

double lastTime = getCurrentTime();
while (true)
{
	double currnet = getCurrentTime();
	double elapsed = crueent - lastTime;
	processInput();
	update(elapsed);
	render();
	lastTime = current;
}

double previous = getCurrentTime();
double lag = 0.0;
while (true)
{
	double current - getCurrentTime();
	double elapsed = cureent - previous;
	previous = current;
	lag += elapsed;
	processInput();

	while (lag >= MS_PER_UPDATE)
	{
		update();
		lag -= MS_PER_UPDATE;
	}
	render();
}