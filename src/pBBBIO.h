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

//
// ------------------------------------------------- Public Function Prototypes
//

