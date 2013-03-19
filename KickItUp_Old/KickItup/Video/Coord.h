#ifndef _KICKITUP_COORD_H
#define _KICKITUP_COORD_H

class Coord
{
private:
    short   m_x;
    short   m_y;

public:
    Coord( short x = 0, short y = 0 )   :   m_x( x ), m_y( y )
    {
    }

    Coord( const Coord & rhs )  :   m_x( rhs.m_x ), m_y( rhs.m_y )
    {
    }

    ~Coord(void)
    {
    }

    const Coord &   operator= ( const Coord & rhs )
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        return *this;
    }

    void    setX( const short & x )     {   m_x = x;    }
    short   getX() const                {   return m_x; }
    void    setY( const short & y )     {   m_y = y;    }
    short   getY() const                {   return m_y; }
};

#endif // _KICKITUP_COORD_H
