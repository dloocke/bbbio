/*++

Header Name:

	pBBBIO.c
	
Header Description:

	This file contains private definitions and macros for the BBBIO source
	files.
	
Author:

	Michael Soliterman (msoliter@berkeley.edu) 30-Apr-2013
	
Environment:

	Ångström Distribution on BeagleBone Black (Revision A52)
	
--*/

//
// ------------------------------------------------------------------- Includes
//

//
// ---------------------------------------------------------------- Definitions
//

#define BBBIO_DEBUG				true
#define BBBIO_SUCCESS			0

//
// Some handy locations for manipulating the GPIO pins.
//

#define BBBIO_GPIO_DIRECTORY 	"/sys/class/gpio"
#define BBBIO_GPIO_EXPORT 		"/sys/class/gpio/export"
#define BBBIO_GPIO_UNEXPORT 	"/sys/class/gpio/unexport"

//
// ----------------------------------------------------------- Type Definitions
//

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

