/*++

File Name:

	BBBIO.c
	
File Description:

	This file contains routines for accessing and updating the IO pins
	on the BeagleBone Black.
	
Author:

	Michael Soliterman (msoliter@berkeley.edu) 30-Apr-2013
	
Environment:

	Ångström Distribution on BeagleBone Black (Revision A52)
	
--*/

//
// ------------------------------------------------------------------- Includes
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "BBBIO.h"
#include "pBBBIO.h"

//
// -------------------------------------------------Global Variable Definitions
//

char CommandBuffer[1024] = "";

//
// ------------------------------------------------ Private Function Prototypes
//

bool
pBBBIOGet (
	BBBIO_PIN Pin,
	BBBIO_INFO Info,
	char* Buffer,
	int Size
	);

bool
pBBBIOSet (
	BBBIO_PIN Pin,
	BBBIO_INFO Info,
	char* Value
	);
	
bool
pBBBIOClaim (
	BBBIO_PIN Pin
	);

bool
pBBBIORelease (
	BBBIO_PIN Pin
	);
	
//
// ------------------------------------------------ Public Function Definitions
//

//
// ----------------------------------------------- Private Function Definitions
//

bool
pBBBIOGet (
	BBBIO_PIN Pin,
	BBBIO_INFO Info,
	char* Buffer,
	int Size
	)
	
/*++

Routine Description:

	This routine will get a string from the pin's file system.
	
Arguments:

	Pin - supplies the pin to access
	
	Info - supplies what to read from the pin
	
	Buffer - supplies a buffer where the read value can be written
	
	Size - supplies the size of the provided buffer

Return Value:

	True if the value was successfully written to the buffer, false otherwise.

--*/

{

	int CharactersRead;
	FILE* ValueFile;
	char ValueFileName[256];
	
	switch (Info) {
		case BBBIO_INFO_VALUE:
			snprintf(ValueFileName,
					 sizeof(ValueFileName),
					 "%s/gpio%d/value",
					 BBBIO_GPIO_DIRECTORY,
					 Pin);
			break;
			
		case BBBIO_INFO_DIRECTION:
			snprintf(ValueFileName,
					 sizeof(ValueFileName),
					 "%s/gpio%d/direction",
					 BBBIO_GPIO_DIRECTORY,
					 Pin);
			break;

		default:
			return false;
	}
			
	if (BBBIO_DEBUG) {
		printf("Opening %s\n", ValueFileName);
	}	
			
	ValueFile = fopen(ValueFileName, "r");
	if (ValueFile != NULL) {
		CharactersRead = getline(&Buffer,
		  	   				     &Size,
			  					 ValueFile);
							   
	    Buffer[CharactersRead - 1] = '\0';
		fclose(ValueFile);	
		return true;
	}
	
	return false;
}

bool
pBBBIOSet (
	BBBIO_PIN Pin,
	BBBIO_INFO Info,
	char* Value
	)
	
/*++

Routine Description:

	This routine will write a string value to a field of the given pin.
	
Arguments:

	Pin - supplies the pin to be written to
	
	Info - supplies which field to write to
	
	Value - supplies the value to write
	
Return Value:

	True if the pin's value was updated successfully, false otherwise.
	
--*/

{

	int LightIndex;
	int Success;
							
	switch (Info) {
		case BBBIO_INFO_VALUE:
			snprintf(CommandBuffer,
					 sizeof(CommandBuffer),
					 "echo %s > %s/gpio%d/value 2> /dev/null",
					 Value,
					 BBBIO_GPIO_DIRECTORY,
					 Pin);
			break;	 
				 
		case BBBIO_INFO_DIRECTION:
			snprintf(CommandBuffer,
					 sizeof(CommandBuffer),
					 "echo %s > %s/gpio%d/direction 2> /dev/null",
					 Value,
					 BBBIO_GPIO_DIRECTORY,
					 Pin);
			break;	 
		
		case BBBIO_INFO_BRIGHTNESS:
		
			//
			// Decode which light we're talking about.
			//
	
			switch (Pin) {
				case USR0:
					LightIndex = 0;
					break;
			
				case USR1:
					LightIndex = 1;
					break;
			
				case USR2:
					LightIndex = 2;
					break;
			
				case USR3:
					LightIndex = 3;
					break;
			
				default:
					return false;
			}
			
			//
			// First, set the LED to listen to us.
			//
		
			snprintf(CommandBuffer,
					 sizeof(CommandBuffer),
					 "echo gpio > %s/beaglebone:green:usr%d/trigger",
					 BBBIO_LED_DIRECTORY,
					 LightIndex);
					 
			if (BBBIO_DEBUG) {
				printf("%s\n", CommandBuffer);
			}
					 
			system(CommandBuffer);
			
			//
			// Now issue the actual command to control brightness.
			//
	
			snprintf(CommandBuffer,
					 sizeof(CommandBuffer),
					 "echo %s > %s/beaglebone:green:usr%d/brightness",
					 Value,
					 BBBIO_LED_DIRECTORY,
					 LightIndex);
			 
			break;
			
		default:
			return false;
	}	  
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}	
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

bool
pBBBIOClaim (
	BBBIO_PIN Pin
	)
	
/*++

Routine Description:

	This routine will export a pin so that this program can control it.
	
Arguments:

	Pin - supplies the pin to be exported
	
Return Value:

	True if the pin was successfully exported, false otherwise.

--*/

{
	
	int Success;
	
	//
	// Build the export command.
	//
	
	snprintf(CommandBuffer, 
			 sizeof(CommandBuffer),
			 "echo %d > %s 2> /dev/null",
			 Pin,
			 BBBIO_GPIO_EXPORT);
	
	//
	// Execute the export command.
	//
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

bool
pBBBIORelease (
	BBBIO_PIN Pin
	)
	
/*++

Routine Description:

	This routine will unexport a pin so that other programs can use it.
	
Arguments:

	Pin - supplies the pin to be unexported
	
Return Value:

	True if the pin was successfully unexported, false otherwise.

--*/

{
	
	int Success;
	
	//
	// Build the unexport command.
	//
	
	snprintf(CommandBuffer, 
			 sizeof(CommandBuffer),
			 "echo %d > %s 2> /dev/null",
			 Pin,
			 BBBIO_GPIO_UNEXPORT);
	
	//
	// Execute the unexport command.
	//
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}	
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

