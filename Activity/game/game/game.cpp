// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
	
//globals 
int num_vertBox = 30, num_hoizBox = 20;
int size = 16; //number of pixels 16 x 16
int w = size * num_hoizBox; //background number of pixels in width
int l = size * num_hoizBox; // background numeber of pixels in height

int direction, snake_length = 4;

//max size of snake
struct Snake {
	int x, y;
}s[100];

struct Fruit {
	int x, y;
}food;

void Tick() {
	//how fast the snake should be moving
	//move the reamaining pieceies of snake s[1] -  s[99]
	for (int i = snake_length; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}
	//head of snake depends on direction of user 
	//user up 
	if (direction == 3)
	{
		s[0].y -= 1;
	}
	if (direction == 0)
	{
		s[0].y += 1;
	}
	if (direction == 1)
	{
		s[0].x -= 1;
	}
	if (direction == 2)
	{
		s[0].x += 1;
	}
	//if snake eats food it should grow
	if ((s[0].x) == food.x && (s[0].y) == food.y)
	{
		float time = 1; //modify timing when snake eats fruit
		snake_length++;

		//randomly place food somewhere else
		food.x = rand() % num_hoizBox;
		food.y = rand() % num_vertBox;

		time = 0; //reset timing
	}

	//boundary checking screen loop back on other side
	//LEFT and RIGHT
	if (s[0].x > num_hoizBox)
		s[0].x = 0;
	if (s[0].x < num_hoizBox)
		s[0].x = 0;
	//TOP and BOTTOM
	if (s[0].x > num_vertBox)
		s[0].y = 0;
	if (s[0].x < num_vertBox)
		s[0].y = 0;

	//check if go over snake 
	for (int i = 1; i < snake_length; i++)
	{
		//cut snake in hald from place eaten
		if (s[0].x = s[i].x && s[0].y == s[i].y)
			snake_length = i;
	}
}
void Tick2() {
	//how fast the snake should be moving
	//move the reamaining pieceies of snake s[1] -  s[99]
	for (int i = snake_length; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}
	//head of snake depends on direction of user 
	//user up 
	if (direction == 8)
	{
		s[0].y -= 1;
	}
	if (direction == 5)
	{
		s[0].y += 1;
	}
	if (direction == 6)
	{
		s[0].x -= 1;
	}
	if (direction == 7)
	{
		s[0].x += 1;
	}
	//if snake eats food it should grow
	if ((s[0].x) == food.x && (s[0].y) == food.y)
	{
		float time = 1; //modify timing when snake eats fruit
		snake_length++;

		//randomly place food somewhere else
		food.x = rand() % num_hoizBox;
		food.y = rand() % num_vertBox;

		time = 0; //reset timing
	}

	//boundary checking screen loop back on other side
	//LEFT and RIGHT
	if (s[0].x > num_hoizBox)
		s[0].x = 0;
	if (s[0].x < num_hoizBox)
		s[0].x = 0;
	//TOP and BOTTOM
	if (s[0].x > num_vertBox)
		s[0].y = 0;
	if (s[0].x < num_vertBox)
		s[0].y = 0;

	//check if go over snake 
	for (int i = 1; i < snake_length; i++)
	{
		//cut snake in hald from place eaten
		if (s[0].x = s[i].x && s[0].y == s[i].y)
			snake_length = i;
	}
}


int main()
{
	srand((unsigned int)time(0));

	RenderWindow window(VideoMode(w, l), "snake game!");


	//texture
	Texture t1, t2, t3;
	t1.loadFromFile("image/white.png");
	t2.loadFromFile("image/red.png");
	t3.loadFromFile("image/green.png");

	//second player
	/*
	String secondplayerTexture = "";
	Texture t4;
	t4.loadFromFile("image/" + secondplayerTexture);
	*/
	Texture t4, t7;
	t4.loadFromFile("image/black.png");
	t7.loadFromFile("image/blue.png");


	//add more random fruit
	Texture t5, t6;
	t5.loadFromFile("image/fuit2.png");
	t6.loadFromFile("image/fuit3.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);

	//adding more sprites
	Sprite sprite4(t4);
	Sprite sprite7(t7);
	//fruit
	Sprite sprite5(t5);
	Sprite sprite6(t6);


	food.x = 10;
	food.y = 10;

	Clock clock;

	float timer = 0, delay = .1f;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//alow us to check when a user does something
		Event e;

		//check when window is closed 
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}

		//controls for snake
		if (Keyboard::isKeyPressed(Keyboard::Up))
			direction = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			direction = 0;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			direction = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			direction = 2;

		//controls for snake
		if (Keyboard::isKeyPressed(Keyboard::Up))
			direction = 8;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			direction = 5;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			direction = 6;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			direction = 7;

		if (timer > delay)
		{
			timer = 0; //reset timer
			Tick(); //move snake one sprite forward
			Tick2();
		}

		//draw
		window.clear();

		//draw background
		for (int i = 0; i < num_hoizBox; i++)
		{
			for (int j = 0; j < num_vertBox; j++)
			{
				sprite1.setPosition(i*size, j*size);
				window.draw(sprite1);
				sprite4.setPosition(i*size + 1, j*size);
				window.draw(sprite4);

			}
		}

		//draw snake
		for (int i = 0; i < snake_length; i++)
		{
			sprite2.setPosition(s[i].x*size, s[i].y*size);
			window.draw(sprite2);
			sprite7.setPosition(s[i].x*size+1, s[i].y*size);
		}
		//draw fruit 
		int v = rand() % 3 + 1;

 		sprite3.setPosition(food.x*size, food.y*size);
		window.draw(sprite3);
		if (v == 1)
			window.draw(sprite3);
		else if (v == 2)
			window.draw(sprite5);
		else if (v==3)
			window.draw(sprite6);


	}

	return 0;
}