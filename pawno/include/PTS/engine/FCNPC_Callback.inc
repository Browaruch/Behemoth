#if defined _FCNPC_included
	public FCNPC_OnCreate(npcid){
		
		return 1;
	}

	public FCNPC_OnSpawn(npcid){
		
		return 1;
	}

	public FCNPC_OnRespawn(npcid){
		for(new i = 0; i < MAX_RENIA; i++){
			if(npcid == Acid_Renia[i]){
				FCNPC_Spawn(Acid_Renia[i],AcidReniaMeta[i][p_skin],AcidReniaMeta[i][p_spawnX],AcidReniaMeta[i][p_spawnY],AcidReniaMeta[i][p_spawnZ]);
				FCNPC_SetAngle(Acid_Renia[i],AcidReniaMeta[i][p_spawnA]);
				FCNPC_SetInvulnerable(Acid_Renia[i],true);
				FCNPC_SetVirtualWorld(Acid_Renia[i],AcidReniaMeta[i][p_spawnVW]);
				FCNPC_SetInterior(Acid_Renia[i],AcidReniaMeta[i][p_spawnINT]);
				SetPlayerColor(Acid_Renia[i],AcidReniaMeta[i][p_color]);
				FCNPC_SetWeapon(Acid_Renia[i],27);
				FCNPC_SetAmmo(Acid_Renia[i],9999);
				FCNPC_SetFightingStyle(Acid_Renia[i],FIGHT_STYLE_KUNGFU);
			}
		}
		return 1;
	}

	public FCNPC_OnDeath(npcid,killerid,weaponid){
		FCNPC_Respawn(npcid);
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