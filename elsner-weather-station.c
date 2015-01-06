#define BUFF_SIZE 40

char *substring(char *string, int position, int length) 
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
 
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }
 
   for (c = 0 ; c < position -1 ; c++) 
      string++; 
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *string;      
      string++;   
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}

float substringToFloat(char *string, int position, int length) {
	char *pointer;
	float value;

	pointer = substring(string,position,length);
	value = atof(pointer);
	free(pointer);
	
	return value;
}


STREAM* pRs485Stream = stream_create("/dev/tty/Elsner Weather Station",1,0);// create rs232 stream
char szBuffer[BUFF_SIZE];
int nCnt;


float temperature,sunSouth, sunEast, sunWest, daylight, windspeed, dawn, rain;


while(1)
    {
    nCnt = stream_read(pRs485Stream,szBuffer,BUFF_SIZE,100);    // read stream
	if(nCnt != 40) {
		continue;
		printf("Not enough bytes received");
	}
	if(szBuffer[0] != 'W') {
		printf("Invalid start byte");
	}

	temperature = substringToFloat(szBuffer,2,5);
	setoutput(0,temperature);

	sunSouth = substringToFloat(szBuffer,7,2);
	setoutput(1,sunSouth);

	sunWest = substringToFloat(szBuffer,9,2);
	setoutput(2,sunWest);

	sunEast = substringToFloat(szBuffer,11,2);
	setoutput(3,sunEast);
 
	daylight = substringToFloat(szBuffer,14,3);
	setoutput(4,daylight);
 
	if(szBuffer[12] == 'J') {
		dawn = 1;
	} else {
		dawn = 0;
	}
	setoutput(5, dawn);
	
	windspeed = substringToFloat(szBuffer,17,4);
	setoutput(6,windspeed * 3.6); // m/s -> km/h

	if(szBuffer[20] == 'J') {
		rain = 1;
	} else {
		rain = 0;
	}
	setoutput(7, rain);
	
    sleep(1000);
}
