/*detect.c*/
/*This piece of code determines if the PC has any parallel adapter*/
/*If yes, it finds out and prints the addresses of the DATA, CONTROL */
/*and the STATUS ports*/

#include <stdio.h>
#include <dos.h>

main()
{
	int dport, cport, sport, select, offset;
	clrscr(); /*clear screen*/
	printf("\tProgram to detect the parallel printer adapter.\n");
	printf("Enter 1, 2 or 3 to detect LPT1, LPT2 or LPT3 respectively.\n\n");

	/*wait for a keystroke*/
	select=getch();

	/*loop indefinitely if the key pressed is not '1', '2' or '3'*/
	while ( (select != '1') && (select != '2') && (select != '3') )
	{
		printf("Invalid number. Enter 1, 2 or 3\n");
		select=getch();
	}
	
	switch(select)
	{
	case '1':
		offset=0x08;
		break;
	case '2':
		offset=0x0a;
			break;
	case '3':
		offset=0x0c;
		break;
	default:
		break;
	}

	/*now look into BIOS area to determine the address of the particular*/
	/*parallel adapter*/

	dport=peek(0x40, offset);
	
	/*If the address is zero, means that particular parallel adapter*/
	/*is not present. No point in continuing. Abort the code here*/
	if (dport == 0)
	{
		printf("Sorry, On this machine LPT%d does not exist\n", select-'0');
		exit(0);
	}
	/*else print the port addresses of the DATA, STATUS and CONTROL ports*/
	printf("\nLPT%d detected!\n", select -'0');
	printf("DATA port is %x\n", dport);
	printf("STATUS port is %x\n", dport+1);
	printf("CONTROL port is %x\n", dport+2)
}