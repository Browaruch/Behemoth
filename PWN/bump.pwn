// This is a comment
// uncomment the line below if you want to write a filterscript
#define FILTERSCRIPT

#include <a_samp>
#include <a_actor>
#include <sscanf2>
#include <streamer>
#include <izcmd>
#define DISABLE_3D_TRYG_INIT
#include <SAM/3DTryg>
#include <SAM/StreamerFunction>
#include <SAM/ATM>
#include <SAM/Logs>

#define SCRIPT_NAME		"Bumper"

#include <security/ScriptChecker>

#if !defined _YSF_included
	stock bool:IsPlayerSpawned(playerid){
		new pstate=GetPlayerState(playerid);
		if(pstate != 1 && pstate != 2 && pstate != 3) return false;
		return true;
	}
#endif

CMD:test(playerid,params[]){
	for(new i = 99; i <= 101; i++){
		switch(strval(params)){
			case 1: ApplyAnimation(i,"STRIP","PLY_CASH",4.1,1,1,1,1,1);
			case 2: ApplyAnimation(i,"STRIP","PUN_CASH",4.1,1,1,1,1,1);
			case 3: ApplyAnimation(i,"STRIP","PUN_HOLLER",4.1,1,1,1,1,1);
			case 4: ApplyAnimation(i,"STRIP","PUN_LOOP",4.1,1,1,1,1,1);
			case 5: ApplyAnimation(i,"STRIP","strip_A",4.1,1,1,1,1,1);
			case 6: ApplyAnimation(i,"STRIP","strip_B",4.1,1,1,1,1,1);
			case 7: ApplyAnimation(i,"STRIP","strip_C",4.1,1,1,1,1,1);
			case 8: ApplyAnimation(i,"STRIP","strip_D",4.1,1,1,1,1,1);
			case 9: ApplyAnimation(i,"STRIP","strip_E",4.1,1,1,1,1,1);
			case 10: ApplyAnimation(i,"STRIP","strip_F",4.1,1,1,1,1,1);
			case 11: ApplyAnimation(i,"STRIP","strip_G",4.1,1,1,1,1,1);
			case 12: ApplyAnimation(i,"STRIP","STR_A2B",4.1,1,1,1,1,1);
			case 13: ApplyAnimation(i,"STRIP","STR_B2A",4.1,1,1,1,1,1);
			case 14: ApplyAnimation(i,"STRIP","STR_B2C",4.1,1,1,1,1,1);
			case 15: ApplyAnimation(i,"STRIP","STR_C1",4.1,1,1,1,1,1);
			case 16: ApplyAnimation(i,"STRIP","STR_C2",4.1,1,1,1,1,1);
			case 17: ApplyAnimation(i,"STRIP","STR_C2B",4.1,1,1,1,1,1);
			case 18: ApplyAnimation(i,"STRIP","STR_Loop_A",4.1,1,1,1,1,1);
			case 19: ApplyAnimation(i,"STRIP","STR_Loop_B",4.1,1,1,1,1,1);
			case 20: ApplyAnimation(i,"STRIP","STR_Loop_C",4.1,1,1,1,1,1);
			default: ClearAnimations(i,0);
		}
	}
	return 1;
}

CMD:test2(playerid,params[]){
	ApplyAnimation(strval(params),"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	return 1;
}

CMD:test3(playerid,params[]){
	ApplyAnimation(strval(params),"STRIP","STR_Loop_C",4.0,1,0,0,0,0);
	return 1;
}

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000AA)	//
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

stock CreateActorEx(name[],color,modelid,Float:x,Float:y,Float:z,Float:angle,Float:set_z=1.0){
	CreateDynamic3DTextLabel(name,color,x,y,z+set_z,30.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0);
	return CreateActor(modelid,x,y,z,angle);
}

CMD:tube(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	new Float:x,Float:y,Float:z,
		Float:rx,Float:ry,Float:rz,
		buffer[256];
	GetPlayerPos(playerid,x,y,z);
	GetVehicleRotation(GetPlayerVehicleID(playerid),rx,ry,rz);
	CreateDynamicObject(18814,x,y,z,CompRotationFloat(rx+90.0),ry,rz);
	format(buffer,sizeof buffer,"CreateDynamicObject(18814,%f,%f,%f,%f,%f,%f);",x,y,z,CompRotationFloat(rx+90.0),ry,rz);
	WriteLog(buffer,"Tube.txt");
	return 1;
}

/*
CMD:event(playerid){
	SetPlayerPos(playerid,-36.5669,1526.0662,12.9172);
	SetPlayerFacingAngle(playerid,270.0000);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}
*/

CMD:cowbig(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	SetPlayerAttachedObject(playerid,9,16442,1, 15.0,0.0,0.0, 0.0,90.0,90.0, 10.0,10.0,10.0);
	return 1;
}

CMD:sharkbig(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	SetPlayerAttachedObject(playerid,9,1608,1, 0.0,0.0,0.0, 0.0,90.0,0.0, 10.0,10.0,10.0);
	return 1;
}

CMD:cow(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	SetPlayerAttachedObject(playerid,9,16442,1, 0.0,0.0,0.0, 0.0,90.0,90.0,1.0,1.0,1.0);
	return 1;
}

public OnPlayerConnect(playerid){

	return 1;
}


new tmpobj[10];

