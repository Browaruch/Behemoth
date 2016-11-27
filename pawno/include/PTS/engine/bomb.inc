
function OnBombUpdate(mobid){
	BombTick[mobid]++;
	if(BombTick[mobid] == 300){
		//podk³adamy bombe
		new Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz,Float:rz,buffer[128];
		GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,x,y);
		Tryg3DMapAndreasFindZ(x,y,z);
		while(IsPointInWater(x,y)){
			GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,x,y);
			Tryg3DMapAndreasFindZ(x,y,z);
		}
		GetPointInWallForPoint(x,y,z+1.5,5000.0,tx,ty,tz);
		GetRotationFor2Point2D(tx,ty,x,y,rz);
		BombText[mobid] = CreateDynamic3DTextLabel("£adunek Wybuchowy",0xFF0000FF,tx,ty,tz,35.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,-1,0);
		BombObject[mobid] = CreateDynamicObject(363,tx,ty,tz,0.0,0.0,CompRotationFloat(rz+180.0));
		BombMapIcon[mobid] = CreateDynamicMapIcon(tx,ty,tz,37,1,0,0,-1,6000.0);
		BombArea[mobid] = CreateDynamicSphere(tx,ty,tz,25.0,0,0,-1);
		BombStatus[mobid] = true;
		
		for(new i = 0, j = sizeof(gSAZones); i < j; i++){
			if(tx >= gSAZones[i][SAZONE_AREA][0] && tx <= gSAZones[i][SAZONE_AREA][3] && ty >= gSAZones[i][SAZONE_AREA][1] && ty <= gSAZones[i][SAZONE_AREA][4] && tz >= gSAZones[i][SAZONE_AREA][2] && tz <= gSAZones[i][SAZONE_AREA][5]){
				format(buffer,sizeof buffer,"##Wykryto bombe: {00FF00}%s",gSAZones[i][SAZONE_NAME]);
				format(BombLocation[mobid],64,"%s",gSAZones[i][SAZONE_NAME]);
				break;
			}
		}
		FoxForeach(i,Player){
			if(SkinyWojska(i) && gGracz[i][FrakcjaWojsko] == 1){
				SendClientMessage(i,COLOR_ORANGE,buffer);
			}
		}
	} else if(BombTick[mobid] >= 900){
		//detonacja jeœli nie rozbrojona
		if(BombStatus[mobid]){
			BombStatus[mobid] = false;
			new Float:tx,Float:ty,Float:tz,buffer[128];
			GetDynamicObjectPos(BombObject[mobid],tx,ty,tz);
			CreateDynamicExplosion(tx,ty,tz,7,25.0,0,0,-1,200.0);
			CreateDynamicExplosion(tx-2.5,ty-2.5,tz,7,25.0,0,0,-1,200.0);
			CreateDynamicExplosion(tx-2.5,ty+2.5,tz,7,25.0,0,0,-1,200.0);
			CreateDynamicExplosion(tx+2.5,ty-2.5,tz,7,25.0,0,0,-1,200.0);
			CreateDynamicExplosion(tx+2.5,ty+2.5,tz,7,25.0,0,0,-1,200.0);
			if(IsValidDynamicObject(BombObject[mobid])) DestroyDynamicObject(BombObject[mobid]);
			if(IsValidDynamicMapIcon(BombMapIcon[mobid])) DestroyDynamicMapIcon(BombMapIcon[mobid]);
			if(IsValidDynamic3DTextLabel(BombText[mobid])) DestroyDynamic3DTextLabel(BombText[mobid]);
			if(IsValidDynamicArea(BombArea[mobid])) DestroyDynamicArea(BombArea[mobid]);
			for(new i = 0, j = sizeof(gSAZones); i < j; i++){
				if(tx >= gSAZones[i][SAZONE_AREA][0] && tx <= gSAZones[i][SAZONE_AREA][3] && ty >= gSAZones[i][SAZONE_AREA][1] && ty <= gSAZones[i][SAZONE_AREA][4] && tz >= gSAZones[i][SAZONE_AREA][2] && tz <= gSAZones[i][SAZONE_AREA][5]){
					format(buffer,sizeof buffer,"##Bomba wybuch³a: {00FF00}%s",gSAZones[i][SAZONE_NAME]);
					break;
				}
			}
			FoxForeach(i,Player){
				if(IsPlayerInRangeOfPoint(i,150.0,tx,ty,tz)){
					if(IsPlayerInAnyVehicle(i)){
						new engine,lights, alarm, bonnet, boot, doors, objective, vehid = GetPlayerVehicleID(i);
						GetVehicleParamsEx(vehid,engine,lights,alarm,doors,bonnet,boot,objective);
						SetVehicleParamsEx(vehid,0,0,alarm,doors,bonnet,boot,objective);
					}
				}
				if(SkinyWojska(i) && gGracz[i][FrakcjaWojsko] == 1){
					SendClientMessage(i,COLOR_ORANGE,buffer);
				}
			}
		}
		BombTick[mobid] = 0;
	}
}