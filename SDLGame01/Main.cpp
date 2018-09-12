#include <iostream>
#include <SDL.h>
#include <iostream>

#include "Engine/Engine.hpp"
#include "Dot.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Mandel.hpp"

int main(int argc, char* argv[]) {

	Engine* engine = new Engine();

	static const int SCREENWIDTH = 640;
	static const int SCREENHEIGHT = 480;

	if (!engine->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, 0)) {
		return -1;
	}

	/*Dot* obj = new Dot(120, 15, 30);
	obj->setEngine(engine);
	if (!obj->init()) {
		return -1;
	}

	engine->addObj(obj);*/

	/*Point* point1 = new Point(420, 350);
	Point* point2 = new Point(800, 150);
	Point* point3 = new Point(900, 570);

	Line* line1 = new Line(point1->getPosition(), point2->getPosition());
	Line* line2 = new Line(point1->getPosition(), point3->getPosition());
	Line* line3 = new Line(point2->getPosition(), point3->getPosition());

	point1->setEngine(engine);
	point2->setEngine(engine);
	point3->setEngine(engine);
	line1->setEngine(engine);
	line2->setEngine(engine);
	line3->setEngine(engine);

	point1->init();
	point2->init();
	point3->init();
	line1->init();
	line2->init();
	line3->init();

	engine->addObj(point1);
	engine->addObj(point2);
	engine->addObj(point3);
	engine->addObj(line1);
	engine->addObj(line2);
	engine->addObj(line3);*/

	Mandel* mandel = new Mandel(SCREENWIDTH, SCREENHEIGHT);
	mandel->setEngine(engine);
	mandel->init();

	engine->addObj(mandel);

	while (engine->isRunning()) {
		engine->handleEvent();
		engine->update();
		engine->render();
		SDL_Delay(1);
	}

	engine->quit();

	return 0;

}
