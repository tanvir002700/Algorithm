int Direction(const point_int &O, const point_int &A, const point_int &B) //checks rotation
{
        int rotation = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
        if(rotation == 0) return 0;
        return rotation > 0? 1 : -1;
}
bool On_Segment(point_int p, point_int q, point_int r) // q point lies between p and r
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
bool Segment_Intersect(point_int p1, point_int p2, point_int q1, point_int q2)
{
    int d1 = Direction(p1, p2, q1);
    int d2 = Direction(p1, p2, q2);
    int d3 = Direction(q1, q2, p1);
    int d4 = Direction(q1, q2, p2);
    if(d1 != d2 && d3 != d4)return true;
    if(!d1 && On_Segment(p1, q1, p2)) return true;
    if(!d2 && On_Segment(p1, q2, p2)) return true;
    if(!d3 && On_Segment(q1, p1, q2)) return true;
    if(!d4 && On_Segment(q1, p2, q2)) return true;
    return false;
}
