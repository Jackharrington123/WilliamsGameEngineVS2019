#include "Explosion.h"

Explosion::Explosion(sf::Vector2f pos)
	: AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/explosion-spritesheet.png"));
	SetUpExplosionAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);
}

void Explosion::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 64, 64));
	frames.push_back(sf::IntRect(64, 0, 64, 64));
	frames.push_back(sf::IntRect(128, 0, 64, 64));
	frames.push_back(sf::IntRect(129, 0, 64, 64));
	frames.push_back(sf::IntRect(256, 0, 64, 64));
	frames.push_back(sf::IntRect(320, 0, 64, 64));
	frames.push_back(sf::IntRect(384, 0, 64, 64));
	frames.push_back(sf::IntRect(448, 0, 64, 64));
	frames.push_back(sf::IntRect(512, 0, 64, 64));

	addAnimation("explosion", frames);
}
void Explosion::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);
	if (!isPlaying())
	{
		makeDead();
	}
}