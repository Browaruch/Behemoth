#define FILTERSCRIPT

#include <a_samp>
#include <a_actor>
#include <izcmd>
#include <sscanf2>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#define SCRIPT_NAME		"Dupeczki"

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000AE)	//
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

new Actor[30];

CMD:tancerki(playerid,params[]){
	if(!IsPlayerAdmin(playerid)) return 0;
	new loop, lib_name[32], anim_name[32];
	if(sscanf(params,"ds[32] s[32]",loop,lib_name,anim_name)) return SendClientMessage(playerid,0xFFFFFFFF,"/tancerki <loop 1/0> <lib name> <anim name>");
	for(new i = 0; i < 30; i++){
		ApplyActorAnimation(Actor[i],lib_name,anim_name,4.1,loop,1,1,1,1);
	}
	return 1;
}

CMD:tancerki2(playerid,params[]){
	if(!IsPlayerAdmin(playerid)) return 0;
	for(new i = 0; i < 30; i++){
		switch(strval(params)){
			case -1: ApplyActorAnimation(Actor[i],"DANCING","DAN_Loop_A",4.1,1,0,0,0,0);
			case 1: ApplyActorAnimation(Actor[i],"STRIP","PLY_CASH",4.1,1,1,1,1,1);
			case 2: ApplyActorAnimation(Actor[i],"STRIP","PUN_CASH",4.1,1,1,1,1,1);
			case 3: ApplyActorAnimation(Actor[i],"STRIP","PUN_HOLLER",4.1,1,1,1,1,1);
			case 4: ApplyActorAnimation(Actor[i],"STRIP","PUN_LOOP",4.1,1,1,1,1,1);
			case 5: ApplyActorAnimation(Actor[i],"STRIP","strip_A",4.1,1,1,1,1,1);
			case 6: ApplyActorAnimation(Actor[i],"STRIP","strip_B",4.1,1,1,1,1,1);
			case 7: ApplyActorAnimation(Actor[i],"STRIP","strip_C",4.1,1,1,1,1,1);
			case 8: ApplyActorAnimation(Actor[i],"STRIP","strip_D",4.1,1,1,1,1,1);
			case 9: ApplyActorAnimation(Actor[i],"STRIP","strip_E",4.1,1,1,1,1,1);
			case 10: ApplyActorAnimation(Actor[i],"STRIP","strip_F",4.1,1,1,1,1,1);
			case 11: ApplyActorAnimation(Actor[i],"STRIP","strip_G",4.1,1,1,1,1,1);
			case 12: ApplyActorAnimation(Actor[i],"STRIP","STR_A2B",4.1,1,1,1,1,1);
			case 13: ApplyActorAnimation(Actor[i],"STRIP","STR_B2A",4.1,1,1,1,1,1);
			case 14: ApplyActorAnimation(Actor[i],"STRIP","STR_B2C",4.1,1,1,1,1,1);
			case 15: ApplyActorAnimation(Actor[i],"STRIP","STR_C1",4.1,1,1,1,1,1);
			case 16: ApplyActorAnimation(Actor[i],"STRIP","STR_C2",4.1,1,1,1,1,1);
			case 17: ApplyActorAnimation(Actor[i],"STRIP","STR_C2B",4.1,1,1,1,1,1);
			case 18: ApplyActorAnimation(Actor[i],"STRIP","STR_Loop_A",4.1,1,1,1,1,1);
			case 19: ApplyActorAnimation(Actor[i],"STRIP","STR_Loop_B",4.1,1,1,1,1,1);
			case 20: ApplyActorAnimation(Actor[i],"STRIP","STR_Loop_C",4.1,1,1,1,1,1);
			case 21: ApplyActorAnimation(Actor[i],"BLOWJOBZ","BJ_STAND_LOOP_W",4.1,1,1,1,1,1);
			case 22: ApplyActorAnimation(Actor[i],"BLOWJOBZ","BJ_COUCH_LOOP_W",4.1,1,1,1,1,1);
			case 23: ApplyActorAnimation(Actor[i],"BLOWJOBZ","BJ_STAND_END_W",4.1,1,1,1,1,1);
			case 24: ApplyActorAnimation(Actor[i],"BLOWJOBZ","BJ_COUCH_END_W",4.1,1,1,1,1,1);
		}
	}
	return 1;
}

