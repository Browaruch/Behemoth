#include <a_samp>
#include <streamer>
#include <sscanf2>
#include <mapandreas>
#include <izcmd>
#include <FCNPC>

#define MAX_CA_OBJECTS 1
#include <colandreas>

#include <PTS/pts.player>

#include <SAM/StreamerFunction>
#include <SAM/3DTryg>
#include <SAM/ATM>

#include <engine/Missile>
#include <FCNPC_Hook>

new interceptor_npc,
	interceptor_veh,
	interceptor_timer,
	interceptor_area,
	bool:interceptor_ready=false,
	interceptor_tick,
	bool:weapon_enable = false;

CMD:interceptor(playerid){
	weapon_enable = !weapon_enable;
	return 1;
}

public OnFilterScriptInit(){
	
	interceptor_area = CreateDynamicCube(-100.9095,1443.4415,35.0000,114.6733,1589.1609,200.0,0,0,-1);
	
	interceptor_veh = CreateVehicle(520,7.3747,1529.9331,100.0,266.6788,0,0,100);
	SetVehicleHealth(interceptor_veh,1000000.0);
	
	//interceptor_area = CreateDynamicCube(-3000.0,-3000.0,50.0,3000.0,3000.0,300.0,0,0,-1);

	#if defined _FCNPC_included
		interceptor_npc = FCNPC_Create("Vassago");
		FCNPC_Spawn(interceptor_npc,71,7.3747,1529.9331,100.0);
		FCNPC_Respawn(interceptor_npc);
		SetPlayerColor(interceptor_npc,0xFF0000FF);
	#endif
	
	
	interceptor_timer = SetTimerEx("OnInterceptorUpdate", 500, true, "d", interceptor_npc);
	
	return 1;
}

forward OnInterceptorUpdate(npcid);

public OnInterceptorUpdate(npcid){
	if(interceptor_ready && !FCNPC_IsMoving(npcid)){
		new F5[e_float];
		GetVehiclePos(FCNPC_GetVehicleID(npcid),F5[X],F5[Y],F5[Z]);
		GetPointInFront3DCol(F5[X],F5[Y],F5[Z],float(random(91)-45),float(random(360)),float(random(150)+50),F5[tX],F5[tY],F5[tZ]);
		MovePointColCutLineEx(F5[X],F5[Y],F5[Z],F5[tX],F5[tY],F5[tZ],F5[tX],F5[tY],F5[tZ],8.0);
		//Tryg3DMapAndreasFindZ(F5[tX],F5[tY],F5[tZ]);
		if(IsPointInDynamicArea(interceptor_area,F5[tX],F5[tY],F5[tZ])){
			FCNPC_SetVehicleTargetRotation(npcid,F5[tX],F5[tY],F5[tZ]);
			FCNPC_GoTo(npcid,F5[tX],F5[tY],F5[tZ],MOVE_TYPE_DRIVE,1.0,false,0.0,false);
		}
	}
	
	if(weapon_enable){
		new F4[Float3D], F6[Float3D], vid = FCNPC_GetVehicleID(npcid);
		GetVehiclePos(vid,F6[T3D:X],F6[T3D:Y],F6[T3D:Z]);
		GetVehicleRotation(vid,F6[T3D:rX],F6[T3D:rY],F6[T3D:rZ]);
		CompRotationFloat(F6[T3D:rX]-45.0,F6[T3D:rX]);

		GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],F6[T3D:rX],F6[T3D:rZ]+90.0,3.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
		GetPointInFront3DCol(F4[T3D:X],F4[T3D:Y],F4[T3D:Z],F6[T3D:rX],F6[T3D:rZ],1200.0,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
		MissileLaunch(MISSILE_TYPE_EXPLODE_NORMAL,5.0,25.0,80.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_NORMAL,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid);

		GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],F6[T3D:rX],F6[T3D:rZ]-90.0,3.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
		GetPointInFront3DCol(F4[T3D:X],F4[T3D:Y],F4[T3D:Z],F6[T3D:rX],F6[T3D:rZ],1200.0,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
		MissileLaunch(MISSILE_TYPE_EXPLODE_NORMAL,5.0,25.0,80.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_NORMAL,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid);

		GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],F6[T3D:rX],F6[T3D:rZ]+45.0,4.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
		GetPointInFront3DCol(F4[T3D:X],F4[T3D:Y],F4[T3D:Z],F6[T3D:rX],F6[T3D:rZ],1200.0,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
		MissileLaunch(MISSILE_TYPE_EXPLODE_NORMAL,5.0,25.0,80.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_NORMAL,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid);

		GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],F6[T3D:rX],F6[T3D:rZ]-45.0,4.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
		GetPointInFront3DCol(F4[T3D:X],F4[T3D:Y],F4[T3D:Z],F6[T3D:rX],F6[T3D:rZ],1200.0,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
		MissileLaunch(MISSILE_TYPE_EXPLODE_NORMAL,5.0,25.0,80.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_NORMAL,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid);

		if(GetTickCount()-interceptor_tick > 3000){
			
			new Float:rand1,
				Float:rand2 = float(randomex(100,300));
				
			rand2 = float(randomex(50,300));
			rand1 = rand2 / 2;
			F4[T3D:rZ] = float(random(360));
			GetVehiclePos(vid,F6[T3D:X],F6[T3D:Y],F6[T3D:Z]);
			
			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,CompRotationFloat(F4[T3D:rZ]+60.0),8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,CompRotationFloat(F4[T3D:rZ]+120.0),8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,CompRotationFloat(F4[T3D:rZ]+180.0),8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,CompRotationFloat(F4[T3D:rZ]+240.0),8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,CompRotationFloat(F4[T3D:rZ]+300.0),8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			GetPointInFront3D(F6[T3D:X],F6[T3D:Y],F6[T3D:Z],0.0,F4[T3D:rZ],8.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
			GetPointInFront2D(F4[T3D:X],F4[T3D:Y],F4[T3D:rZ],rand2,F4[T3D:tX],F4[T3D:tY]);
			Tryg3DMapAndreasFindZ(F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ]);
			MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,15.0,35.0,50.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z],GetPlayerVirtualWorld(npcid),GetPlayerInterior(npcid),-1,300.0,MISSILE_OBJECT_HYDRA,F4[T3D:tX],F4[T3D:tY],F4[T3D:tZ],npcid,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,rand1);

			
			interceptor_tick = GetTickCount();
		}
	}
	return 1;
}

