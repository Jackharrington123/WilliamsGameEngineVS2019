#include "Meteor.h"
#include "Explosion.h"
const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
	makeDead();
	float wide = sprite_.getGlobalBounds().width;
	float high = sprite_.getGlobalBounds().height;
	ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(sprite_.getPosition().x - wide /2, sprite_.getPosition().y - high / 2));
	GAME.getCurrentScene().addGameObject(explosion);
}

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();


	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}
