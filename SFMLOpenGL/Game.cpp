#include <Game.h>

bool updatable = false;


Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);

	
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
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

	Matricies();
	
}

void Game::Matricies()
{
	Vector3 V1(1.0f, 1.0f, -5.0f);
	Vector3 V2(-1.0f, 1.0f, -5.0f);
	Vector3 V3(-1.0f, -1.0f, -5.0f);
	Vector3 V4(1.0f, -1.0f, -5.0f);
	Vector3 V5(1.0f, 1.0f, -15.0f);
	Vector3 V6(-1.0f, 1.0f, -15.0f);
	Vector3 V7(-1.0f, -1.0f, -15.0f);
	Vector3 V8(1.0f, -1.0f, -15.0f);

	Matrix3 mF1(V1, V2, V3);
	Matrix3 mF2(V1, V3, V4);
	Matrix3 mB1(V5, V6, V7);
	Matrix3 mB2(V5, V7, V8);
	Matrix3 mT1(V1, V2, V6);
	Matrix3 mT2(V1, V5, V6);
	Matrix3 mU1(V3, V7, V4);
	Matrix3 mU2(V4, V8, V7);
	Matrix3 mL1(V2, V6, V7);
	Matrix3 mL2(V2, V3, V7);
	Matrix3 mR1(V1, V5, V8);
	Matrix3 mR2(V1, V4, V8);

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(mF1.m_A11, mF1.m_A12, mF1.m_A13);
		glVertex3f(mF1.m_A21, mF1.m_A22, mF1.m_A23);
		glVertex3f(mF1.m_A31, mF1.m_A32, mF1.m_A33);
		/*glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		glVertex3f(V2.m_x, V2.m_y, V2.m_z);
		glVertex3f(V3.m_x, V3.m_y, V3.m_z);*/

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(mF2.m_A11, mF2.m_A12, mF2.m_A13);
		glVertex3f(mF2.m_A21, mF2.m_A22, mF2.m_A23);
		glVertex3f(mF2.m_A31, mF2.m_A32, mF2.m_A33);
		/*glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		glVertex3f(V3.m_x, V3.m_y, V3.m_z);
		glVertex3f(V4.m_x, V4.m_y, V4.m_z);*/

		//Back Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(mB1.m_A11, mB1.m_A12, mB1.m_A13);
		glVertex3f(mB1.m_A21, mB1.m_A22, mB1.m_A23);
		glVertex3f(mB1.m_A31, mB1.m_A32, mB1.m_A33);
		/*glVertex3f(V5.m_x, V5.m_y, V5.m_z);
		glVertex3f(V6.m_x, V6.m_y, V6.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);*/

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(mB2.m_A11, mB2.m_A12, mB2.m_A13);
		glVertex3f(mB2.m_A21, mB2.m_A22, mB2.m_A23);
		glVertex3f(mB2.m_A31, mB2.m_A32, mB2.m_A33);
		/*glVertex3f(V5.m_x, V5.m_y, V5.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);
		glVertex3f(V8.m_x, V8.m_y, V8.m_z);*/

		//Top face
		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(mT1.m_A11, mT1.m_A12, mT1.m_A13);
		glVertex3f(mT1.m_A21, mT1.m_A22, mT1.m_A23);
		glVertex3f(mT1.m_A31, mT1.m_A32, mT1.m_A33);
		/*glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		glVertex3f(V2.m_x, V2.m_y, V2.m_z);
		glVertex3f(V6.m_x, V6.m_y, V6.m_z);*/

		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(mT2.m_A11, mT2.m_A12, mT2.m_A13);
		glVertex3f(mT2.m_A21, mT2.m_A22, mT2.m_A23);
		glVertex3f(mT2.m_A31, mT2.m_A32, mT2.m_A33);
		/*glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		glVertex3f(V5.m_x, V5.m_y, V5.m_z);
		glVertex3f(V6.m_x, V6.m_y, V6.m_z);
	*/
	//Bottom Face
		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(mU1.m_A11, mU1.m_A12, mU1.m_A13);
		glVertex3f(mU1.m_A21, mU1.m_A22, mU1.m_A23);
		glVertex3f(mU1.m_A31, mU1.m_A32, mU1.m_A33);
		/*glVertex3f(V3.m_x, V3.m_y, V3.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);
		glVertex3f(V4.m_x, V4.m_y, V4.m_z);*/


		glColor3f(0.0, 1.0f, 0.0f);
		glVertex3f(mU2.m_A11, mU2.m_A12, mU2.m_A13);
		glVertex3f(mU2.m_A21, mU2.m_A22, mU2.m_A23);
		glVertex3f(mU2.m_A31, mU2.m_A32, mU2.m_A33);
		/*glVertex3f(V4.m_x, V4.m_y, V4.m_z);
		glVertex3f(V8.m_x, V8.m_y, V8.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);*/

		//Left face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(mL1.m_A11, mL1.m_A12, mL1.m_A13);
		glVertex3f(mL1.m_A21, mL1.m_A22, mL1.m_A23);
		glVertex3f(mL1.m_A31, mL1.m_A32, mL1.m_A33);
		/*glVertex3f(V2.m_x, V2.m_y, V2.m_z);
		glVertex3f(V6.m_x, V6.m_y, V6.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);*/

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(mL2.m_A11, mL2.m_A12, mL2.m_A13);
		glVertex3f(mL2.m_A21, mL2.m_A22, mL2.m_A23);
		glVertex3f(mL2.m_A31, mL2.m_A32, mL2.m_A33);
		/*glVertex3f(V2.m_x, V2.m_y, V2.m_z);
		glVertex3f(V3.m_x, V3.m_y, V3.m_z);
		glVertex3f(V7.m_x, V7.m_y, V7.m_z);*/

		//Right face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(mR1.m_A11, mR1.m_A12, mR1.m_A13);
		glVertex3f(mR1.m_A21, mR1.m_A22, mR1.m_A23);
		glVertex3f(mR1.m_A31, mR1.m_A32, mR1.m_A33);
		/*glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		glVertex3f(V5.m_x, V5.m_y, V5.m_z);
		glVertex3f(V8.m_x, V8.m_y, V8.m_z);**/

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(mR2.m_A11, mR2.m_A12, mR2.m_A13);
		glVertex3f(mR2.m_A21, mR2.m_A22, mR2.m_A23);
		glVertex3f(mR2.m_A31, mR2.m_A32, mR2.m_A33);
		///*glVertex3f(V1.m_x, V1.m_y, V1.m_z);
		//glVertex3f(V4.m_x, V4.m_y, V4.m_z);
		//glVertex3f(V8.m_x, V8.m_y, V8.m_z);
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

