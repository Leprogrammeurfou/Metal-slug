#include "Animation.h"

Animation::Animation(){
	//Constructeur par défault
	img_animation = 0;
	on_pause = false;
	delay = NULL;
	img_width = NULL;
}

Animation::Animation(std::vector<sf::IntRect> boxes, unsigned int delay_){
	img_animation = 0;

	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
	delay = delay_;
	sf::Clock clock;
}

Animation::Animation(std::vector<sf::IntRect> boxes, unsigned int delay_, std::string name){
	img_animation = 0;

	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
	delay = delay_;
	sf::Clock clock;
	myName = name;
}

void Animation::addAnimations(std::vector<sf::IntRect> boxes){
	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
}

void Animation::setDelay(int delay_){
	delay= delay_;
}

sf::IntRect& Animation::get_bounding_box(){
	return bounding_boxes.at(img_animation);
	
}

sf::IntRect& Animation::get_bounding_box(int number){
		return bounding_boxes.at(number);
}

void Animation::new_frame(){
	
	elapsed = clock.getElapsedTime();


	std::cout<<"Time Elapsed = "<< elapsed.asMilliseconds();
	std::cout<<std::endl;
	//unsigned int T=elapsed.asMilliseconds();
	if(elapsed.asMilliseconds() > delay){
	if(img_animation<nb_images - 1){
		if(!on_pause){
			img_animation++;
			clock.restart();
		}
		
	}
	else{
			img_animation = 0;
			clock.restart();
		}
	}
}

void Animation::pause(){
	on_pause = true;
}
void Animation::start(){
	on_pause = false;
	clock.restart();
}

sf::IntRect& Animation::loop(){
	this->new_frame();
	return this->get_bounding_box();
}

void Animation::to_zero(){
	img_animation = 0;
}

sf::IntRect Animation::invert(sf::IntRect old_box){
	sf::IntRect temp;
	temp.left = this->img_width - (old_box.left + old_box.width);
	return temp;
}

void Animation::invertAll(unsigned int image_width){
	this->img_width = image_width;
	for(int i=0;i<nb_images;i++){
		bounding_boxes[i] = this->invert(bounding_boxes[i]);
	}
}