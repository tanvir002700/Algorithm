cumulative sum:

S(x,y,z)=value(x,y,z) + S(x-1,y,z) + S(x,y-1,z)+S(x,y,z-1)-S(x-1,y-1,z)-S(x,y-1,z-1)-S(x-1,y,z-1)
+S(x-1,y-1,z-1)

Query:
S([x1,y1,z1] to [x2,y2,z2] )=S(x2,y2,z2)+S(x1,y1,z2)+S(x1,y2,z1)+S(x1,y1,z1)-S(x2,y2,z1)-S(x2,y1,z2)-S(x1,y2,z2)
-S(x1,y1,z1)
