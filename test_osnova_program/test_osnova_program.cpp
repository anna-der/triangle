#include <iostream>

struct Triangle
{
    double a, b, c;
};

bool check(const Triangle& triangle) 
{
    return triangle.a > 0 && triangle.b > 0 && triangle.c > 0 && //only real triangles. 
        triangle.a + triangle.b > triangle.c && 
        triangle.a + triangle.c > triangle.b &&
        triangle.b + triangle.c > triangle.a;
}
double p(const Triangle& triangle)
{
    double p = (triangle.a + triangle.b + triangle.c) / 2;
    return p;
}

double square(const Triangle& triangle)
{
    double sum = p(triangle);
    return std::sqrt(sum * (sum - triangle.a) * (sum - triangle.b) * (sum - triangle.c));
}

void compare(const Triangle& triangle1, const Triangle& triangle2, const Triangle& triangle3)
{
    double squares[] = { square(triangle1), square(triangle2), square(triangle3) };
    double maxSquare = squares[0];
    for (int i = 1; i < 3; i++) 
    {
        if (squares[i] > maxSquare) maxSquare = squares[i];
    }
    std::cout << "Triangle";
    for (int i = 0; i < 3; i++) 
    {
        if (squares[i] == maxSquare) std::cout << " " << (i + 1);
    }
    std::cout << " has the largest square.\n";
}

int main()
{
    std::cout << "Triangles\n";
    Triangle triangle1, triangle2, triangle3;
    Triangle* triangles[] = { &triangle1, &triangle2, &triangle3 };

    for (int i = 0; i < 3; ++i) 
    {
        std::cout << "Enter the sides of the " << (i + 1) << " triangle\n";
        std::cout << "A" << (i + 1) << "B" << (i + 1) << " = ";
        std::cin >> triangles[i]->a;
        std::cout << "B" << (i + 1) << "C" << (i + 1) << " = ";
        std::cin >> triangles[i]->b;
        std::cout << "C" << (i + 1) << "A" << (i + 1) << " = ";
        std::cin >> triangles[i]->c;

        if (!check(*triangles[i])) 
        {
            std::cout << "Mistake. Try again!!!\n";
            return 1;
        }
        double s = p(*triangles[i]);
        double a = square(*triangles[i]);

        std::cout << "Semi-perimeter: " << s << ", Square: " << a << "\n\n"; //it can be delete. it is for checking.
    }
    compare(triangle1, triangle2, triangle3);
    return 0;
}

//test1
//A1B1 = 4
//B1C1 = 2
//C1A1 = 3
//A2B2 = 6
//B2C2 = 3
//C2A2 = 4
//A3B3 = 7
//B3C3 = 4
//C3A3 = 5
//Triangle 3 has the largest square.

//test2
//A1B1 = 5
//B1C1 = 4
//C1A1 = 9
//Mistake.Try again!!! - because square = 0, it is not the real triangle. But if we exchange > to >= in bool check, in this case it will be true. but it is not correct for program.

//test3
//A1B1 = -8
//B1C1 = 9
//C1A1 = 6
//Mistake.Try again!!!

//test4
//A1B1 = 5
//B1C1 = 5
//C1A1 = 5
//A2B2 = 9
//B2C2 = 9
//C2A2 = 9
//A3B3 = 8
//B3C3 = 8
//C3A3 = 8
//Triangle 2 has the largest square.

//test5
//A1B1 = 100
//B1C1 = 150
//C1A1 = 200
//A2B2 = 800
//B2C2 = 600
//C2A2 = 500
//A3B3 = 300
//B3C3 = 200
//C3A3 = 250
//Triangle 2 has the largest square.

//test6 
//A1B1 = 1
//B1C1 = 1
//C1A1 = 1.999999
//A2B2 = 7.4444
//B2C2 = 8.437
//C2A2 = 6.9978
//A3B3 = 9.8886
//B3C3 = 5.3689
//C3A3 = 7.9766
//Triangle 2 has the largest square.

//test7
//A1B1 = 7
//B1C1 = 8
//C1A1 = 9
//A2B2 = 6.9
//B2C2 = 8.1
//C2A2 = 9
//A3B3 = 7.1
//B3C3 = 8
//C3A3 = 8.9
//Triangle 3 has the largest square.

//test8
//A1B1 = 8
//B1C1 = 8
//C1A1 = 8
//A2B2 = 8
//B2C2 = 8
//C2A2 = 8
//A3B3 = 8
//B3C3 = 8
//C3A3 = 8
//Triangle 1 2 3 has the largest square.

//test9
//A1B1 = 6
//B1C1 = 6
//C1A1 = 6
//A2B2 = 6
//B2C2 = 6
//C2A2 = 6
//A3B3 = 6
//B3C3 = 6
//C3A3 = 5.9999999999
//Triangle 1 2 has the largest square.