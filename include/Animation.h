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

	std::string myName;
	unsigned int img_width;
public:
	// \Default constructor
	Animation();
	// \New image to the animation each time.
	Animation(std::vector<sf::IntRect> boxes, unsigned int delay_);

	Animation(std::vector<sf::IntRect> boxes, unsigned int delay_,std::string name);
	// \Add a vector of bounding box for the animations (add the animations at the end)
	void addAnimations(std::vector<sf::IntRect> boxes);
	void setDelay(int delay_);

	// \get the bounding box from the current img_animation
	sf::IntRect& get_bounding_box();
	// \get the bounding box from a number
	sf::IntRect& get_bounding_box(int number);

	// \starts a new frame to the animation (doesn't occur on each loop)
	void new_frame();

	// \set the animation in pause
	void pause();
	// \starts the animations if it is paused
	void start();
	
	// \does the loops of the animation & returns the current bounding box
	sf::IntRect& loop();

	// \reset the animation to zero
	void to_zero();

	sf::IntRect invert(sf::IntRect old_box);

	void invertAll(unsigned int image_width);
	/*TEMP*/
	// \get the variable img_animation
	int get_img_animation(){return this->img_animation;}
};