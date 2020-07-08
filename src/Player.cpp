#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp> 
#include "Equipment.hpp" 
#include "Logger.hpp" 
#include "Game.hpp"
Player::Player(Game *g){
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
    movingRight=true;
    delta.restart();
    id = "player";
    pickingUp = false;
    helmet = nullptr;
    mainHand = nullptr;
    offHand = nullptr;
    foot = nullptr;
    game = g;
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
    sprite->getSprite()->setOrigin(130.f/2.f,200.f/2.f);
}

void Player::handleInput(sf::Event event){
    
    static bool r;
    static bool l;
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Right){
            //if(r==false) flip();
            r = true;
            //l = false;
        } 
        if(event.key.code == sf::Keyboard::Left) {
            //if(l==false) flip();
            l = true;
            //r = false;
        }
        if(event.key.code == sf::Keyboard::Space)
            this->jump();
    }
    else if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::Right)
            r = false;
        if(event.key.code == sf::Keyboard::Left)
            l = false;
    }
    
    if(r & !l){
        if(!movingRight){
            movingRight=true;
            flip();
        }
        this->right();
    }
    else if(l & !r){
        if(movingRight){
            movingRight=false;
            flip();
        }
        this->left();
    }
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
    //Logger::log(Log::DEBUG,equipment.size());
    for(equipped=equipment.begin();equipped!=equipment.end();equipped++){
        //Logger::log(Log::DEBUG,"Equipment");
        if((*equipped)->getSlot() == slot)
            goto replace;
    }
    //Logger::log(Log::DEBUG,"No matching slot");
    linkSlot(equip);
    equipment.push_back(equip);
    equip->equipped(this);
    return;

    //GOTO
    replace: 
    //Logger::log(Log::DEBUG,"Replacing an item");
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
    linkSlot(a);
    equipment.push_back(a);
    a->equipped(this);
    (*b)->dropped();
    equipment.erase(b);
}

void Player::linkSlot(Equipment *a){
    game->removeObject(a);
    switch(a->getSlot()){
        case Slot::HEAD:
            helmet = a;
            break;
        case Slot::OFFHAND:
            offHand = a;
            break;
        case Slot::MAINHAND:
            mainHand = a;
            break;
        case Slot::FOOT:
            foot = a;
            break;
        default:
            break;
    }
} 

void Player::update(){
    Logger::log(Log::DEBUG,"Origin:",sprite->getSprite()->getOrigin());
    //YOOO we can do that, note to seLF
    GameActor::update();

    if(helmet != nullptr)
        helmet->update();
    if(mainHand != nullptr)
        mainHand->update();
    if(offHand != nullptr)
        offHand->update();
    if(foot != nullptr)
        foot->update();

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

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    if(flipped){
        if(mainHand != nullptr)
            target.draw(*mainHand);
        target.draw(*sprite);
        if(offHand != nullptr)
            target.draw(*offHand);
        if(helmet != nullptr)
            target.draw(*helmet);
        if(foot != nullptr)
            target.draw(*foot);
    }
    else{
        if(offHand != nullptr)
            target.draw(*offHand);
        target.draw(*sprite);
        if(mainHand != nullptr)
            target.draw(*mainHand);
        if(helmet != nullptr)
            target.draw(*helmet);
        if(foot != nullptr)
            target.draw(*foot);
    }
}

void Player::flip(){
    GameActor::flip();
    if(helmet!=nullptr)
        helmet->flip();
    if(mainHand!=nullptr)
        mainHand->flip();
    if(offHand !=nullptr)
        offHand->flip();
    if(foot != nullptr)
        foot->flip();
}
