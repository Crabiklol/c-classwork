//1
Vector2D operator+(const Vector2D& v)
{
    return Vector2D(x + v.x, y + v.y);
}

//2
bool operator==(const Student& s)
{
    return name == s.name && age == s.age;
}

//3
friend ostream& operator<<(ostream& out, const Point& p)
{
    out << "Point: " << p.x << ", " << p.y;
    return out;
}

//4
Counter operator++()
{
    value++;
    return *this;
}

//5
Money operator+(const Money& m)
{
    return Money(amount + m.amount);
}

Money operator-(const Money& m)
{
    return Money(amount - m.amount);
}

bool operator==(const Money& m)
{
    return amount == m.amount;
}
