/****************************************************************************************************
 *                                                                                                  *
 * Reaver Defense Hulk Prototype v1.2 made by Abyss Morgan                                          *
 *                                                                                                  *
 * Download: https://github.com/AbyssMorgan/SA-MP/tree/master/filterscripts                         *
 *                                                                                                  *
 ****************************************************************************************************/

 
#include <a_samp>
#include <streamer>
#include <mapandreas>
#include <ColAndreas>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#define SCRIPT_NAME		"Defense Hulk V6"

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000AC)	//
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

#define DISABLE_3D_TRYG_INIT
#include <SAM/3DTryg>
#include <engine/EngineV6>

#define SD_VERYHIGH					(999.0)

#define MAX_DEFENSE_HULK			(3)
#define MAX_NGC_NPC					(300)

#define MOB_SPEED_SLOW				(5.0)
#define MOB_SPEED_NORMAL			(10.0)
#define MOB_SPEED_FAST				(25.0)

new DefenseHulkTimer,
	NGCFighter[MAX_NGC_NPC][4],
	NGCFighterPool,
	DragonHead[MAX_NGC_NPC][4],
	DragonHeadPool,
	UnderDudeHead[MAX_NGC_NPC][4],
	UnderDudeHeadPool,
	NGCCommander[MAX_NGC_NPC][4],
	NGCCommanderPool,
	NGCExcavator[MAX_NGC_NPC][4],
	NGCExcavatorPool;
	
forward OnMobUpdate(tec);

forward FighterUpdate(mobid);
forward CreateFighter(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid);
forward DestroyFighter(mobid);

forward CommanderUpdate(mobid);
forward CreateCommander(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid);
forward DestroyCommander(mobid);

forward ExcavatorUpdate(mobid);
forward CreateExcavator(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid);
forward DestroyExcavator(mobid);

forward DragonUpdate(mobid);
forward CreateDragon(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid);
forward DestroyDragon(mobid);

forward UnderDudeUpdate(mobid);
forward CreateUnderDude(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid);
forward DestroyUnderDude(mobid);

public OnFilterScriptInit(){

    // Load the SA map

	
	DefenseHulkTimer = SetTimerEx("OnMobUpdate", 500, true, "d", 1);
	
	new myarea = CreateDynamicCube(-100.9095,1443.4415,35.0000,114.6733,1589.1609,200.0);

	for(new i = 0; i < 10; i++){
		CreateFighter(i,7.3747,1529.9331,100.0, 0,0, myarea);
	}
	
	/*
	for(new i = 0; i < 10; i++){
		CreateDragon(i,7.3747,1529.9331,100.0, 0,0, myarea);
	}
	*/
	
	for(new i = 0; i < 10; i++){
		CreateCommander(i,7.3747,1529.9331,100.0, 0,0, myarea);
	}
	
	/*
	for(new i = 0; i < 10; i++){
		CreateExcavator(i, 0.0,0.0,3.0, 0,0, myarea);
	}
	
	for(new i = 0; i < 10; i++){
		CreateUnderDude(i, -2170.0430,1623.7864,-6.0942, 0,0, myarea);
	}
	*/
	return 1;
}

public OnFilterScriptExit(){
	KillTimer(DefenseHulkTimer);
	return 1;
}

public OnMobUpdate(tec){
	#pragma unused tec
	
	for(new i = 0; i <= NGCFighterPool; i++){
		if(NGCFighter[i][2] == 1){
			FighterUpdate(i);
		}
	}
	
	for(new i = 0; i <= DragonHeadPool; i++){
		if(DragonHead[i][2] == 1){
			DragonUpdate(i);
		}
	}
	
	for(new i = 0; i <= NGCCommanderPool; i++){
		if(NGCCommander[i][2] == 1){
			CommanderUpdate(i);
		}
	}
	
	for(new i = 0; i <= NGCExcavatorPool; i++){
		if(NGCExcavator[i][2] == 1){
			ExcavatorUpdate(i);
		}
	}
	
	
	for(new i = 0; i <= UnderDudeHeadPool; i++){
		if(UnderDudeHead[i][2] == 1){
			UnderDudeUpdate(i);
		}
	}
	return 1;
}

