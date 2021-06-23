#include "Character.hpp"

Character::Character() : _horizon_acceleration(0), _vertical_acceleration(3)
{

}

Character::~Character()
{

}

double Character::getHorizonAcceleration() const
{
    return (_horizon_acceleration);
}


double Character::getVerticalAcceleration() const
{
    return (_vertical_acceleration);
}

void Character::increaseHorizonAcceleration(double bonus_acceleration)
{
    _horizon_acceleration += bonus_acceleration;

    if (_horizon_acceleration > 3)
        _horizon_acceleration = 3;
    else if (_horizon_acceleration < -3)
        _horizon_acceleration = -3;
}

void Character::increaseVerticalAcceleration(double bonus_acceleration)
{
    _vertical_acceleration += bonus_acceleration;

    if (_vertical_acceleration > 3)
        _vertical_acceleration = 3;
}
void Character::divideHorizonAcceleration()
{
    _horizon_acceleration /= 1.2;
}

void Character::sufferFromGravity()
{
    if (_vertical_acceleration < 3)
        _vertical_acceleration  += 1;
}