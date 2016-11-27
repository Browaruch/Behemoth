#include <a_samp> 
#include <izcmd> 
#include <streamer> 
#include <sscanf2> 
#include <ColAndreas>
#include <SAM/3DTryg> 
#include <engine/Mines> 

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#define SCRIPT_NAME		"Miny"

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000A0)	//
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
	SendClientMessageToAll(0xFF0000FF,"[IMPORTANT] Trwa podk³adanie min...");
	
	new Float:tmpz;
	for(new i = 0; i < 15; i++){

		Tryg3DMapAndreasFindZ(-10.0000,1700.0000+(i*30),tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -10.0000, 1700.0000+(i*30), tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
		
		Tryg3DMapAndreasFindZ(-40.0000,1700.0000+(i*30),tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -40.0000, 1700.0000+(i*30), tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
		
		Tryg3DMapAndreasFindZ(410.0,1700.0000+(i*30),tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, 410.0, 1700.0000+(i*30), tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
	
	}
	for(new i = 1; i < 13; i++){
		Tryg3DMapAndreasFindZ(-10.0000+(i*30),1700.0000,tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -10.0000+(i*30), 1700.0000, tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
		
		Tryg3DMapAndreasFindZ(-10.0000+(i*30),1700.0000-30.0,tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -10.0000+(i*30), 1700.0000-30.0, tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
	}
	for(new i = 1; i < 14; i++){
		Tryg3DMapAndreasFindZ(-10.0000+(i*30),2120.0,tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -10.0000+(i*30), 2120.0, tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
		
		Tryg3DMapAndreasFindZ(-10.0000+(i*30),2120.0-30.0,tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, -10.0000+(i*30), 2120.0-30.0, tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
	}
	for(new i = 0; i < 7; i++){
		Tryg3DMapAndreasFindZ(380.0,1700.0000+(i*30),tmpz);
		CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 2.0, 0.05, 200.0, 120, 380.0, 1700.0000+(i*30), tmpz+1.0, 0, 0, -1, 200.0, MINE_OBJECT_STANDARD);
	}

	CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 1.5, 0.05, 50.0, 120, 271.0000,1881.8000,-31.3906, 0, 0, -1, 200.0, MINE_OBJECT_LASER);
	CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 1.5, 0.05, 50.0, 120, 266.3000,1881.8000,-31.3906, 0, 0, -1, 200.0, MINE_OBJECT_LASER);
	CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 1.5, 0.05, 50.0, 120, 266.3000,1886.3000,-31.3906, 0, 0, -1, 200.0, MINE_OBJECT_LASER);
	CreateDynamicMine(MINE_TYPE_EXPLODE_NORMAL, 1.5, 0.05, 50.0, 120, 271.0000,1886.3000,-31.3906, 0, 0, -1, 200.0, MINE_OBJECT_LASER);
	
	
    return 1; 
} 

#define MINE_DAMAGE_PLAYER		80.0
#define MINE_DAMAGE_VEHICLE		1000.0

public OnMineDestroy(mobid,Float:x,Float:y,Float:z,type,killerid,Float:radius,damagerid){
	
	new Float:plx,Float:ply,Float:plz;
	Tryg3DForeach(i){
		GetPlayerPos(i,plx,ply,plz);
		if(GetDistanceBetweenPoints3D(x,y,z,plx,ply,plz) <= radius){
			if(IsPlayerInAnyVehicle(killerid)){
				new Float:hp, vid = GetPlayerVehicleID(killerid);
				GetVehicleHealth(vid,hp);
				SetVehicleHealth(vid,hp-MINE_DAMAGE_VEHICLE);
			} else {
				new Float:hp,Float:ar;
				GetPlayerHealth(killerid,hp);
				GetPlayerArmour(killerid,ar);
				SetPlayerHealth(killerid,hp);
				SetPlayerArmour(killerid,ar);
			
				Tryg3D_GivePlayerDamage(killerid,MINE_DAMAGE_PLAYER,damagerid,51,true);
			}
		}
	}
	
	return 1;
}

CMD:addmine(playerid,params[]){ 
    if(!IsPlayerAdmin(playerid)) return 0; 
     
    new buffer[128], type, Float:detection_range, Float:explode_radius, Float:health, respawntime, 
        Float:x, Float:y, Float:z, worldid, interiorid, Float:streamdistance, mine_object = MINE_OBJECT_STANDARD, teamid = ANY_TEAM; 
    GetPlayerPos(playerid,x,y,z); 
    worldid = GetPlayerVirtualWorld(playerid); 
    interiorid = GetPlayerInterior(playerid); 
    if(sscanf(params,"dfffdfD(-1)D(-1)",type,detection_range,explode_radius,health,respawntime,streamdistance,mine_object,teamid)) return SendClientMessage(playerid,-1,"/addmine <type> <detection r> <explode r> <hp> <respawn> <stream distance> [obj] [team]"); 
     
    if(mine_object == -1) mine_object = MINE_OBJECT_STANDARD; 
    if(teamid == -1) teamid = ANY_TEAM; 
     
    new mobid = CreateDynamicMine(type,detection_range,explode_radius,health,respawntime,x,y,z,worldid,interiorid,-1,streamdistance,mine_object,teamid); 
    format(buffer,sizeof buffer,"Added mine id %d",mobid); 
    SendClientMessage(playerid,-1,buffer); 
     
    return 1; 
} 

CMD:delmine(playerid,params[]){ 
    if(!IsPlayerAdmin(playerid)) return 0; 
    new buffer[128], mobid = INVALID_MINE_ID; 
    if(sscanf(params,"d",mobid)) return SendClientMessage(playerid,-1,"/delmine <mobid>"); 
     
    if(MineComponent[mobid][mine_status] != MINE_STATUS_UNACTIVE){ 
        DestroyDynamicMine(mobid); 
        format(buffer,sizeof buffer,"Removed mine id %d",mobid); 
        SendClientMessage(playerid,-1,buffer); 
    } else { 
        format(buffer,sizeof buffer,"Mine id %d not exist",mobid); 
        SendClientMessage(playerid,-1,buffer); 
    } 
    return 1; 
}  
