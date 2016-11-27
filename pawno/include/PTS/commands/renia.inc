
CMD:reniaatak(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid,targetid;
	if(sscanf(params,"dd",userid,targetid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniaatak <id> <cel lub -1>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(targetid == -1){
		FCNPC_StopAim(Acid_Renia[userid]);
	} else {
		FCNPC_SetWeapon(Acid_Renia[userid],27);
		FCNPC_SetAmmo(Acid_Renia[userid],9999);
		FCNPC_AimAtPlayer(Acid_Renia[userid],targetid,true,0,true);
	}
	return 1;
}

CMD:reniaatakall(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new targetid;
	if(sscanf(params,"d",targetid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniaatakall <cel lub -1>");
	for(new i = 0; i < MAX_RENIA; i++){
		if(targetid == -1){
			FCNPC_StopAim(Acid_Renia[i]);
		} else {
			FCNPC_SetWeapon(Acid_Renia[i],27);
			FCNPC_SetAmmo(Acid_Renia[i],9999);
			FCNPC_AimAtPlayer(Acid_Renia[i],targetid,true,0,true);
		}
	}
	return 1;
}

CMD:reniaskin(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid,skinid;
	if(sscanf(params,"dd",userid,skinid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniaskin <id> <id skina>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(!IsValidSkin(skinid)) return SendClientMessage(playerid,0xFFFFFFFF,"B≥Ídne id skina.");
	FCNPC_SetSkin(Acid_Renia[userid],skinid);
	return 1;
}

CMD:renia(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /renia <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	Acid_Renia_Ruch[userid] = true;
	FCNPC_GoToPlayerOnGroundCol(Acid_Renia[userid],playerid,MOVE_TYPE_WALK,MOVE_SPEED_AUTO,true,1.0,2.0,true);
	return 1;
}

CMD:reniastop(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniastop <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	Acid_Renia_Ruch[userid] = false;
	FCNPC_Stop(Acid_Renia[userid]);
	return 1;
}

CMD:reniaall(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	for(new i = 0; i < MAX_RENIA; i++){
		Acid_Renia_Ruch[i] = true;
		FCNPC_GoToPlayerOnGroundCol(Acid_Renia[i],playerid,MOVE_TYPE_WALK,MOVE_SPEED_AUTO,true,1.0,2.0,true);
	}
	return 1;
}

CMD:reniastopall(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	for(new i = 0; i < MAX_RENIA; i++){
		Acid_Renia_Ruch[i] = false;
		FCNPC_Stop(Acid_Renia[i]);
	}
	return 1;
}

CMD:reniath(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniath <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	new F4[Vectors3D];
	GetPlayerOrientationPos(playerid,o_left,2.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
	GetPlayerFacingAngle(playerid,F4[T3D:A]);
	FCNPC_SetPosition(Acid_Renia[userid],F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
	FCNPC_SetAngle(Acid_Renia[userid],F4[T3D:A]);
	FCNPC_SetInvulnerable(Acid_Renia[userid],true);
	FCNPC_SetVirtualWorld(Acid_Renia[userid],GetPlayerVirtualWorld(playerid));
	FCNPC_SetInterior(Acid_Renia[userid],GetPlayerInterior(playerid));
	return 1;
}

CMD:reniatt(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniatt <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	new F4[Vectors3D];
	GetNPCOrientationPos(Acid_Renia[userid],o_left,2.0,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);

	SetPlayerPos(playerid,F4[T3D:X],F4[T3D:Y],F4[T3D:Z]);
	SetPlayerFacingAngle(playerid,FCNPC_GetAngle(Acid_Renia[userid]));
	SetPlayerVirtualWorld(playerid,FCNPC_GetVirtualWorld(Acid_Renia[userid]));
	SetPlayerInterior(playerid,FCNPC_GetInterior(Acid_Renia[userid]));
	
	return 1;
}

CMD:reniawejdz(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_ERROR,"Musisz byÊ w pojeüdzie.");
	new userid,seatid;
	if(sscanf(params,"dd",userid,seatid)) return SendClientMessage(playerid,COLOR_ERROR,"/reniawejdz <id> <seatid>!");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(GetDistanceBetweenPlayers(playerid,Acid_Renia[userid]) > 10.0) return SendClientMessage(playerid,COLOR_ERROR,"Renia jest za daleko!");
	if(IsPlayerInAnyVehicle(Acid_Renia[userid])) return SendClientMessage(playerid,COLOR_ERROR,"Renia jest w pojeüdzie");
	if(seatid < 0 || seatid > 3) return SendClientMessage(playerid,COLOR_ERROR,"Wybierz slot zakres 0-3!");
	Acid_Renia_Auto[userid] = true;
	FCNPC_EnterVehicle(Acid_Renia[userid],GetPlayerVehicleID(playerid),seatid,MOVE_TYPE_WALK);
	return 1;
}

CMD:reniabj(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniabj <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(GetDistanceBetweenPlayers(playerid,Acid_Renia[userid]) > 10.0) return SendClientMessage(playerid,COLOR_ERROR,"Renia jest za daleko!");
	Blowjob(playerid,Acid_Renia[userid],0);
	return 1;
}

CMD:reniabj2(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniabj2 <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(GetDistanceBetweenPlayers(playerid,Acid_Renia[userid]) > 10.0) return SendClientMessage(playerid,COLOR_ERROR,"Renia jest za daleko!");
	Blowjob2(playerid,Acid_Renia[userid],0);
	return 1;
}

CMD:reniawyjdz(playerid,params[]){
	if(!gGracz[playerid][acid_renia]) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Uøyj: /reniawyjdz <id>");
	if(userid >= MAX_RENIA || userid < 0) return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawid≥owie ID Gracza");
	if(IsPlayerInAnyVehicle(Acid_Renia[userid])){
		FCNPC_ExitVehicle(Acid_Renia[userid]);
	}
	Acid_Renia_Auto[userid] = false;
	return 1;
}
