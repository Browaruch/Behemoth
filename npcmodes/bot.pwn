#include <a_npc>
#include <a_samp>

public OnRecordingPlaybackEnd()  {
     StartRecordingPlayback(1, "MassurPies");
}

public OnNPCEnterVehicle(vehicleid, seatid) {
    StartRecordingPlayback(1, "MassurPies");
}
public OnNPCExitVehicle() {
   StopRecordingPlayback();
}
