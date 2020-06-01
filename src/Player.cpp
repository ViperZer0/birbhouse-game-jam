#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "Equipment.hpp"
#include "Logger.hpp"

Player::Player(){
    pos[0] = 0;
    pos[1] = 0;
    vel[0] = 0;
    vel[1] = 0;
    acc[0] = 0;
    acc[1] = 0;
    jumpVel=400;
    moveSpeed=200;
    fallAcc=500;
    jumpDebounce=false;
    falling=false;
    collideRight=false;
    collideLeft=false;
    delta.restart();
    id = "player";
    pickingUp = false;
    //Setup player
    sprite = new AnimatedSprite();
    AnimationSequence *squat;
    squat = new AnimationSequence();
    squat->addFrame(sf::IntRect(0,0,130,200),sf::milliseconds(500));
    squat->addFrame(sf::IntRect(130,0,130,200),sf::milliseconds(500));
    squat->setBidirectional(false);
    sprite->setAnimationSeq(squat);
    pos[0]=200;
    pos[1]=200;
}

void Player::handleInput(sf::Event event){
    static bool right;
    static bool left;
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Right){
            right = true;
            left = false;
        }
        if(event.key.code == sf::Keyboard::Left)
        {
            left = true;
            right = false;
        }
        if(event.key.code == sf::Keyboard::Space)
            this->jump();
    }
    else if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::Right)
            right = false;
        if(event.key.code == sf::Keyboard::Left)
            left = false;
    }

    if(right) this->right();
    else if(left) this->left();
    else this->stop();
}

void Player::pickUp(GameObject *obj){
    if(obj->getId() == std::string("equipment")){
        Equipment *equipped = static_cast<Equipment *>(obj);
        equip(equipped);
    }
    /*
    else if(obj->getId() == std::string("coin")){
        Coin *coin = std::static_cast<Coin *>(obj);
        addCoins(coin->getAmount());
    }*/
}

void Player::equip(Equipment *equip){
    Slot slot = equip->getSlot();
    std::vector<Equipment *>::iterator equipped;
    Logger::log(Log::DEBUG,equipment.size());
    for(equipped=equipment.begin();equipped!=equipment.end();equipped++){
        Logger::log(Log::DEBUG,"Equipment");
        if((*equipped)->getSlot() == slot)
            goto replace;
    }
    Logger::log(Log::DEBUG,"No matching slot");
    equipment.push_back(equip);
    equip->equipped(this);

    return;

    //GOTO
    replace: 
    Logger::log(Log::DEBUG,"Replacing an item");
    if(equip->getPickedUp()){
        if(pickingUp){
            swap(equip,equipped);
            return;
        }
    }
    else{
        if(pickingUp){
            swap(equip,equipped);
            return;
        }
        if(equip->getValue() > (*equipped)->getValue()){
            swap(equip,equipped);
            return;
        }
    }
}     

void Player::swap(Equipment *a, std::vector<Equipment *>::iterator b){
    equipment.push_back(a);
    a->equipped(this);
    (*b)->dropped(this);
    equipment.erase(b);
}

void Player::update(Player *player){
    //YOOO we can do that, note to seLF
    GameActor::update(player);
    switch(sprite->getFrame()){
        case 0:
            equipOffset = sf::Vector2f(0,0);
            break;
        case 1:
            equipOffset = sf::Vector2f(0,8);
            break;
        default:
            equipOffset = sf::Vector2f(0,0);
            break;
    }
}
