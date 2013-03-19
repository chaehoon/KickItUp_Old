#ifndef _KICKITUP_DIM_H
#define _KICKITUP_DIM_H

class Dim
{
private:
    short   m_w;        // Æø
    short   m_h;        // ³ôÀÌ

public:
    Dim( short w = 0, short h = 0 )   :   m_w( w ), m_h( h )
    {
    }

    Dim( const Dim & rhs )  :   m_w( rhs.m_w ), m_h( rhs.m_h )
    {
    }

    ~Dim(void)
    {
    }

    const Dim &   operator= ( const Dim & rhs )
    {
        m_w = rhs.m_w;
        m_h = rhs.m_h;
    }

    void    setW( const short & w )     {   m_w = w;    }
    short   getW() const                {   return m_w; }
    void    setH( const short & h )     {   m_h = h;    }
    short   getH() const                {   return m_h; }
};

#endif // _KICKITUP_DIM_H
