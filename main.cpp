#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

constexpr double PI = 3.14159;
constexpr double REDUC = 0.74;
constexpr double ANGLE = 35;

void createTree(VertexArray& treeArr, Vector2f next, float angle, float length)
{
	if (length < 2) return;

	treeArr.append(Vertex(next, Color(255, 190, 200)));

	auto c = (cos((2. * PI / 360) * angle));
	auto s = (sin((2. * PI / 360) * angle));

	float nextX = next.x + c * length;
	float nextY = next.y - s * length;

	Vector2f nextPoint(nextX, nextY);

	treeArr.append(Vertex(nextPoint, Color(255, 190, 200)));

	createTree(treeArr, nextPoint, angle + ANGLE, length * REDUC);
	createTree(treeArr, nextPoint, angle - ANGLE, length * REDUC);
}

int main()
{
	RenderWindow window(VideoMode(640, 480), "Binary Tree");

	VertexArray treeBranches(PrimitiveType::Lines);
	createTree(treeBranches, Vector2f(320, 400), 90, 100);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(treeBranches);
		window.display();
	}

	return 0;
}