#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
    public :
        Character();
        ~Character();
        double getHorizonAcceleration() const;
        double getVerticalAcceleration() const;
        void increaseHorizonAcceleration(double bonus_acceleration);
        void divideHorizonAcceleration();
        void increaseVerticalAcceleration(double bonus_acceleration);
        void sufferFromGravity();

    private : 
        double _horizon_acceleration;
        double _vertical_acceleration;
};

#endif