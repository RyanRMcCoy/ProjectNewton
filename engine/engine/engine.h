#include <vector>

class engine
{
private:
	float lastUpdate;

	vector<physicalObject> objects;
	aabbHandler collisionHandler;
public:
	engine();

	void addObject(physicalObject o);
	vector<physicalObject> getObjects();
	void update();
};