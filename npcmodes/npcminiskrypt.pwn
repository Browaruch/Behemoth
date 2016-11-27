#include <a_npc>
#include <a_samp>

public OnRecordingPlaybackEnd()  {
     StartRecordingPlayback(1, "npcminiskrypt");
}

public OnNPCEnterVehicle(vehicleid, seatid) {
    StartRecordingPlayback(1, "npcminiskrypt");
}
public OnNPCExitVehicle() {
   StopRecordingPlayback();
}
