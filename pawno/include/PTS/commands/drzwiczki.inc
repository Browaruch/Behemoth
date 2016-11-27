CMD:lotgaro(playerid){
	MoveDynamicObject(LotniskoBrama,1291.25513,1328.61548,5.65560,0.5,0.00000,0.00000,90.00000);
	MoveDynamicObject(LotniskoBrama2,1291.24304,1319.29346,5.65560,0.5,0.00000,0.00000,90.00000);
	SendClientMessage(playerid,COLOR_BLUE,"Gara¿ na lotnisku w LV zosta³ otwarty!");
	return 1;
}

CMD:lotgarc(playerid){
	MoveDynamicObject(LotniskoBrama,1291.25513,1328.61548,11.66160,1.0,0.00000,0.00000,90.00000);
	MoveDynamicObject(LotniskoBrama2,1291.24304,1319.29346,11.66160,1.0,0.00000,0.00000,90.00000);
	SendClientMessage(playerid,COLOR_BLUE,"Gara¿ na lotnisku w LV zosta³ zamkniêty!");
	return 1;
}

CMD:bramawyspac(playerid){
	MoveDynamicObject(WyspaBrama,1567.32092,-4947.87646,6.34940,1.0,0.00000,0.00000,180.00000);
	return 1;
}

CMD:bramawyspao(playerid){
	MoveDynamicObject(WyspaBrama,1561.1191,-4947.9355,6.3494,1.0,0.00000,0.00000,180.00000);
	return 1;
}

CMD:sflso(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFLS,608.7000,-1197.7000,11.0000,2.0 ,0.0000000,0.0000000,24.5000000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:sflsc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFLS,608.7000100,-1197.7000000,20.9000000,2.0 ,0.0000000,0.0000000,24.5000000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lssfo(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLSSF,631.4000,-1192.9000,12.7400,2.0,0.0000000,0.2500000,24.7490000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}


CMD:lssfc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLSSF,631.4000200,-1192.9000000,20.6000000,2.0,0.0000000,0.2500000,24.7490000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lvlso(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLVLS,1728.71448,521.44409,23.0200,2.0,0.00000,0.00000,161.02000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lvlsc(playerid,params[]){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLVLS,1728.71448,521.44409,30.90060,2.0,0.00000,0.00000,161.02000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lslvo(playerid,params[]){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLSLV,1750.77563,529.43561,22.5571,1.9,0.00000,0.00000,-19.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lslvc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLSLV,1750.77563,529.43561,30.21708,2.0,0.00000,0.00000,-19.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:sflvo(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFLV,-1381.00269,826.09863,49.11047-8.0,2.0,0.00000,0.00000,-43.67990);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:sflvc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFLV,-1381.00269,826.09863,49.11047,2.0,0.00000,0.00000,-43.67990);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lvsfo(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLVSF,-1413.58984,831.53961,49.20675-8.0,2.0,0.00000,0.00000,137.88005);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:lvsfc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaLVSF,-1413.58984,831.53961,49.20675,2.0,0.00000,0.00000,137.88005);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:sfbso(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFBS,-2677.03149,1283.38464,55.05373-8.0,2.0,0.00000,0.00000,0.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:sfbsc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaSFBS,-2677.03149,1283.38464,55.05373,2.0,0.00000,0.00000,0.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:bssfo(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaBSSF,-2686.31470,1270.84631,55.08646-8.0,2.0,0.00000,0.00000,180.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}

CMD:bssfc(playerid){
	if((gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(GranicaBSSF,-2686.31470,1270.84631,55.08646,2.0,0.00000,0.00000,180.00000);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem stra¿y granicznej");
	}
	return 1;
}



CMD:zbrojniao(playerid){
	if((gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(drzwiwojska,237.5036,1862.8875,14.4017,0.5,0,0,0);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem wojska");
	}
	return 1;
}

CMD:zbrojniac(playerid){
	if((gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)) || gGracz[playerid][AdminLvl] >= LEVEL_JUNIORADMIN){
		MoveDynamicObject(drzwiwojska,239.62109,1862.76526,14.40170,0.5,0,0,0);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem wojska");
	}
	return 1;
}
