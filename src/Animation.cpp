#include "Animation.h"

Animation::Animation(){
	//Constructeur par défault
	img_animation = 0;
	on_pause = false;
	delay = NULL;
	img_width = NULL;
	able = false;
	Animation_type = 0;
}

Animation::Animation(std::vector<sf::IntRect> boxes, unsigned int delay_, unsigned int side_){
	img_animation = 0;

	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
	delay = delay_;
	sf::Clock clock;
	on_pause = false;
	Animation_type = 0;
	able = false;

	if(side_ % 2 == 0){
		side = 0;
	}else{
		side = 1;
	}

	clock.restart();
}

Animation::Animation(std::vector<sf::IntRect> boxes, unsigned int delay_, std::string name, unsigned int side_){
	img_animation = 0;

	for(unsigned int i=0;i<boxes.size();i++){
		bounding_boxes.push_back(boxes.at(i));
	}

	nb_images = bounding_boxes.size();
	delay = delay_;
	sf::Clock clock;
	myName = name;

	on_pause = false;
	Animation_type = 0;
	able = false;

	if(side_ % 2 == 0){
		side = 0;
	}else{
		side = 1;
	}

	clock.restart();
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
	//std::cout<<" "<<img_animation;
	return bounding_boxes.at(img_animation);

}

sf::IntRect& Animation::get_bounding_box(int number){
	return bounding_boxes.at(number);
}

void Animation::new_frame(){

	elapsed = clock.getElapsedTime();

	//unsigned int T=elapsed.asMilliseconds();
	if(elapsed.asMilliseconds() > delay){
		if(Animation_type == 0){
			if(img_animation<nb_images - 1){
				if(!on_pause){
					img_animation++;
					clock.restart();
				}
				else{
					std::cout<<"Pause, gros"<<std::endl;
				}
			}
			else{
				img_animation = 0;
				clock.restart();
			}
		}
		else if(Animation_type == 1){
			if(!able){//AVANCER JUSQU'AU MAX
				if(!on_pause){
					img_animation++;
					clock.restart();
					if(img_animation == nb_images -1){
						able = true;
					}
				}
			}
			else{ //RECULER JUSQU'A 0
				if(!on_pause){
					if(img_animation != 0){					
					img_animation--;
					clock.restart();
					}
					else{
						img_animation++;
					clock.restart();
						able = false;
					}
				}
			}


			
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
		bounding_boxes[i].left = this->invert(bounding_boxes[i]).left;
	}

	std::vector<sf::IntRect> tableau;
	for(int i = 0;i <= bounding_boxes.size()-1;i++){
		tableau.push_back(bounding_boxes.at(i));
	}


	bounding_boxes = tableau;

	bounding_boxes;
}


void Animation::switch_animation_type(){
	if(Animation_type %2 == 0){
		Animation_type = 1;
	}else{
		Animation_type = 0;
	}
}