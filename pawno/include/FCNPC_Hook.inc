/****************************************************************************************************
 *                                                                                                  *
 * Sk³adnik Next Generation City Mod                                                                *
 * Skrypt opracowany przez Pawe³ Przespolewski (Abyss Morgan)                                       *
 * dla AllTogether, NGC Revolution                                                                  *
 * na podstawie gry AirRivals oraz Battle Pirates                                                   *
 * Kontakt z autorem wojownikx9x@gmail.com lub https://www.facebook.com/Zin.WojownikX9X             *
 * Copyright © 2016 Abyss Morgan. All rights reserved.                                              *
 * Kopiowanie i udostêpnianie kodu lub jego czêœci zabronione!                                      *
 *                                                                                                  *
 ****************************************************************************************************/
 
//Hook: PutPlayerInVehicle
stock AR_PutPlayerInVehicle(playerid, vehicleid, seatid){
	if(!IsPlayerNPC(playerid)) return PutPlayerInVehicle(playerid,vehicleid,seatid);
	return FCNPC_PutInVehicle(playerid,vehicleid,seatid);
}

#if defined _ALS_PutPlayerInVehicle
    #undef PutPlayerInVehicle
#else
    #define _ALSPutPlayerInVehicle
#endif
#define PutPlayerInVehicle AR_PutPlayerInVehicle



//Hook: SpawnPlayer
stock AR_SpawnPlayer(playerid){
	if(!IsPlayerNPC(playerid)) return SpawnPlayer(playerid);
	return FCNPC_Respawn(playerid);
}

#if defined _ALS_SpawnPlayer
    #undef SpawnPlayer
#else
    #define _ALS_SpawnPlayer
#endif
#define SpawnPlayer AR_SpawnPlayer




//Hook: IsPlayerConnected
stock AR_IsPlayerConnected(playerid){
	if(!IsPlayerNPC(playerid)){
		if(IsPlayerConnected(playerid)) return true;
		return false;
	} else {
		if(FCNPC_IsValid(playerid)) return true;
		return false;
	}
}

#if defined _ALS_IsPlayerConnected
    #undef IsPlayerConnected
#else
    #define _ALS_IsPlayerConnected
#endif
#define IsPlayerConnected AR_IsPlayerConnected



//Hook: SetPlayerInterior
stock AR_SetPlayerInterior(playerid,interiorid){
	if(!IsPlayerNPC(playerid)){
		return SetPlayerInterior(playerid,interiorid);
	} else {
		return FCNPC_SetInterior(playerid,interiorid);
	}
}

#if defined _ALS_SetPlayerInterior
    #undef SetPlayerInterior
#else
    #define _ALS_SetPlayerInterior
#endif
#define SetPlayerInterior AR_SetPlayerInterior



//Hook: GetPlayerInterior
stock AR_GetPlayerInterior(playerid){
	if(!IsPlayerNPC(playerid)){
		return GetPlayerInterior(playerid);
	} else {
		return FCNPC_GetInterior(playerid);
	}
}

#if defined _ALS_GetPlayerInterior
    #undef GetPlayerInterior
#else
    #define _ALS_GetPlayerInterior
#endif
#define GetPlayerInterior AR_GetPlayerInterior



//Hook: SetPlayerVirtualWorld
stock AR_SetPlayerVirtualWorld(playerid,worldid){
	if(!IsPlayerNPC(playerid)){
		return SetPlayerVirtualWorld(playerid,worldid);
	} else {
		return FCNPC_SetVirtualWorld(playerid,worldid);
	}
}

#if defined _ALS_SetPlayerVirtualWorld
    #undef SetPlayerVirtualWorld
#else
    #define _ALS_SetPlayerVirtualWorld
#endif
#define SetPlayerVirtualWorld AR_SetPlayerVirtualWorld



//Hook: GetPlayerVirtualWorld
stock AR_GetPlayerVirtualWorld(playerid){
	if(!IsPlayerNPC(playerid)){
		return GetPlayerVirtualWorld(playerid);
	} else {
		return FCNPC_GetVirtualWorld(playerid);
	}
}

#if defined _ALS_GetPlayerVirtualWorld
    #undef GetPlayerVirtualWorld
#else
    #define _ALS_GetPlayerVirtualWorld
#endif
#define GetPlayerVirtualWorld AR_GetPlayerVirtualWorld



//Hook: SendClientMessage
stock AR_SendClientMessage(playerid, color, const message[]){
	if(!IsPlayerNPC(playerid)){
		return SendClientMessage(playerid,color,message);
	} else {
		printf("NPC MSG: %s",message);
	}
	return 1;
}

#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif
#define SendClientMessage AR_SendClientMessage



//Hook: GetPlayerVehicleID
stock AR_GetPlayerVehicleID(playerid){
	if(!IsPlayerNPC(playerid)){
		return GetPlayerVehicleID(playerid);
	} else {
		return FCNPC_GetVehicleID(playerid);
	}
}

#if defined _ALS_GetPlayerVehicleID
    #undef GetPlayerVehicleID
#else
    #define _ALS_GetPlayerVehicleID
#endif
#define GetPlayerVehicleID AR_GetPlayerVehicleID



//Hook: SetPlayerPos
stock AR_SetPlayerPos(playerid, Float:x, Float:y, Float:z){
	if(!IsPlayerNPC(playerid)) return SetPlayerPos(playerid,x,y,z);
	return FCNPC_SetPosition(playerid,x,y,z);
}

#if defined _ALS_SetPlayerPos
    #undef SetPlayerPos
#else
    #define _ALSSetPlayerPos
#endif
#define SetPlayerPos AR_SetPlayerPos



//Hook: GetPlayerPos
stock AR_GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z){
	if(!IsPlayerNPC(playerid)) return GetPlayerPos(playerid,x,y,z);
	return FCNPC_GetPosition(playerid,x,y,z);
}

#if defined _ALS_GetPlayerPos
    #undef GetPlayerPos
#else
    #define _ALSGetPlayerPos
#endif
#define GetPlayerPos AR_GetPlayerPos



//EOF