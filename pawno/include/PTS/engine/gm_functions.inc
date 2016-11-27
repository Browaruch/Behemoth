stock RakSAMP(playerid){
	if(!gGracz[playerid][prot_hack_detect]) return 1;
	gGracz[playerid][prot_hack_detect] = false;
	new buffer[200];
	format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used RakSAMP",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
	print(buffer);
	WriteLog(buffer,LOG_FILE_HACK);
	MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
	SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu RakSAMP.");
	BanEx(playerid,"[HD] RakSAMP");
	return 0;
}

stock SavePlayerPM(playerid,string[]){
	for(new i = 0; i < (MAX_LASTPM-1); i++){
		fstrcopy(LastPlayerPM[playerid][i+1],LastPlayerPM[playerid][i]);
	}
	new n = MAX_LASTPM-1;
	fstrcopy(string,LastPlayerPM[playerid][n]);
}

stock OtworzGranice(){
	MoveDynamicObject(GranicaSFLS,608.7000,-1197.7000,11.0000,2.0 ,0.0000000,0.0000000,24.5000000);
	MoveDynamicObject(GranicaLSSF,631.4000,-1192.9000,12.7400,2.0,0.0000000,0.2500000,24.7490000);
	
	MoveDynamicObject(GranicaSFLV,-1381.00269,826.09863,49.11047-8.0,2.0,0.00000,0.00000,-43.67990);
	MoveDynamicObject(GranicaLVSF,-1413.58984,831.53961,49.20675-8.0,2.0,0.00000,0.00000,137.88005);
	
	MoveDynamicObject(GranicaLSLV,1750.77563,529.43561,22.5571,1.9,0.00000,0.00000,-19.00000);
	MoveDynamicObject(GranicaLVLS,1728.71448,521.44409,23.0200,2.0,0.00000,0.00000,161.02000);
	
	MoveDynamicObject(GranicaBSSF,-2686.31470,1270.84631,55.08646-8.0,2.0,0.00000,0.00000,180.00000);
	MoveDynamicObject(GranicaSFBS,-2677.03149,1283.38464,55.05373-8.0,2.0,0.00000,0.00000,0.00000);

}

