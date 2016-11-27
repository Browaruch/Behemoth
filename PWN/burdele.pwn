#define FILTERSCRIPT

#include <a_samp>
#include <sscanf2>
#include <streamer>
#include <izcmd>
#include <SAM/FoxForeach>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#define SCRIPT_NAME		"Burdele"

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000A2)	//
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

new blowjobCP,
	blowjobCP2;

public OnFilterScriptInit(){
	blowjobCP = CreateDynamicCP(949.97,-48.24,1001.0,1.0,-1,-1,-1);
	
	blowjobCP2 = CreateDynamicCP(943.52,-42.81,1001.0,1.0,-1,-1,-1);
	
	return 1;
}

forward Blowjob(facet,baba,step);
public Blowjob(facet,baba,step){
	switch(step){
		case 0: {
			TogglePlayerControllable(facet,0);
			TogglePlayerControllable(baba,0);

			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_START_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_START_W",4.1,0,1,1,1,1,1);

			SetTimerEx("Blowjob",1000,false,"ddd",facet,baba,step+1);

			return 1;
		}
		case 1: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_LOOP_P",4.1,1,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_LOOP_W",4.1,1,1,1,1,1,1);
			SetTimerEx("Blowjob",2500+random(3000),false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 2: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_END_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_END_W",4.1,0,1,1,1,1,1);
			SetTimerEx("Blowjob",1000,false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 3: {
			ApplyAnimation(facet,"CARRY","crry_prtial",4.0,0,0,0,0,0);
			ApplyAnimation(baba,"CARRY","crry_prtial",4.0,0,0,0,0,0);
			ClearAnimations(facet);
			ClearAnimations(baba);
			TogglePlayerControllable(facet,1);
			TogglePlayerControllable(baba,1);
			return 1;
		}
	}
	return 1;
}

CMD:zrobloda(playerid,params[]){
	new userid;
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"U¿yj: /zrobloda [ID]");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	}
	Blowjob(userid,playerid,0);
	return 1;
}

public OnPlayerEnterDynamicCP(playerid,checkpointid){
	if(checkpointid == blowjobCP){
		// szukamy czy w CP jest inny gracz tez
		FoxForeach(i,Player){
			if(playerid == i) continue;
			if(IsPlayerInRangeOfPoint(i,1.5,949.97,-48.24,1001.0)){
				burdel_Blowjob(playerid,i,0);
				return 1;
			}
			SendClientMessage(playerid,-1,"[BURDELE] Musisz tu wejsc razem z druga osoba");
			return 1;
		}
	} else if(checkpointid == blowjobCP2){
		// szukamy czy w CP jest inny gracz tez
		FoxForeach(i,Player){
			if(playerid == i) continue;
			if(IsPlayerInRangeOfPoint(i,1.5,943.52,-42.81,1001.0)){
				burdel_Blowjob2(playerid,i,0);
				return 1;
			}
			SendClientMessage(playerid,-1,"[BURDELE] Musisz tu wejsc razem z druga osoba");
			return 1;
		}
	}
	return 0;
}

forward burdel_Blowjob(facet,baba,step);
public burdel_Blowjob(facet,baba,step){
 switch(step){
  case 0: {

    SetPlayerPos(facet, 952.21, -45.5,1001.12);
    SetPlayerPos(baba, 952.21,-46.05,1001.12);

    SetPlayerFacingAngle(facet,180);
    SetPlayerFacingAngle(baba,0);
    TogglePlayerControllable(facet,0);
    TogglePlayerControllable(baba,0);

    ApplyAnimation(facet, "BLOWJOBZ", "BJ_COUCH_START_P", 4.1, 0, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_COUCH_START_W", 4.1, 0, 1, 1, 1, 1, 1);

    SetTimerEx("burdel_Blowjob",1000,false,"ddd",facet,baba,step+1);

    return;
  }
  case 1: {
    ApplyAnimation(facet, "BLOWJOBZ", "BJ_COUCH_LOOP_P", 4.1, 1, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.1, 1, 1, 1, 1, 1, 1);
    SetTimerEx("burdel_Blowjob",2500+random(3000),false,"ddd",facet,baba,step+1);
    return;
  }
  case 2: {
    ApplyAnimation(facet, "BLOWJOBZ", "BJ_COUCH_END_P", 4.1, 0, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_COUCH_END_W", 4.1, 0, 1, 1, 1, 1, 1);
    SetTimerEx("burdel_Blowjob",1000,false,"ddd",facet,baba,step+1);
    return;
  }
  case 3: {
    ApplyAnimation(facet, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(baba, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ClearAnimations(facet);
    ClearAnimations(baba);
    TogglePlayerControllable(facet,1);
    TogglePlayerControllable(baba,1);
    return;
  }
 }
 return;
}

forward burdel_Blowjob2(facet,baba,step);
public burdel_Blowjob2(facet,baba,step){
 switch(step){
  case 0: {

    SetPlayerPos(facet, 945.17, -44.0,1001.12);
    SetPlayerPos(baba, 945.17,-45.0,1001.12);

    SetPlayerFacingAngle(facet,180);
    SetPlayerFacingAngle(baba,0);
    TogglePlayerControllable(facet,0);
    TogglePlayerControllable(baba,0);

    ApplyAnimation(facet, "BLOWJOBZ", "BJ_STAND_START_P", 4.1, 0, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_STAND_START_W", 4.1, 0, 1, 1, 1, 1, 1);

    SetTimerEx("burdel_Blowjob2",1000,false,"ddd",facet,baba,step+1);

    return;
  }
  case 1: {
    SetPlayerPos(facet, 945.17, -44.0,1001.12);
    SetPlayerPos(baba, 945.17,-45.0,1001.12);

    ApplyAnimation(facet, "BLOWJOBZ", "BJ_STAND_LOOP_P", 4.1, 1, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.1, 1, 1, 1, 1, 1, 1);
    SetTimerEx("burdel_Blowjob2",2500+random(3000),false,"ddd",facet,baba,step+1);
    return;
  }
  case 2: {
    ApplyAnimation(facet, "BLOWJOBZ", "BJ_STAND_END_P", 4.1, 0, 1, 1, 1, 1, 1);
    ApplyAnimation(baba, "BLOWJOBZ", "BJ_STAND_END_W", 4.1, 0, 1, 1, 1, 1, 1);
    SetTimerEx("burdel_Blowjob2",1000,false,"ddd",facet,baba,step+1);
    return;
  }
  case 3: {
    ApplyAnimation(facet, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(baba, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ClearAnimations(facet);
    ClearAnimations(baba);
    TogglePlayerControllable(facet,1);
    TogglePlayerControllable(baba,1);
    return;
  }
 }
 return;
}

/*
#define MAX_DICK_SIZE	(30) // dozwolone 5 - 30

stock GetDickSize(playerid){
	new cw;
	CompRotation(ProtVar::pData[playerid][accountID],cw);
	return floatround(floatabs(MAX_DICK_SIZE-(floatsin(cw,degrees)*(MAX_DICK_SIZE-5)+5)));
}


CMD:dick(playerid){
	if(ProtVar::pData[playerid][accountID] == 0) return SendClientMessage(playerid,0xFFFFFFFF,"Musisz posiadaæ konto aby u¿yæ tej komendy ;)");
	new buffer[128], di;
	di = GetDickSize(playerid);
	format(buffer,sizeof buffer,"Twój rozmiar kutasa wynosi %d cm",di);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	return 1;
}
*/
// EOF