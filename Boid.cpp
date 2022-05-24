#include <bits/stdc++.h>

#include "Vector2D.h"

using namespace std;

class Boid
{
    
    private:

        Vector2D position;
        Vector2D velocity;
        Vector2D accelaration;
    
    public:

        Boid(Vector2D pos, Vector2D vel, Vector2D acc)
        {
            this->position = pos;
            this->velocity = vel;
            this->accelaration = acc;
        }
        pair<float,float> getPosition(){
            pair<float, float> temp = position.get();
            return temp;
        }
        pair<float, float> getVelocity()
        {
            pair<float, float> temp = velocity.get();
            return temp;
        }
        pair<float, float> getAccelaration()
        {
            pair<float, float> temp = accelaration.get();
            return temp;
        }
        void set(Vector2D pos, Vector2D vel, Vector2D acc)
        {
            this->position = pos;
            this->velocity = vel;
            this->accelaration = acc;
        }
        void update()
        {
            this->position.addVector(this->velocity);
            this->velocity.addVector(this->accelaration);
        }
        //~Boid();

};

int main(){
    Boid boid(Vector2D(250.0, 250.0), Vector2D(2.0, 2.0), Vector2D(1.0, 1.0));
    int count = 0;
    while (count < 10)
    {
        boid.update();
        count++;
        cout << boid.getPosition().first << " " << boid.getPosition().second << endl;
        cout << boid.getVelocity().first << " " << boid.getVelocity().second << endl;
        cout << boid.getAccelaration().first << " " << boid.getAccelaration().second << endl;
    }
    return 0;
}