stock SprawdzPoziomFirmy(firmaid){
	if(fFirma[firmaid][Dostarczenia] < 30){
		fFirma[firmaid][Poziom] = 0;
	} else if(fFirma[firmaid][Dostarczenia] >= 30 && fFirma[firmaid][Dostarczenia] < 90){
		fFirma[firmaid][Poziom] = 1;
	} else if(fFirma[firmaid][Dostarczenia] >= 10 && fFirma[firmaid][Dostarczenia] < 150){
		fFirma[firmaid][Poziom] = 2;
	} else if(fFirma[firmaid][Dostarczenia] >= 160 && fFirma[firmaid][Dostarczenia] < 220){
		fFirma[firmaid][Poziom] = 3;
	} else if(fFirma[firmaid][Dostarczenia] >= 220 && fFirma[firmaid][Dostarczenia] < 270){
		fFirma[firmaid][Poziom] = 4;
	} else if(fFirma[firmaid][Dostarczenia] >= 270 && fFirma[firmaid][Dostarczenia] < 320){
		fFirma[firmaid][Poziom] = 5;
	} else if(fFirma[firmaid][Dostarczenia] >= 320 && fFirma[firmaid][Dostarczenia] < 370){
		fFirma[firmaid][Poziom] = 6;
	} else if(fFirma[firmaid][Dostarczenia] >= 370 && fFirma[firmaid][Dostarczenia] < 470){
		fFirma[firmaid][Poziom] = 7;
	} else if(fFirma[firmaid][Dostarczenia] >= 470 && fFirma[firmaid][Dostarczenia] < 490){
		fFirma[firmaid][Poziom] = 8;
	} else if(fFirma[firmaid][Dostarczenia] >= 490 && fFirma[firmaid][Dostarczenia] < 500){
		fFirma[firmaid][Poziom] = 9;
	} else if(fFirma[firmaid][Dostarczenia] >= 530 && fFirma[firmaid][Dostarczenia] < 570){
		fFirma[firmaid][Poziom] = 10;
	} else if(fFirma[firmaid][Dostarczenia] >= 570 && fFirma[firmaid][Dostarczenia] < 620){
		fFirma[firmaid][Poziom] = 11;
	} else if(fFirma[firmaid][Dostarczenia] >= 620 && fFirma[firmaid][Dostarczenia] < 700){
		fFirma[firmaid][Poziom] = 12;
	} else if(fFirma[firmaid][Dostarczenia] >= 700 && fFirma[firmaid][Dostarczenia] < 750){
		fFirma[firmaid][Poziom] = 13;
	} else if(fFirma[firmaid][Dostarczenia] >= 750 && fFirma[firmaid][Dostarczenia] < 800){
		fFirma[firmaid][Poziom] = 14;
	} else if(fFirma[firmaid][Dostarczenia] >= 800 && fFirma[firmaid][Dostarczenia] < 860){
		fFirma[firmaid][Poziom] = 15;
	} else if(fFirma[firmaid][Dostarczenia] >= 860 && fFirma[firmaid][Dostarczenia] < 910){
		fFirma[firmaid][Poziom] = 16;
	} else if(fFirma[firmaid][Dostarczenia] >= 910 && fFirma[firmaid][Dostarczenia] < 970){
		fFirma[firmaid][Poziom] = 17;
	} else if(fFirma[firmaid][Dostarczenia] >= 970 && fFirma[firmaid][Dostarczenia] < 1050){
		fFirma[firmaid][Poziom] = 18;
	} else if(fFirma[firmaid][Dostarczenia] >= 1050 && fFirma[firmaid][Dostarczenia] < 1150){
		fFirma[firmaid][Poziom] = 19;
	} else if(fFirma[firmaid][Dostarczenia] >= 1150 && fFirma[firmaid][Dostarczenia] < 1300){
		fFirma[firmaid][Poziom] = 20;
	} else if(fFirma[firmaid][Dostarczenia] >= 1300 && fFirma[firmaid][Dostarczenia] < 1500){
		fFirma[firmaid][Poziom] = 21;
	} else if(fFirma[firmaid][Dostarczenia] >= 1500 && fFirma[firmaid][Dostarczenia] < 2000){
		fFirma[firmaid][Poziom] = 22;
	} else if(fFirma[firmaid][Dostarczenia] >= 2000 && fFirma[firmaid][Dostarczenia] < 2300){
		fFirma[firmaid][Poziom] = 23;
	} else if(fFirma[firmaid][Dostarczenia] >= 2300 && fFirma[firmaid][Dostarczenia] < 2500){
		fFirma[firmaid][Poziom] = 24;
	} else if(fFirma[firmaid][Dostarczenia] >= 2500 && fFirma[firmaid][Dostarczenia] < 2700){
		fFirma[firmaid][Poziom] = 25;
	} else if(fFirma[firmaid][Dostarczenia] >= 2700 && fFirma[firmaid][Dostarczenia] < 3000){
		fFirma[firmaid][Poziom] = 26;
	} else if(fFirma[firmaid][Dostarczenia] >= 3000 && fFirma[firmaid][Dostarczenia] < 3200){
		fFirma[firmaid][Poziom] = 27;
	} else if(fFirma[firmaid][Dostarczenia] >= 3200 && fFirma[firmaid][Dostarczenia] < 3500){
		fFirma[firmaid][Poziom] = 28;
	} else if(fFirma[firmaid][Dostarczenia] >= 3500 && fFirma[firmaid][Dostarczenia] < 3700){
		fFirma[firmaid][Poziom] = 29;
	} else if(fFirma[firmaid][Dostarczenia] >= 3700 && fFirma[firmaid][Dostarczenia] < 4000){
		fFirma[firmaid][Poziom] = 30;
	} else if(fFirma[firmaid][Dostarczenia] >= 4000 && fFirma[firmaid][Dostarczenia] < 4200){
		fFirma[firmaid][Poziom] = 31;
	} else if(fFirma[firmaid][Dostarczenia] >= 4200 && fFirma[firmaid][Dostarczenia] < 4500){
		fFirma[firmaid][Poziom] = 32;
	} else if(fFirma[firmaid][Dostarczenia] >= 4500 && fFirma[firmaid][Dostarczenia] < 4800){
		fFirma[firmaid][Poziom] = 33;
	} else if(fFirma[firmaid][Dostarczenia] >= 4800 && fFirma[firmaid][Dostarczenia] < 5100){
		fFirma[firmaid][Poziom] = 34;
	} else if(fFirma[firmaid][Dostarczenia] >= 5100){
		fFirma[firmaid][Poziom] = 35;
	}
	return 1;
}

stock Float:GetVehicleMaxFuel(modelid){
	switch(modelid){
		case 572: return 999.0;
		case 577,592: return 600.0;
		case 432: return 300.0;
		case 425,520: return 200.0;
		case 515: return 140.0;
		case 514: return 120.0;
		case 403: return 110.0;
		case 407,544,601,433: return 100.0;
		case 443,406,531,437: return 90.0;
		case 563,455,416,427,431,487,498: return 80.0;
		case 499: return 75.0;
		case 528,409,456: return 70.0;
		case 525: return 65.0;
		case 411,413,414,440,459,470,482,578: return 60.0;
		case 461,462,463,468,521,522,523,581: return 30.0;
	}
	return 50.0;
}

