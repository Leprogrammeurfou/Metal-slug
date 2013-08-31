#include "Animation.h"

Animation::Animation(){
	//Constructeur par défault
	img_animation = 0;
	on_pause = false;
	delay = NULL;
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

void Animation::addAnimations(std::vector<sf::IntRect> boxes){
	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
}

sf::IntRect& Animation::get_bounding_box(){
	return bounding_boxes.at(img_animation);
}

sf::IntRect& Animation::get_bounding_box(int number){
	if(number == 0){
		return bounding_boxes.at(img_animation + 1);
	}
	else{
		return bounding_boxes.at(img_animation);
	}
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
}

sf::IntRect& Animation::loop(){
	this->start();
	this->new_frame();
	return this->get_bounding_box();
}

void Animation::to_zero(){
	img_animation = 0;
}