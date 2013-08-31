#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
class Animation{
private:
	std::vector<sf::IntRect> bounding_boxes;
	int nb_images;
	int img_animation;

	bool on_pause;
	int delay;

	sf::Clock clock;
	sf::Time elapsed;
public:
	Animation();
	Animation(std::vector<sf::IntRect> boxes, unsigned int delay_);//New image to the animation each time.

	void addAnimations(std::vector<sf::IntRect> boxes);

	sf::IntRect& get_bounding_box();
	sf::IntRect& get_bounding_box(int number);

	void new_frame();

	void pause();
	void start();
	
	sf::IntRect& loop();

	void to_zero();

	/*TEMP*/
	int get_img_animation(){return this->img_animation;}
};