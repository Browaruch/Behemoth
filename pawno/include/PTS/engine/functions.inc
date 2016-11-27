
//return (minx,miny,minz,	maxx,maxy,maxz)
stock FixAreaValue(Float:X1,Float:Y1,Float:Z1,Float:X2,Float:Y2,Float:Z2,&Float:minx,&Float:miny,&Float:minz,&Float:maxx,&Float:maxy,&Float:maxz){
	if(X1 < X2){
		minx = X1, maxx = X2;
	} else {
		minx = X2, maxx = X1;
	}
	if(Y1 < Y2){
		miny = Y1, maxy = Y2;
	} else {
		miny = Y2, maxy = Y1;
	}
	if(Z1 < Z2){
		minz = Z1, maxz = Z2;
	} else {
		minz = Z2, maxz = Z1;
	}
}


stock bool:IsPlayerSpawnedEx(playerid){
	if(!IsPlayerVisible[playerid]) return false;
	new pstate=GetPlayerState(playerid);
	if(pstate != 1 && pstate != 2 && pstate != 3) return false;
	return true;
}

stock bool:IsValidSkin(skinid){
	if(skinid < 0 || skinid > 311) return false;
	switch(skinid){
		case 74: return false;
	}
	return true;
}

stock CreateActorEx(name[],color,modelid,Float:x,Float:y,Float:z,Float:angle,Float:set_z=1.0){
	CreateDynamic3DTextLabel(name,color,x,y,z+set_z,30.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
	return CreateActor(modelid,x,y,z,angle);
}

stock bool:IsAnimAllow(playerid){
	if(IsPlayerInAnyVehicle(playerid)){
		SendClientMessage(playerid,COLOR_RED,"Nie mo¿na u¿ywaæ animacji w pojeŸdzie.");
		return false;
	} else if(gGracz[playerid][Zemdlenie]){
		SendClientMessage(playerid,COLOR_RED,"Zemdla³eœ");
		return false;
	} else if(gGracz[playerid][Kajdanki] != 0){
		SendClientMessage(playerid,COLOR_RED,"Nie mo¿esz u¿ywaæ animacji w kajdankach!");
		return false;
	}
	return true;
}

stock LoopingAnim(playerid,animlib[],animname[],Float:Speed,looping,lockx,locky,lockz,lp){
	if(!IsAnimAllow(playerid)) return 0;
	ApplyAnimation(playerid,animlib,animname,Speed,looping,lockx,locky,lockz,lp,1);
	gGracz[playerid][performingAnim] = true;
	return 1;
}

stock OnePlayAnim(playerid,animlib[],animname[],Float:Speed,looping,lockx,locky,lockz,lp){
	if(IsPlayerInAnyVehicle(playerid)){
		SendClientMessage(playerid,COLOR_RED,"Nie mo¿na u¿ywaæ animacji w pojeŸdzie.");
		return 0;
	}
	ApplyAnimation(playerid,animlib,animname,Speed,looping,lockx,locky,lockz,lp,1);
	gGracz[playerid][performingAnim] = true;
	return 1;
}

stock StopLoopingAnim(playerid){
	ApplyAnimation(playerid,"CARRY","crry_prtial",4.0,0,0,0,0,0);
	ClearAnimations(playerid);
	gGracz[playerid][performingAnim] = false;
}

stock MSGToAdmins(color,text[],level){
	FoxForeach(i,Player){
		if(gGracz[i][AdminLvl] >= level){
			SendClientMessage(i,color,text);
		}
	}
}

stock GetPlayerIP(playerid){
	new szIP[16];
	GetPlayerIp(playerid,szIP,sizeof(szIP));
	return szIP;
}

//By Nickk888
stock bool:IsVehicleInUse(vehicleid){
	FoxForeach(i,Character){
		if(IsPlayerInAnyVehicle(i)){
			if(GetPlayerVehicleID(i) == vehicleid) return true;
		}
	}
	return false;
}

//By Nickk888
stock GetVehicleIDModelName(vehicleid){
	new vname[100];
	format(vname,sizeof(vname),"%s",VehicleNames[GetVehicleModel(vehicleid) - 400][0]);
	return vname;
}

//By JernejL
stock Float:DistanceCameraTargetToLocation(Float:CamX,Float:CamY,Float:CamZ, Float:ObjX,Float:ObjY,Float:ObjZ, Float:FrX,Float:FrY,Float:FrZ){
	new Float:TGTDistance;
	TGTDistance = floatsqroot((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));
	new Float:tmpX,Float:tmpY,Float:tmpZ;
	
	tmpX = FrX * TGTDistance + CamX;
	tmpY = FrY * TGTDistance + CamY;
	tmpZ = FrZ * TGTDistance + CamZ;
	
	return floatsqroot((tmpX - ObjX) * (tmpX - ObjX) + (tmpY - ObjY) * (tmpY - ObjY) + (tmpZ - ObjZ) * (tmpZ - ObjZ));
}

//By CracK
stock IsPlayerAimingAt(playerid,Float:x,Float:y,Float:z,Float:radius){
    new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
    GetPlayerCameraPos(playerid,cx,cy,cz);
    GetPlayerCameraFrontVector(playerid,fx,fy,fz);
    return (radius >= DistanceCameraTargetToLocation(cx,cy,cz,x,y,z,fx,fy,fz));
}

stock RemovePlayerWeapon(playerid,weaponid){
	new plyWeapons[12];
	new plyAmmo[12];
	for(new slot = 0; slot != 12; slot++){
		new wep,ammo;
		GetPlayerWeaponData(playerid,slot,wep,ammo);
		if(wep != weaponid){
			GetPlayerWeaponData(playerid,slot,plyWeapons[slot],plyAmmo[slot]);
		}
	}
	ResetPlayerWeapons(playerid);
	for(new slot = 0; slot < 12; slot++){
		GivePlayerWeapon(playerid,plyWeapons[slot],plyAmmo[slot]);
	}
}

stock IsNumeric(const str[]){
	new len = strlen(str);
	if(!len) return false;
	for(new i; i < len; i++){
		if(!('0' <= str[i] <= '9')) return false;
	}
	return true;
}

stock GetGunName(gunid){
	new res[24];
	switch(gunid){
		case 0: format(res,sizeof(res),"Rêka");
		case 1: format(res,sizeof(res),"Kastet");
		case 2: format(res,sizeof(res),"Kij golfowy");
		case 3: format(res,sizeof(res),"Pa³ka");
		case 4: format(res,sizeof(res),"Nó¿");
		case 5: format(res,sizeof(res),"Kij bassebalowy");
		case 6: format(res,sizeof(res),"£opata");
		case 7: format(res,sizeof(res),"Kij bilardowy");
		case 8: format(res,sizeof(res),"Katana");
		case 9: format(res,sizeof(res),"Chainsaw");
		case 10: format(res,sizeof(res),"Double-ended Dildo");
		case 11: format(res,sizeof(res),"Dildo");
		case 12: format(res,sizeof(res),"Wibrator");
		case 13: format(res,sizeof(res),"Srebrny wibrator");
		case 14: format(res,sizeof(res),"Kwiaty");
		case 15: format(res,sizeof(res),"Cane");
		case 16: format(res,sizeof(res),"Grenade");
		case 17: format(res,sizeof(res),"Tear Gas");
		case 18: format(res,sizeof(res),"Molotov Cocktail");
		case 22: format(res,sizeof(res),"9mm Pistol");
		case 23: format(res,sizeof(res),"Pistolet z t³umikiem");
		case 24: format(res,sizeof(res),"Desert Eagle");
		case 25: format(res,sizeof(res),"Pump Shotgun");
		case 26: format(res,sizeof(res),"Sawnoff Shotgun");
		case 27: format(res,sizeof(res),"Combat Shotgun");
		case 28: format(res,sizeof(res),"Uzi");
		case 29: format(res,sizeof(res),"MP5");
		case 30: format(res,sizeof(res),"AK-47");
		case 31: format(res,sizeof(res),"M4");
		case 32: format(res,sizeof(res),"Tec-9");
		case 33: format(res,sizeof(res),"Country Rifle");
		case 34: format(res,sizeof(res),"Snajperka");
		case 35: format(res,sizeof(res),"RPG");
		case 36: format(res,sizeof(res),"Wyrzutnia rakiet");
		case 37: format(res,sizeof(res),"Miotacz ognia");
		case 38: format(res,sizeof(res),"Minigun");
		case 39: format(res,sizeof(res),"Satchel Charge");
		case 40: format(res,sizeof(res),"Detonator");
		case 41: format(res,sizeof(res),"Gaz pieprzowy");
		case 42: format(res,sizeof(res),"Gasnica");
		case 43: format(res,sizeof(res),"Aparat");
		case 44: format(res,sizeof(res),"Goggle Noktowizyjne");
		case 45: format(res,sizeof(res),"Goggle Termowizyjne");
		case 46: format(res,sizeof(res),"Spadochron");
		default: format(res,sizeof(res),"Brak");
	}
	return res;
}

