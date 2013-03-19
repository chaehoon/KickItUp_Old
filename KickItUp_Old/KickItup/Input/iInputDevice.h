#ifndef _KICKITUP_IINPUTDEVICE_H
#define _KICKITUP_IINPUTDEVICE_H

/// @brief	Inputdevice interface
class iInputDevice
{
public:
	enum	eKind {
		Axis,		///< 마우스 포인터 위치
		Button,		///< 마우스 버튼
		KeyState,	///< 키상태.
		BufState,	///< 입력 버퍼.
	};

	enum	eAxis	{
		X,			///< X 축.
		Y,			///< Y 축.
		Z,			///< Z 축.
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