/*
0 objectid
1 areaid
2 status
3 step
*/

public FighterUpdate(mobid){
	if(NGCFighter[mobid][2] == 1){
		if(!IsDynamicObjectMoving(NGCFighter[mobid][0])){
			if(NGCFighter[mobid][3] == 0){
				EpsilonEngineRotation(NGCFighter[mobid][0],ENGINE_FIGHTER);
				NGCFighter[mobid][3] = 1;
			} else {
				EpsilonEngineX(NGCFighter[mobid][0],NGCFighter[mobid][1],ENGINE_FIGHTER,50,100,5,MOB_SPEED_NORMAL);
				NGCFighter[mobid][3] = 0;
			}
		}
	}
	return 1;
}

public CreateFighter(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid){
	
	NGCFighter[mobid][0] = CreateDynamicObject(10757,x,y,z+3.0,8.0,12.0,180.0,worldid,interiorid,-1,300.0);
	SetDynamicObjectMaterial(NGCFighter[mobid][0],0,1676,"wshxrefpump","metalic128",0xFF00AAAA);
	SetDynamicObjectMaterial(NGCFighter[mobid][0],1,1676,"wshxrefpump","metalic128",0xFF00AAAA);
	
	NGCFighter[mobid][1] = areaid;
	NGCFighter[mobid][3] = 0;
	
	if(NGCFighterPool < mobid) NGCFighterPool = mobid;
	
	NGCFighter[mobid][2] = 1;
	
	return 1;
}

public DestroyFighter(mobid){
	NGCFighter[mobid][2] = 0;
	if(IsValidDynamicObject(NGCFighter[mobid][0])) DestroyDynamicObject(NGCFighter[mobid][0]);
	return 1;
}


public DragonUpdate(mobid){
	if(DragonHead[mobid][2] == 1){
		if(!IsDynamicObjectMoving(DragonHead[mobid][0])){
			if(DragonHead[mobid][3] == 0){
				EpsilonEngineRotation(DragonHead[mobid][0],ENGINE_SUPPLY);
				DragonHead[mobid][3] = 1;
			} else {
				EpsilonEngineX(DragonHead[mobid][0],DragonHead[mobid][1],ENGINE_SUPPLY,50,100,5,MOB_SPEED_NORMAL);
				DragonHead[mobid][3] = 0;
			}
		}
	}
	return 1;
}

public CreateDragon(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid){
	
	DragonHead[mobid][0] = CreateDynamicObject(3528,x,y,z+3.0,0.0,0.0,90.0,worldid,interiorid,-1,300.0);
	DragonHead[mobid][1] = areaid;
	DragonHead[mobid][3] = 0;
	
	if(DragonHeadPool < mobid) DragonHeadPool = mobid;
	
	DragonHead[mobid][2] = 1;
	
	return 1;
}

public DestroyDragon(mobid){
	DragonHead[mobid][2] = 0;
	if(IsValidDynamicObject(DragonHead[mobid][0])) DestroyDynamicObject(DragonHead[mobid][0]);
	return 1;
}

public UnderDudeUpdate(mobid){
	if(UnderDudeHead[mobid][2] == 1){
		if(!IsDynamicObjectMoving(UnderDudeHead[mobid][0])){
			if(UnderDudeHead[mobid][3] == 0){
				EpsilonEngineRotation(UnderDudeHead[mobid][0],ENGINE_UNDERDUDE);
				UnderDudeHead[mobid][3] = 1;
			} else {
				EpsilonEngineX(UnderDudeHead[mobid][0],UnderDudeHead[mobid][1],ENGINE_UNDERDUDE,50,100,5,MOB_SPEED_NORMAL);
				UnderDudeHead[mobid][3] = 0;
			}
		}
	}
	return 1;
}

