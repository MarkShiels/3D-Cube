#include <Game.h>

bool updatable = false;

gpp::Vector3 v3;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);

	
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	Vector3f V1(1.0f, 1.0f, -5.0f);
	Vector3f V2(-1.0f, 1.0f, -5.0f);
	Vector3f V3(-1.0f, -1.0f, -5.0f);
	Vector3f V4(-1.0f, -1.0f, -5.0f);
	Vector3f V5(1.0f, 1.0f, -15.0f);
	Vector3f V6(-1.0f, 1.0f, -15.0f);
	Vector3f V7(-1.0f, -1.0f, -15.0f);
	Vector3f V8(1.0f, -1.0f, -15.0f);

	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f( V1.x, V1.y, V1.z);
		glVertex3f(V2.x, V2.y, V2.z);
		glVertex3f(V3.x, V3.y, V3.z);
	
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(V1.x, V1.y, V1.z);
		glVertex3f(V3.x, V3.y, V3.z);
		glVertex3f(V4.x, V4.y, V4.z);

		//Back Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(V5.x, V5.y, V5.z);
		glVertex3f(V6.x, V6.y, V6.z);
		glVertex3f(V7.x, V7.y, V7.z);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(V5.x, V5.y, V5.z);
		glVertex3f(V7.x, V7.y, V7.z);
		glVertex3f(V8.x, V8.y, V8.z);

		//Top face
		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(V1.x, V1.y, V1.z);
		glVertex3f(V2.x, V2.y, V2.z);
		glVertex3f(V6.x, V6.y, V6.z);

		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, 1.0f, -15.0f);
	
		//Bottom Face
		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);

		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);
		glVertex3f(1.0f, -1.0f, -15.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);

		//Left face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);

		//Right face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);
		glVertex3f(1.0f, -1.0f, -15.0f);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, 1.0f, -15.0f);
		glVertex3f(1.0f, -1.0f, -15.0f);
	}
	glEnd();
	glEndList();



	
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asMicroseconds() >= 0.00000000001f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

