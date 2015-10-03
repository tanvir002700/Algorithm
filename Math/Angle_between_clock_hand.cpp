double angle(int h, int m)
{
    double hAngle = 0.5D * (h * 60 + m);
    double mAngle = 6 * m;
    double angle = abs(hAngle - mAngle);
    angle = min(angle, 360 - angle);
    return angle;
}
