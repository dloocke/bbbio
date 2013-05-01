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

//
// ----------------------------------------------------------- Type Definitions
//

typedef enum _BBBIO_INFO {
	BBBIO_INFO_VALUE,
	BBBIO_INFO_DIRECTION

/*++

Enum. Description:

	This enum. defines the different fields of a pin that can be written to 
	or read from.
	
Member Descriptions:

	*_VALUE - the value field of a pin. This is brightness for LED pins.
	
	*_DIRECTION - the direction of a pin, usually "in" or "out"
	
--*/

} BBBIO_INFO;

typedef struct _BBBIO_PIN {
	unsigned Header;
	unsigned int Number;
	char* Name;
	unsigned int Index;

/*++

Struct Description:

	This struct defines the standard form of a pin on the BeagleBone Black, for
	use with the BBBIO library.
  
Member Descriptions:

	Header - defines which header this pin is on: 0 - P8, 1 - P9
  
	Number - defines which pin number this is on that header
  
	Name - supplies the string name given to this pin in the documentation
  
	Index - supplies the number used to export/unexport this pin

--*/

} BBBIO_PIN;

//
// ------------------------------------------------- Public Function Prototypes
//

//
// ------------------------------------------------- Public Function Prototypes
//

#endif
