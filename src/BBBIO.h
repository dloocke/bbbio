/*++

Header Name:

	BBBIO.c
	
Header Description:

	This file contains the public interface for applications to do IO
	with the BeagleBone Black pins.
	
Author:

	Michael Soliterman (msoliter@berkeley.edu) 30-Apr-2013
	
Environment:

	Ångström Distribution on BeagleBone Black (Revision A52)
	
--*/

#ifndef _BBBIO_H_
#define _BBBIO_H_

//
// ------------------------------------------------------------------- Includes
//

//
// ---------------------------------------------------------------- Definitions
//

#define USR0 (1*32 + 21)
#define USR1 (2*32 + 22)
#define USR2 (2*32 + 23)
#define USR3 (2*32 + 24)

//
// ----------------------------------------------------------- Type Definitions
//

typedef enum _BBBIO_INFO {
	BBBIO_INFO_VALUE,
	BBBIO_INFO_DIRECTION,
	BBBIO_INFO_BRIGHTNESS

/*++

Enum. Description:

	This enum. defines the different fields of a pin that can be written to 
	or read from.
	
Member Descriptions:

	*_VALUE - the value field of a pin
	
	*_DIRECTION - the direction of a pin, usually "in" or "out"
	
	*_BRIGHTNESS - the brightness of an LED pin (doesn't do anything otherwise)
	
--*/

} BBBIO_INFO;

//
// Pins are defined by their indexing in the file system - so, just an integer.
//

typedef unsigned int BBBIO_PIN;

//
// ------------------------------------------------- Public Function Prototypes
//

//
// ------------------------------------------------- Public Function Prototypes
//

#endif