public CreateUnderDude(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid){
	
	UnderDudeHead[mobid][0] = CreateDynamicObject(1379,x,y,z,0.0,0.0,0.0,worldid,interiorid,-1,300.0);
	UnderDudeHead[mobid][1] = areaid;
	UnderDudeHead[mobid][3] = 0;
	
	if(UnderDudeHeadPool < mobid) UnderDudeHeadPool = mobid;
	
	UnderDudeHead[mobid][2] = 1;
	
	return 1;
}

public DestroyUnderDude(mobid){
	UnderDudeHead[mobid][2] = 0;
	if(IsValidDynamicObject(UnderDudeHead[mobid][0])) DestroyDynamicObject(UnderDudeHead[mobid][0]);
	return 1;
}



public CommanderUpdate(mobid){
	if(NGCCommander[mobid][2] == 1){
		if(!IsDynamicObjectMoving(NGCCommander[mobid][0])){
			if(NGCCommander[mobid][3] == 0){
				EpsilonEngineRotation(NGCCommander[mobid][0],ENGINE_NORMAL);
				NGCCommander[mobid][3] = 1;
			} else {
				EpsilonEngineX(NGCCommander[mobid][0],NGCCommander[mobid][1],ENGINE_NORMAL,50,100,5,MOB_SPEED_NORMAL);
				NGCCommander[mobid][3] = 0;
			}
		}
	}
	return 1;
}

public CreateCommander(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid){
	
	NGCCommander[mobid][0] = CreateDynamicObject(1681,x,y,z+3.0,8.0,12.0,180.0,worldid,interiorid,-1,300.0);
	SetDynamicObjectMaterial(NGCCommander[mobid][0],0,1676,"wshxrefpump","metalic128",0xFF00AAAA);
	SetDynamicObjectMaterial(NGCCommander[mobid][0],1,1676,"wshxrefpump","metalic128",0xFF00AAAA);
	
	//skin
	SetDynamicObjectMaterial(NGCCommander[mobid][0],0,1676,"wshxrefpump","metalic128",0xFFFF0000);
	SetDynamicObjectMaterial(NGCCommander[mobid][0],1,1676,"wshxrefpump","metalic128",0xFFFF0000);

	NGCCommander[mobid][1] = areaid;
	NGCCommander[mobid][3] = 0;
	
	if(NGCCommanderPool < mobid) NGCCommanderPool = mobid;
	
	NGCCommander[mobid][2] = 1;
	
	return 1;
}

public DestroyCommander(mobid){
	NGCCommander[mobid][2] = 0;
	if(IsValidDynamicObject(NGCCommander[mobid][0])) DestroyDynamicObject(NGCCommander[mobid][0]);
	return 1;
}

public ExcavatorUpdate(mobid){
	if(NGCExcavator[mobid][2] == 1){
		EngineXCA(NGCExcavator[mobid][0],NGCExcavator[mobid][1],ENGINE_EXCAVATOR,50,100,1.0,MOB_SPEED_SLOW);
		EngineExcavatorUpdate(NGCExcavator[mobid][0],NGCExcavator[mobid][1],ENGINE_EXCAVATOR,MOB_SPEED_SLOW);		
	}
	return 1;
}

public CreateExcavator(mobid,Float:x,Float:y,Float:z,worldid,interiorid,areaid){
	
	NGCExcavator[mobid][0] = CreateDynamicObject(18248,x,y,z+7.0,0.0,0.0,185.0,worldid,interiorid,-1,300.0);
	NGCExcavator[mobid][1] = areaid;
	NGCExcavator[mobid][3] = 0;
	
	if(NGCExcavatorPool < mobid) NGCExcavatorPool = mobid;
	
	NGCExcavator[mobid][2] = 1;
	
	return 1;
}

public DestroyExcavator(mobid){
	NGCExcavator[mobid][2] = 0;
	if(IsValidDynamicObject(NGCExcavator[mobid][0])) DestroyDynamicObject(NGCExcavator[mobid][0]);
	return 1;
}

//EOF