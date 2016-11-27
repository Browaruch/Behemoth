#define FILTERSCRIPT
#define SCRIPT_NAME		"lampion"
#include <a_samp>
#include <streamer>
#include <izcmd>
#include <SAM/StreamerFunction>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000A1)	//
#define CALL_CHANEL_ID_OUTPUT		(0x000000FF)	//Game Mode
#define CALL_CHANEL_ID_BROADCAST	(0xFFFFFFFF)	//Kana³ rozg³oszeniowy

public OnScriptCall(playerid, chanel, errorlevel, data[]){
	if(chanel == CALL_CHANEL_ID_INPUT || chanel == CALL_CHANEL_ID_BROADCAST){
		switch(errorlevel){
			case 0xFF: { //Wysy³a czas aktywnoœci skryptu
				new buffer[32];
				format(buffer,sizeof buffer,"%s:%d",SCRIPT_NAME,GetFilterScriptActiveTime());
				CallToAllScript(playerid, CALL_CHANEL_ID_OUTPUT, 0xFE, buffer);
			}
		}
	}
	return 1;
}

#define LAMPION_ODLEGLOSC_Z 300
#define LAMPION_ODLEGLOSC_X 525
#define LAMPION_ODLEGLOSC_Y 925
#define LAMPION_OBIEKT  3534
#define LAMPION_CZAS 10000
#define LAMPION_CZAS2 600000

new lampion_lu[MAX_PLAYERS];

forward lampion_usun(obiekt);

CMD:lampion(playerid){
	lampion_pusc(playerid);
	return 1;
}

lampion_pusc(playerid){
	if(GetTickCount()-lampion_lu[playerid]<LAMPION_CZAS){
		return SendClientMessage(playerid,-1,"Lampiony mozesz puszczac co 10 sekund!");
	} else {
		lampion_lu[playerid]=GetTickCount();
	}

	new Float:P[4];
	GetPlayerPos(playerid,P[0],P[1],P[2]);
	GetPlayerFacingAngle(playerid,P[3]);

	new obiekt=CreateDynamicObject(LAMPION_OBIEKT, P[0],P[1]+1.2,P[2]+2.0,0,0,0,0,GetPlayerInterior(playerid),-1,200);

	P[0]+=(LAMPION_ODLEGLOSC_X*floatsin(-P[3],degrees));
	P[1]+=(LAMPION_ODLEGLOSC_Y*floatcos(-P[3],degrees));
	P[2]+=LAMPION_ODLEGLOSC_Z;
	//P[2]=P[2]-2.8;

	MoveDynamicObject(obiekt, P[0],P[1],P[2], 3,0,0,0);

	Streamer_Update(playerid);

	SetTimerEx("lampion_usun", LAMPION_CZAS2, false, "i", obiekt);

	return 1;
}

public lampion_usun(obiekt){
	DestroyDynamicObject(obiekt);
	return 1;
}

public OnFilterScriptInit(){
	
	return 1;
}

// EOF