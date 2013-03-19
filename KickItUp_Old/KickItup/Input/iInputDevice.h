#ifndef _KICKITUP_IINPUTDEVICE_H
#define _KICKITUP_IINPUTDEVICE_H

/// @brief	Inputdevice interface
class iInputDevice
{
public:
	enum	eKind {
		Axis,		///< ���콺 ������ ��ġ
		Button,		///< ���콺 ��ư
		KeyState,	///< Ű����.
		BufState,	///< �Է� ����.
	};

	enum	eAxis	{
		X,			///< X ��.
		Y,			///< Y ��.
		Z,			///< Z ��.
	};

	union	uKey {
	public:
		eAxis	axis;
		int		key;

	public:
		uKey( const int k )	:	key( k )	{}
		uKey( const eAxis a):	axis( a )	{}
	};

	virtual			~iInputDevice(void)	{}
	virtual void	Reset() {}
	virtual void	Update( unsigned long delta ) {}
	virtual int		GetState( const eKind kind, const uKey axis )	{	return 0;	}
};

#endif // _KICKITUP_IINPUTDEVICE_H