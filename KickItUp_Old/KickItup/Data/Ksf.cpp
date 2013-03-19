#include "Ksf.h"
#include <algorithm>
#include <string>

using std::fill;
using std::string;
using string::size_type;

Ksf::Ksf(void)  :   m_madi( 0 ), 
    m_tick( 0 ),
    m_dummy( 0 ),
    m_track( 0 )
{
    fill( &m_bpm[0], &m_bpm[3], 0.0 );
    fill( &m_start[0], &m_start[3], 0 );
    fill( &m_bunki[0], &m_bunki[2], 0 );
}

Ksf::~Ksf(void)
{
}

// read kickitup Step Data from stream.
bool Ksf::ReadFromStrem( istream & is )
{
    fill( &m_start[0], &m_start[3], 0 );
    fill( &m_bpm[0], &m_bpm[3], 0.0 );
    fill( &m_bunki[0], &m_bunki[2], 0 );
    
    char    buf[2048];
    while( is.getline( buf, sizeof(buf) ) ) {
        
        string  strLine( buf );
        if( strLine[0] == '#' ) {
            string  value;

            // TITLE 얻기.
            if( _getValue( strLine, "#TITLE:", value ) ) {
                m_title = value;
            }
            // TICKCOUNT 얻기
            else if( _getValue( strLine, "#TICKCOUNT:", value ) ) {
                m_tick = atoi( value.c_str() );
            }
            // BUNKI 얻기
            else if( _getValue( strLine, "#BUNKI:", value ) ) {
                m_bunki[0] = atoi( value.c_str() );
            }
            // BUNKI2 얻기
            else if( _getValue( strLine, "#BUNKI2:", value ) ) {
                m_bunki[1] = atoi( value.c_str() );
            }
            // BPM 얻기
            else if( _getValue( strLine, "#BPM:", value ) ) {
                m_bpm[0] = atof( value.c_str() );
            }
            // BPM2 얻기
            else if( _getValue( strLine, "#BPM2:", value ) ) {
                m_bpm[0] = atof( value.c_str() );
            }
            // BPM3 얻기
            else if( _getValue( strLine, "#BPM3:", value ) ) {
                m_bpm[0] = atof( value.c_str() );
            }
            // DIFFCULTY 얻기
            else if( _getValue( strLine, "#DIFFCULTY:", value ) ) {
                m_dummy = atoi( value.c_str() );
            }
            // MADI 얻기
            else if( _getValue( strLine, "#MADI:", value ) ) {
                m_madi = atoi( value.c_str() );
            }
            // STARTTIME 얻기
            else if( _getValue( strLine, "#STARTTIME:", value ) ) {
                m_start[0] = atoi( value.c_str() ) * 10;
            }
            // STARTTIME2 얻기
            else if( _getValue( strLine, "#STARTTIME2:", value ) ) {
                m_start[1] = atoi( value.c_str() ) * 10;
            }
            // STARTTIME3 얻기
            else if( _getValue( strLine, "#STARTTIME2:", value ) ) {
                m_start[2] = atoi( value.c_str() ) * 10;
            }
            // STEP 얻기
            else if( strLine.find( "#STEP:" ) != string::npos ) {

                // tick Setting.
                // _addTick();

                // Step 얻기.
                for( int i = 0 ; i < MAX_DATA ; ++i ) {
                    if( !is.getline( buf, sizeof( buf ) ) )
                        break;

                    StepData_t  sd;
                    strncpy( sd.step, buf, 13 );
                    sd.step[13] = 0;
                    m_step.push_back( sd );
                    
                    // Data end.
                    if( strcmp( buf, "2222222222222") == 0 )
                        break;
                }
            } // STEP 얻기
        }
    }
	return true;
}

bool Ksf::_getValue( const string & context, const string & key, string & value )
{
    string::size_type startIdx;
    string::size_type endIdx;

    bool    ret = false;

    // value 얻기.
    startIdx = context.find( key );
    if( startIdx == 0 ) {
        startIdx += key.length();
        endIdx = context.find_last_of( ";" );
        if( startIdx < endIdx && endIdx != string::npos ) {
            value.assign( context.begin()+startIdx, context.begin() + endIdx );
            ret = true;
        }
    }
    return ret;
}

void Ksf::_addTick()
{
    double  bmpcount = 60.0 / m_bpm[0] * 100.0;

    StepData_t  sd;
    fill( &sd.step[0], &sd.step[13], '0' );     // sd.step = "0000000000000";

    for( double  tmpStart = m_start[0] ;  bmpcount < tmpStart ; tmpStart -=  bmpcount ) {
        for( int i = 0 ; i < m_tick ; ++ i ) {
            m_step.push_back( sd );
        }
    }
}
