POINT rotate_point(POINT c,float angle,POINT p)
{
        float s = sin(angle);
        float c = cos(angle);

     // translate point back to origin:
       p.x -= c.x;
       p.y -= c.y;

     // rotate point
       float xnew = p.x * c - p.y * s;
       float ynew = p.x * s + p.y * c;

  // translate point back:
       p.x = xnew + c.x;
       p.y = ynew + c.y;
       return p;
}
