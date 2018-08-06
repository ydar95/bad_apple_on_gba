#include "bad_apple_buf.c"
#include <GsGBA.h>
#include <GsText.h>
static void queryKey();
const IntrFuncp IntrTable[14]=
{
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy
};



const unsigned short master_Palette[256] = {0x0000, 0xFFFF, 0};

unsigned short buffer[240*160]={0};

int display( u16* vram ,const u16* buf ,int index ){
	int N=buf[index];
	u32 color=0x00000000;			//黑色开始
	int i;
	u16* display_buf = vram;
	int j;
	index++;
	for(i=0;i<N;i++){
		if(buf[index]==0){
			for(j=0;j<buf[index];j++) {
				*display_buf=color;
				display_buf++;
			}
		}else{
			DmaClear(2 ,color ,display_buf,buf[index]*2,32);
			DmaWait(2);
			display_buf+=buf[index];
		}
		if(color==0x00000000)
			color=0xFFFFFFFF;
		else
			color=0x00000000;
		index++;
	}
	//DmaArrayCopy(2,buffer,vram,32);
	//DmaClear(2 ,color ,display_buf,buf[index]*sizeof(u16),16);
	//DmaWait(2);
	return index;
}

int AgbMain()
{

	u16 timer;					
	int index=0;

	GsSetMode( MODE_3 );

	while(1)								
	{

	if(timer%20==0)						
		queryKey();
	
	if(timer%2000==0){
		index=display((u16*)(0x6000000),buf,index);
		if(index==1162074)	//loop
			index=0;
	}


	timer++;					
	if(timer>65535)timer=0;				
	}

	return 0;
}

void queryKey()
{
    KeyRead();						//??????


  	if (Cont & U_KEY);
	if (Cont & D_KEY);
	if (Cont & R_KEY);
	if (Cont & L_KEY);
	if ( Cont & R_BUTTON );
	if ( Cont & L_BUTTON );
	
}
