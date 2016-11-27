/****************************************************************************************************
 *                                                                                                  *
 *                                          Anti God Mode                                           *
 *                                                                                                  *
 * Copyright © 2016 Abyss Morgan. All rights reserved.                                              *
 *                                                                                                  *
 * Download: N/A                                                                                    *
 *                                                                                                  *
 * Plugins: None                                                                                    *
 * Modules: ProtVar                                                                                 *
 *                                                                                                  *
 * File Version: 1.0                                                                                *
 *                                                                                                  *
 ****************************************************************************************************/


/*
Uwaga: w callbacku OnPlayerSpawn(playerid)

//na pocz¹tku dodajemy to:
public OnPlayerSpawn(playerid){
	if(!CG_ProtVar::cgod_clear[playerid]) return 1;
	
	//reszta kodu
	
	return 1;
}
*/

#define CGOD_EXTRA_VW		(playerid+90000)

//CG_ProtVar::
#if defined ENABLE_PROTECTION_VARIABLES && defined CG_ProtVar::
	#define CG_ProtVar::	CG_ProtVar::
#else
	#define CG_ProtVar::
#endif

new bool:CG_ProtVar::cgod_clear[MAX_PLAYERS],
	CG_ProtVar::cgod_vw[MAX_PLAYERS],
	CG_ProtVar::S0beitVehicle[MAX_PLAYERS],
	CG_ProtVar::RobberTestTimer[MAX_PLAYERS] = -1;

stock bool:CheckModS0beit_A(playerid){
	new CG_ProtVar::F4[e_float];
	GetPlayerCameraFrontVector(playerid,CG_ProtVar::F4[X],CG_ProtVar::F4[Y],CG_ProtVar::F4[Z]);
	if(CG_ProtVar::F4[Z] <= -0.90) return true;
	return false;
}

stock bool:CheckModS0beit_B(playerid){
	if(IsValidVehicle(CG_ProtVar::S0beitVehicle[playerid])) DestroyVehicle(CG_ProtVar::S0beitVehicle[playerid]);
	new weapon,ammo;
	for(new i = 0; i < 13; i++){
		GetPlayerWeaponData(playerid,i,weapon,ammo);
		if(weapon ==  2) return true;
	}
	return false;
}

