class FileSystem
{
public:
	static FileSystem& instance() {}
	virtual ~FileSystem() {}
	virtual char* readFile(char* path) = 0;
	virtual void writeFile(char* path, char* constents) = 0;

private:
	FileSystem() {}
};

class PS3FileSystem : public FileSystem
{
	virtual char* readFile(char* path)
	{
		//
	}
	virtual void writeFile(char* path, char* contents)
	{
		//
	}
};
class WiiFileSystem : public FileSystem
{
	virtual char* readFile(char* path)
	{
		//
	}
	virtual void writeFile(char* path, char* contents)
	{
		//
	}
};

FileSystem& FileSystem::instance()
{
#if PLATFORM == PLAYSTATION3
	static FileSystem* instance = new PS3FileSystem();
#elif PLATFORM == WII
	static FileSystem* instance = new WiiFileSystem();
#endif
	return *instance;
}