public OnFilterScriptExit(){

	KillTimer(interceptor_timer);
	
	#if defined _FCNPC_included
		if(FCNPC_IsValid(interceptor_npc)){
			FCNPC_Destroy(interceptor_npc);
		}
	#endif
	
	DestroyVehicle(interceptor_veh);
	

	
	return 1;
}

#if defined _FCNPC_included
	public FCNPC_OnCreate(npcid){
		
		return 1;
	}

	public FCNPC_OnSpawn(npcid){
		if(npcid == interceptor_npc){
			FCNPC_SetPosition(npcid,7.3747,1529.9331,100.0);
			FCNPC_SetAngle(npcid,266.6788);
			FCNPC_SetVirtualWorld(npcid,0);
			FCNPC_SetInterior(npcid,0);
			PutPlayerInVehicle(npcid,interceptor_veh,0);
			FCNPC_SetVehicleGearState(npcid,1);
			FCNPC_SetVehicleHydraThrusters(npcid,0);
			FCNPC_SetInvulnerable(npcid,true);
			SetVehiclePos(FCNPC_GetVehicleID(npcid),7.3747,1529.9331,100.0);
			SetVehicleHealth(FCNPC_GetVehicleID(npcid),1000000.0);
			interceptor_ready = true;
		}
		return 1;
	}

	public FCNPC_OnRespawn(npcid){
		if(npcid == interceptor_npc){
			FCNPC_SetPosition(npcid,7.3747,1529.9331,100.0);
			FCNPC_SetAngle(npcid,266.6788);
			FCNPC_SetVirtualWorld(npcid,0);
			FCNPC_SetInterior(npcid,0);
			PutPlayerInVehicle(npcid,interceptor_veh,0);
			FCNPC_SetVehicleGearState(npcid,1);
			FCNPC_SetVehicleHydraThrusters(npcid,0);
			FCNPC_SetInvulnerable(npcid,true);
			SetVehiclePos(FCNPC_GetVehicleID(npcid),7.3747,1529.9331,100.0);
			SetVehicleHealth(FCNPC_GetVehicleID(npcid),1000000.0);
			interceptor_ready = true;
		}
		return 1;
	}

	public FCNPC_OnDeath(npcid,killerid,weaponid){
		if(npcid == interceptor_npc){
			interceptor_ready = false;
			FCNPC_Respawn(interceptor_npc);
		}
		return 1;
	}

	public FCNPC_OnVehicleEntryComplete(npcid, vehicleid, seat){

		return 1;
	}

	public FCNPC_OnVehicleExitComplete(npcid){

		return 1;
	}

	public FCNPC_OnReachDestination(npcid){

		return 1;
	}

	public FCNPC_OnFinishPlayback(npcid){

		return 1;
	}

	public FCNPC_OnTakeDamage(npcid, damagerid, weaponid, bodypart, Float:health_loss){

		return 1;
	}

	public FCNPC_OnVehicleTakeDamage(npcid, damagerid, vehicleid, weaponid, Float:x, Float:y, Float:z){
		if(npcid == interceptor_npc){
			SetVehicleHealth(vehicleid,1000000.0);
		}
		return 1;
	}

	public FCNPC_OnFinishNodePoint(npcid, point){

		return 1;
	}

	public FCNPC_OnChangeNode(npcid, nodeid){

		return 1;
	}

	public FCNPC_OnFinishNode(npcid){

		return 1;
	}

	public FCNPC_OnStreamIn(npcid, forplayerid){

		return 1;
	}

	public FCNPC_OnStreamOut(npcid, forplayerid){

		return 1;
	}
#endif