function RobberTest(playerid){
	if(IsPlayerConnected(playerid) && gGracz[playerid][firstspawn]){
		//zbyt d³ugie logowanie
		new buffer[200];
		format(buffer,sizeof(buffer),"[SECURITY] [%s](%d)%s login timeout",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu zbyt d³ugiego logowania.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
	}
	return 1;
}

function S0beitCheckStart(playerid){
	new CG_ProtVar::F4[e_float];
	GetPlayerPos(playerid,CG_ProtVar::F4[X],CG_ProtVar::F4[Y],CG_ProtVar::F4[Z]);
	GetPlayerFacingAngle(playerid,CG_ProtVar::F4[rZ]);
	CG_ProtVar::S0beitVehicle[playerid] = CreateVehicle(457,0.0,0.0,5.0,0.01,-1,2500,0);
	SetVehicleVirtualWorld(CG_ProtVar::S0beitVehicle[playerid],GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(CG_ProtVar::S0beitVehicle[playerid],GetPlayerInterior(playerid));
	PutPlayerInVehicle(playerid,CG_ProtVar::S0beitVehicle[playerid],0);
	ChowajTextDrawAuto(playerid);
	return 1;
}

//Procedura 2
function OnModS0beitClear(playerid){
	if(CheckModS0beit_A(playerid) || CheckModS0beit_B(playerid)){
		//prawdopodobny ModSobeit
		new buffer[200];
		format(buffer,sizeof(buffer),"[HACK DETECT] [%s](%d)%s used ModSobeit",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu ModSobeit.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
	} else {
		//ModSobeit/WH/AIM Test
		new ammo_0 = 0, ammo_1 = 0, ammo_10 = 0, wep_0 = -1, wep_1 = -1, wep_10 = -1;
		GetPlayerWeaponData(playerid,0,wep_0,ammo_0);
		GetPlayerWeaponData(playerid,1,wep_1,ammo_1);
		GetPlayerWeaponData(playerid,10,wep_10,ammo_10);

		if((ammo_0 >= 10) || (ammo_1 >= 10) || (ammo_10 >= 10)){
			new buffer[200];
			format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used ModSobeit/WH/AIM D:%d:%d:%d:%d",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),GetPlayerWeapon(playerid),ammo_0,ammo_1,ammo_10);
			print(buffer);
			WriteLog(buffer,LOG_FILE_HACK);
			MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
			SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu ModSobeit/WH/AIM.");
			SetTimerEx("KickGracza",200,false,"d",playerid);
		} else {
			//Rozpoczynam procedure DSOUND
			SetPlayerPos(playerid,303.0838,-1605.8403,96.5000);
			TogglePlayerControllable(playerid,1);
			
			SetTimerEx("OnDSOUNDCheck",3000,false,"d",playerid); //Inicjuj procedure DSOUND
		}
	}
	if(IsValidVehicle(CG_ProtVar::S0beitVehicle[playerid])) DestroyVehicle(CG_ProtVar::S0beitVehicle[playerid]);
	return 1;
}

function OnDSOUNDCheck(playerid){
	if(!IsPlayerInRangeOfPoint(playerid,2.0,303.0838,-1605.8403,96.5000)){
		if(!gGracz[playerid][prot_hack_detect]) return 1;
		gGracz[playerid][prot_hack_detect] = false;
		
		new buffer[200];
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used DSOUND.dll or GTA Damaged",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu DSOUND.dll lub twoje GTA SA jest uszkodzone");
		SetTimerEx("KickGracza",200,false,"d",playerid);
	} else {
		CG_ProtVar::cgod_clear[playerid] = true;
		SetPlayerVirtualWorld(playerid,CG_ProtVar::cgod_vw[playerid]);
		
		SpawnPlayer(playerid);
		SetTimerEx("OnScanEnd",1000,false,"d",playerid);
	}
	return 1;
}

function OnScanEnd(playerid){
	TextDrawHideForPlayer(playerid,SkanTD);
	TextDrawHideForPlayer(playerid,zacma);
	return 1;
}
	
public OnPlayerConnect(playerid){
	CG_ProtVar::cgod_clear[playerid] = false;
	#if defined CG_OnPlayerConnect
		CG_OnPlayerConnect(playerid);
	#endif
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect CG_OnPlayerConnect
#if defined CG_OnPlayerConnect
	forward CG_OnPlayerConnect(playerid);
#endif

//Inicjuj procedure 1
public OnPlayerSpawn(playerid){
	if(!CG_ProtVar::cgod_clear[playerid] && !IsPlayerNPC(playerid) && gGracz[playerid][PoradnikNumer] != 14){
		if(!IsPlayerConnected(playerid)) return 1;
		
		TextDrawShowForPlayer(playerid,zacma);
		TextDrawShowForPlayer(playerid,SkanTD);
		CG_ProtVar::cgod_vw[playerid] = GetPlayerVirtualWorld(playerid);
		SetPlayerVirtualWorld(playerid,CGOD_EXTRA_VW);
		TogglePlayerControllable(playerid,0);
	
		ResetPlayerWeapons(playerid);

		S0beitCheckStart(playerid);
		SetTimerEx("OnModS0beitClear",1000,false,"d",playerid); //Inicjuj procedure 2
	}
	#if defined CG_OnPlayerSpawn
		CG_OnPlayerSpawn(playerid);
	#endif
	return 1;
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn CG_OnPlayerSpawn
#if defined CG_OnPlayerSpawn
	forward CG_OnPlayerSpawn();
#endif

//Hook: SetPlayerHealth
stock CG_SetPlayerHealth(playerid,Float:health){
	if(!CG_ProtVar::cgod_clear[playerid]){
		return 0; //nie mo¿na teraz zmieniæ stanu HP
	} else {
		return SetPlayerHealth(playerid,health);
	}
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth CG_SetPlayerHealth

//Hook: SetPlayerArmour
stock CG_SetPlayerArmour(playerid,Float:armour){
	if(!CG_ProtVar::cgod_clear[playerid]){
		return 0; //nie mo¿na teraz zmieniæ stanu Armora
	} else {
		return SetPlayerArmour(playerid,armour);
	}
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour CG_SetPlayerArmour


//Hook: SetPlayerAmmo
stock CG_SetPlayerAmmo(playerid,weaponid,ammo){
	if(ammo < 0 || ammo > 10000) ammo = 10000;
	return SetPlayerAmmo(playerid,weaponid,ammo);
}

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif
#define SetPlayerAmmo CG_SetPlayerAmmo

//Hook: GivePlayerWeapon
stock CG_GivePlayerWeapon(playerid,weaponid,ammo){
	if(weaponid == 44 || weaponid == 45) return 0;
	new wepid, ammo_a;
	GetPlayerWeaponData(playerid,weaponSlots[weaponid],wepid,ammo_a);
	if(ammo < 0){
		ammo = 0;
	} else if(ammo+ammo_a > 10000){
		SetPlayerAmmo(playerid,weaponid,10000);
	} else {
		return GivePlayerWeapon(playerid,weaponid,ammo);
	}
	return 1;
}

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon CG_GivePlayerWeapon
//EOF