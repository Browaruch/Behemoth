//DestroyVehicle
stock AC_DestroyVehicle(&vehicleid){
	if(!IsValidVehicle(vehicleid)) return 0;
	TrailerLock[vehicleid] = false;
	DestroyVehicle(vehicleid);
	vehicleid = INVALID_VEHICLE_ID;
	return 1;
}

#if defined _ALS_DestroyVehicle
    #undef DestroyVehicle
#else
    #define _ALS_DestroyVehicle
#endif
#define DestroyVehicle AC_DestroyVehicle