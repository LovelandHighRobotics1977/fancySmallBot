#include "Headers.h"
#include <cmath>
class Coords{
    public:

    float posX = 0; // robot's x position. Starting position will NOT be 0
    float posY = 0; // robot's y position. Same as with x

    void toDestination(float x, float y){
        float dY = y - posY;
        float dX = x - posX;

        // sine of distance formula, converted to degrees
        float angle = 90 - asin(dX/pow((pow(dY, 2) + pow(dX, 2)), 2))
        *(180 / 3.141592653589793238);
        angle = 90 - abs(angle);

        //determine quadrant (I, II, III, VI)
        char direction_ = 'r';
        
        if(dX > 0){
            direction_ = 'r';
        } else{
            direction_ = 'l';
        };
        
        if(dY < 0){
            turnFor((180 - angle), 0.5, direction_);
            return;
        }

        turnFor(angle, 0.5, direction_);

        posX = x;
        posY = y;
    }

    void turnFor(float degrees, float speed, char direction);
    private:
};
