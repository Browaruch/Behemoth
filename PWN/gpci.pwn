#define FILTERSCRIPT

#include <a_samp>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

new invalid_gpci[][] = {
	"A49CE949FA4808DED4E8DE94E5C9CD0D898E9ECD"
};

#define SCRIPT_NAME		"GPCI"

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000AF)	//
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

public OnFilterScriptInit(){

	return 1;
}

/*
public OnPlayerConnect(playerid){
	if(IsPlayerNPC(playerid)) return 1;
	new serial[50];
	gpci(playerid,serial,sizeof(serial));
	
	for(new i = 0, j = sizeof(invalid_gpci); i < j; i++){
		if(!strcmp(serial,invalid_gpci[i],true)){
			BanEx(playerid,"[HD] GPCI Ban");
		}
	}
	
	return 1;
}
*/

#pragma unused invalid_gpci