stock PlayerDataConstruct(){
	new player_data[Dane];
	
	player_data[MaxCheckpointy] = 61;
	player_data[AnulowanieTowaru] = true;
	player_data[ZaproszenieDoFirmy] = -1;
	player_data[FirmaUID] = -1;
	player_data[SkinKierowcy] = 230;
	player_data[CBKanal] = 1;
	player_data[DomID] = -1;
	player_data[UIDDomu] = -1;
	player_data[Glod] = 100;
	player_data[ViewPM] = true;
	player_data[Zmeczenie] = 100;
	player_data[StatusPm] = true;
	player_data[FotoradarCount] = true;
	player_data[StatusViewC] = true;
	player_data[WiadroPojemnosc] = 1;
	player_data[StatusJail] = true;
	player_data[firstspawn] = false;
	player_data[tick_count] = GetTickCount();
	
	return player_data;
}

stock ChopkiUpdateAnim(){
	ApplyActorAnimation(chopek[2],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(chopek[3],"DANCING","DAN_Loop_A",4.0,1,0,0,0,0);
	ApplyActorAnimation(chopek[13],"FOOD","FF_Sit_Eat1",4.000000,0,1,1,1,0);
	ApplyActorAnimation(chopek[18],"ped","IDLE_chat",4.1,1,1,1,1,1);
	ApplyActorAnimation(chopek[19],"ped","IDLE_chat",4.1,1,1,1,1,1);
	ApplyActorAnimation(chopek[20],"ped","IDLE_chat",4.1,1,1,1,1,1);
	ApplyActorAnimation(chopek[21],"ped","IDLE_chat",4.1,1,1,1,1,1);
	ApplyActorAnimation(chopek[22],"FOOD","FF_Sit_Eat1",4.000000,0,1,1,1,0);
	ApplyActorAnimation(chopek[23],"FOOD","FF_Sit_Eat1",4.000000,0,1,1,1,0);
	ApplyActorAnimation(chopek[27],"FOOD","FF_Sit_Eat1",4.000000,0,1,1,1,0);
}

stock SkinyPolicji(playerid){
	switch(GetPlayerSkin(playerid)){
		case 265,266,267,280,281,283,284,285,306: return 1;
	}
	return 0;
}

stock SkinyWojska(playerid){
	switch(GetPlayerSkin(playerid)){
		case 179,191,286,287: return 1;
	}
	return 0;
}

stock SkinyStrazyGranicznej(playerid){
	switch(GetPlayerSkin(playerid)){
		case 71,282,288,309: return 1;
	}
	return 0;
}

stock SkinyTaxi(playerid){
	switch(GetPlayerSkin(playerid)){
		case 11,142,143,171,172,253: return 1;
	}
	return 0;
}

stock SkinyMedykow(playerid){
	switch(GetPlayerSkin(playerid)){
		case 70,274,275,276,308: return 1;
	}
	return 0;
}

stock SkinyPomocyDrogowej(playerid){
	switch(GetPlayerSkin(playerid)){
		case 8,16,42,50,69,260,268: return 1;
	}
	return 0;
}

stock SkinySP(playerid){
	switch(GetPlayerSkin(playerid)){
		case 277,278,279: return 1;
	}
	return 0;
}



stock CountPolicji(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaPolicja]){
			cnt++;
		} else if(gGracz[i][FrakcjaPolicja] == 1 && SkinyPolicji(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountWojska(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaWojsko]){
			cnt++;
		} else if(gGracz[i][FrakcjaWojsko] == 1 && SkinyWojska(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountStrazyGranicznej(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaStrazGraniczna]){
			cnt++;
		} else if(gGracz[i][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountTaxi(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaTaxi]){
			cnt++;
		} else if(gGracz[i][FrakcjaTaxi] == 1 && SkinyTaxi(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountMedykow(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaMedyk]){
			cnt++;
		} else if(gGracz[i][FrakcjaMedyk] == 1 && SkinyMedykow(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountPomocyDrogowej(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaPomocDrogowa]){
			cnt++;
		} else if(gGracz[i][FrakcjaPomocDrogowa] == 1 && SkinyPomocyDrogowej(i)){
			cnt++;
		}
	}
	return cnt;
}

stock CountSP(bool:only_skin=true){
	new cnt = 0;
	FoxForeach(i,Player){
		if(!only_skin && gGracz[i][FrakcjaSP]){
			cnt++;
		} else if(gGracz[i][FrakcjaSP] == 1 && SkinySP(i)){
			cnt++;
		}
	}
	return cnt;
}

function UpdateZmeczenie(tec){
	FoxForeach(i,Player){
		UpdatePasekZ(i);
	}
	return 1;
}

function UpdateGlod(tec){
	FoxForeach(i,Player){
		UpdatePasek(i);
	}
	return 1;
}
