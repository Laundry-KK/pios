/*
*  ckernel.c
*/
void kmain(void)
{
	const char *str = "PiKern V1.1 Beta";
	char *vidptr = (char*)0xb8000; 	//S needs to help connect this to the colortable in colortable.md
	unsigned int i = 0;
	unsigned int j = 0;

	
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	/* PiVID Module */
	while(str[j] != '\0') {
		/* ASCII defined */
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}
