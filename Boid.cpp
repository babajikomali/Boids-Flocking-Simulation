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

vector<pair<float,float>> show(Boid boid1, Boid boid2){
    pair<float, float> position1 = boid1.getPosition();
    pair<float, float> position2 = boid2.getPosition();
    vector<pair<float, float>> ret;
    ret.push_back(position1);
    ret.push_back(position2);
    return ret;
}

int main(){
    Boid boid1(Vector2D(250.0, 250.0), Vector2D(2.0, 2.0), Vector2D(1.0, 1.0));
    Boid boid2(Vector2D(100.0, 100.0), Vector2D(2.5, 2.5), Vector2D(1.25, 1.25));

    /*int count = 0;
    while (count < 10)
    {
        boid1.update();
        count++;
        cout << boid1.getPosition().first << " " << boid.getPosition().second << endl;
        cout << boid1.getVelocity().first << " " << boid.getVelocity().second << endl;
        cout << boid1.getAccelaration().first << " " << boid.getAccelaration().second << endl;
    }*/
    return 0;
}