public OnFilterScriptInit(){
	SendClientMessageToAll(0xFF0000FF,"[IMPORTANT] Trwa ubieranie tancerek...");
	
	Actor[1] = CreateActor(75,50.0000,1519.0000,15.2205,90.0000);
	Actor[2] = CreateActor(85,50.0000,1521.0000,15.2205,90.0000);
	Actor[3] = CreateActor(87,50.0000,1523.0000,15.2205,90.0000);
	Actor[4] = CreateActor(152,50.0000,1525.0000,15.2205,90.0000);
	Actor[5] = CreateActor(207,50.0000,1527.0000,15.2205,90.0000);
	Actor[6] = CreateActor(237,50.0000,1529.0000,15.2205,90.0000);
	Actor[7] = CreateActor(238,50.0000,1531.0000,15.2205,90.0000);
	Actor[8] = CreateActor(244,50.0000,1533.0000,15.2205,90.0000);
	Actor[9] = CreateActor(63,50.0000,1535.0000,15.2205,90.0000);
	Actor[0] = CreateActor(64,50.0000,1537.0000,15.2205,90.0000);
	
	Actor[11] = CreateActor(245,52.0000,1520.0000,15.2205,90.0000);
	Actor[12] = CreateActor(246,52.0000,1522.0000,15.2205,90.0000);
	Actor[13] = CreateActor(178,52.0000,1524.0000,15.2205,90.0000);
	Actor[14] = CreateActor(256,52.0000,1526.0000,15.2205,90.0000);
	Actor[15] = CreateActor(257,52.0000,1528.0000,15.2205,90.0000);
	Actor[16] = CreateActor(90,52.0000,1530.0000,15.2205,90.0000);
	Actor[17] = CreateActor(92,52.0000,1532.0000,15.2205,90.0000);
	Actor[18] = CreateActor(40,52.0000,1534.0000,15.2205,90.0000);
	Actor[19] = CreateActor(138,52.0000,1536.0000,15.2205,90.0000);
	Actor[10] = CreateActor(243,52.0000,1538.0000,15.2205,90.0000);
	
	Actor[21] = CreateActor(12,54.0000,1519.0000,15.2205,90.0000);
	Actor[22] = CreateActor(13,54.0000,1521.0000,15.2205,90.0000);
	Actor[23] = CreateActor(216,54.0000,1523.0000,15.2205,90.0000);
	Actor[24] = CreateActor(91,54.0000,1525.0000,15.2205,90.0000);
	Actor[25] = CreateActor(56,54.0000,1527.0000,15.2205,90.0000);
	Actor[26] = CreateActor(151,54.0000,1529.0000,15.2205,90.0000);
	Actor[27] = CreateActor(145,54.0000,1531.0000,15.2205,90.0000);
	Actor[28] = CreateActor(140,54.0000,1533.0000,15.2205,90.0000);
	Actor[29] = CreateActor(139,54.0000,1535.0000,15.2205,90.0000);
	Actor[20] = CreateActor(11,54.0000,1537.0000,15.2205,90.0000);
	
	for(new i = 0; i < 30; i++){
		ApplyActorAnimation(Actor[i],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	}
	
	/*
	ApplyActorAnimation(Actor[0],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[1],"DANCING","dnce_M_b",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[2],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[3],"DANCING","dnce_M_d",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[4],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[5],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[6],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[7],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[8],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[9],"DANCING","dnce_M_b",4.0,1,0,0,0,0);
	
	ApplyActorAnimation(Actor[10],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[11],"DANCING","dnce_M_b",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[12],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[13],"DANCING","dnce_M_d",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[14],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[15],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[16],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[17],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[18],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[19],"DANCING","dnce_M_b",4.0,1,0,0,0,0);	
	
	ApplyActorAnimation(Actor[20],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[21],"DANCING","dnce_M_b",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[22],"DANCING","dnce_M_c",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[23],"DANCING","dnce_M_d",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[24],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[25],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[26],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[27],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[28],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(Actor[29],"DANCING","dnce_M_b",4.0,1,0,0,0,0);	
	*/
	
	return 1;
}

public OnFilterScriptExit(){
	for(new i = 0; i < 30; i++){
		DestroyActor(Actor[i]);
	}
	return 1;
}

public OnPlayerSpawn(playerid){
	
	
	
	return 1;
}
