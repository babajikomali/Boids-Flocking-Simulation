#include <bits/stdc++.h>

using namespace std;

class Vector2D
{

    private:

        float x, y;

    public:

        Vector2D(float comp_x = 0.0, float comp_y = 0.0)
        {
            this->x = comp_x;
            this->y = comp_y;
        }
        Vector2D(const Vector2D &vec)
        {
            this->x = vec.x;
            this->y = vec.y;
        }
        void set(float comp_x, float comp_y)
        {
            this->x = comp_x;
            this->y = comp_y;
        }
        pair<float, float> get()
        {
            pair<float, float> temp = {this->x, this->y};
            return temp;
        }
        float magnitude()
        {
            float x_square = this->x * this->x;
            float y_square = this->y * this->y;
            return sqrt(x_square + y_square);
        }
        float magVector(Vector2D vec)
        {
            float x_square = vec.x * vec.x;
            float y_square = vec.y * vec.y;
            return sqrt(x_square + y_square);
        }
        void normalize()
        {
            float m = magnitude();
            if (m > 0)
            {
                this->x /= m;
                this->y /= m;
            }
        }
        void setMagnitude(float mag)
        {
            normalize();
            this->x *= mag;
            this->y *= mag;
        }
        void randomVector()
        {
            this->x = (float)rand();
            this->y = (float)rand();
            normalize();
        }
        void addVector(Vector2D vec)
        {
            this->x += vec.x;
            this->y += vec.y;
        }
        void addScalar(float sca)
        {
            this->x += sca;
            this->y += sca;
        }
        Vector2D addTwoVec(Vector2D vec1, Vector2D vec2)
        {
            Vector2D temp;
            temp.x = vec1.x + vec2.x;
            temp.y = vec1.y + vec2.y;
            return temp;
        }
        void subVector(Vector2D vec)
        {
            this->x -= vec.x;
            this->y -= vec.y;
        }
        void subScalar(float sca)
        {
            this->x -= sca;
            this->y -= sca;
        }
        Vector2D subTwoVec(Vector2D vec1, Vector2D vec2)
        {
            Vector2D temp;
            temp.x = vec1.x - vec2.x;
            temp.y = vec1.y - vec2.y;
            return temp;
        }
        void mulVector(Vector2D vec)
        {
            this->x = (this->x * vec.x) - (this->y * vec.y);
            this->y = (this->x * vec.y) + (this->y * vec.x);
        }
        void mulScalar(float sca)
        {
            this->x *= sca;
            this->y *= sca;
        }
        Vector2D mulTwoVec(Vector2D vec1, Vector2D vec2)
        {
            Vector2D temp;
            temp.x = (vec1.x * vec2.x) - (vec1.y * vec2.y);
            temp.y = (vec1.x * vec2.y) + (vec1.y * vec2.x);
            return temp;
        }
        void divVector(Vector2D vec)
        {
            Vector2D temp1(this->x, this->y), temp2(vec.x, -vec.y);
            Vector2D temp = mulTwoVec(temp1, temp2);
            float den = (this->x * vec.x) + (this->y * vec.y);
            this->x = temp.x / den;
            this->y = temp.y / den;
        }
        void divScalar(float sca)
        {
            this->x /= sca;
            this->y /= sca;
        }
        Vector2D divTwoVec(Vector2D vec1, Vector2D vec2)
        {
            Vector2D temp1(vec1), temp2(vec2.x, -vec2.y);
            Vector2D temp = mulTwoVec(temp1, temp2);
            float den = (vec1.x * vec2.x) + (vec1.y * vec2.y);
            temp.x /= den;
            temp.y /= den;
            return temp;
        }
        float dist(Vector2D vec)
        {
            float dist_x = this->x - vec.x;
            float dist_y = this->y - vec.y;
            return sqrt(dist_x * dist_x + dist_y * dist_y);
        }
        float dotProduct(Vector2D vec)
        {
            return this->x * vec.x + this->y * vec.y;
        }
        float angleBetween(Vector2D vec)
        {
            if (this->x == 0.0 && this->y == 0.0)
                return 0.0f;
            if (vec.x == 0.0 && vec.y == 0.0)
                return 0.0f;

            float dot = dotProduct(vec);
            float mag1 = magnitude();
            float mag2 = magVector(vec);
            float cosangle = dot / (mag1 * mag2);
            if (cosangle <= -1)
                return M_PI;
            if (cosangle >= 1)
                return 0;
            float angle = acos(cosangle);
            return angle;
        }
        Vector2D copy(Vector2D vec)
        {
            Vector2D temp(vec.x, vec.y);
            return temp;
        }
        //~Vector2D();
};