public OnFilterScriptInit(){

	for(new i = 0; i < 1000; i++){
		CreateDynamicObject(18814,0.000000,0.000000,0.000000+(i*50.0),0.000000,0.000000,0.000000,1,.streamdistance=500.0,.drawdistance=500.0);
	}
	
	/*
	CreateDynamicObject(18814,57.880420,-1018.104125,21.976413,89.288665,0.000000,89.288558);
	CreateDynamicObject(18814,30.483766,-1018.000000,21.420154,89.392822,0.000000,89.999618);
	CreateDynamicObject(18814,-2.724406,-1017.943176,21.315519,89.378204,359.999908,89.376693);
	CreateDynamicObject(18814,-34.279418,-1018.077941,20.643468,87.927276,359.999969,89.754875);
	CreateDynamicObject(18814,-64.727180,-1018.000000,18.872041,84.993835,0.000000,90.000000);
	CreateDynamicObject(18814,-93.952735,-1018.146118,15.404385,82.483795,0.000012,91.865638);
	CreateDynamicObject(18814,-123.792205,-1020.872192,12.478310,86.717224,359.999969,99.384216);
	CreateDynamicObject(18814,-154.949035,-1027.837646,11.695677,90.575393,0.000020,106.053031);
	CreateDynamicObject(18814,-183.440368,-1037.769775,12.575997,92.635887,359.999969,112.199279);
	CreateDynamicObject(18814,-211.173004,-1051.426025,14.767663,94.724304,359.999969,119.563209);
	CreateDynamicObject(18814,-235.504791,-1068.111450,17.709115,96.235771,0.000021,129.320816);
	CreateDynamicObject(18814,-254.009948,-1087.685058,21.128850,97.403190,0.000041,142.974731);
	CreateDynamicObject(18814,-270.826110,-1111.698852,25.079416,97.709457,0.000029,144.921401);
	CreateDynamicObject(18814,-293.317687,-1143.150146,30.182634,97.563560,0.000077,143.609313);
	CreateDynamicObject(18814,-238.760864,-1070.961669,18.216997,96.931800,0.000002,132.185379);
	*/
	
	//SendClientMessageToAll(0xFF0000FF,"[IMPORTANT] Update World Building...");
	/*
	for(new playerid = 0, j = GetPlayerPoolSize(); playerid <= j; playerid++){
		
	}
	*/
	tmpobj[0] = CreateDynamicObject(2293,0.0,0.0,-6000.0,0.0,0.0,0.0);
	tmpobj[1] = CreateDynamicObject(2293,0.0,0.0,-6000.0,0.0,0.0,0.0);
	
	/*
	tmpobj[0] = CreateDynamicObject(12957, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[1] = CreateDynamicObject(18646, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	//tmpobj[1] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[2] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[3] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[4] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[5] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[6] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[7] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	tmpobj[8] = CreateDynamicObject(971, 0.0, 0.0, -6000.0, 0.0, 0.0, 0.0, 0, 0, -1, 300.0);
	*/
	

	return 1;
}



CMD:niewidka(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	new vid = GetPlayerVehicleID(playerid);
	LinkVehicleToInterior(vid,1);
	return 1;
}

CMD:widka(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	new vid = GetPlayerVehicleID(playerid);
	LinkVehicleToInterior(vid,0);
	return 1;
}

CMD:teslaadd(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	new vid = GetPlayerVehicleID(playerid);
	//RepairVehicle(vid);
	//SetVehicleHealth(vid,100000.0);
	
	AttachDynamicObjectToVehicle(tmpobj[0], vid, 1.5, -3.5, -1.2, 0.0, 0.0, 0.0);
	AttachDynamicObjectToVehicle(tmpobj[1], vid, -1.5, -3.5, -1.2, 0.0, 0.0, 0.0);
	
	/*
	AttachDynamicObjectToVehicle(tmpobj[0], vid, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[1], vid, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0);
	*/
	/*
	AttachDynamicObjectToVehicle(tmpobj[1], vid, 0.0, 1.3, 0.9, -75.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[2], vid, 0.0, -1.3, 0.9, -75.0, 0.0, 0.0);
	AttachDynamicObjectToVehicle(tmpobj[3], vid, 1.3, 0.0, 0.9, -75.0, 0.0, 90.0);
	AttachDynamicObjectToVehicle(tmpobj[4], vid, -1.3, 0.0, 0.9, -75.0, 0.0, 270.0);
	
	AttachDynamicObjectToVehicle(tmpobj[5], vid, 0.0, 1.3, -0.9, 75.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[6], vid, 0.0, -1.3, -0.9, 75.0, 0.0, 0.0);
	AttachDynamicObjectToVehicle(tmpobj[7], vid, 1.3, 0.0, -0.9, 75.0, 0.0, 90.0);
	AttachDynamicObjectToVehicle(tmpobj[8], vid, -1.3, 0.0, -0.9, 75.0, 0.0, 270.0);
	*/
	
	//LinkVehicleToInterior(vid,1);
	return 1;
}

CMD:tesladel(playerid){
	if(!IsPlayerAdmin(playerid)) return 0;
	//new vid = GetPlayerVehicleID(playerid);
	AttachDynamicObjectToVehicle(tmpobj[0],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[1],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	
	/*
	AttachDynamicObjectToVehicle(tmpobj[2],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[3],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[4],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[5],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[6],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[7],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	AttachDynamicObjectToVehicle(tmpobj[8],INVALID_VEHICLE_ID, 0.25, -0.5, 0.0, 0.0, 0.0, 180.0);
	RepairVehicle(vid);
	SetVehicleHealth(vid,1000.0);
	LinkVehicleToInterior(vid,0);
	*/
	return 1;
}

public OnFilterScriptExit(){

	return 1;
}


